---
aliases:
 - Gravity Well2
tags:
  - TODO
---
# Gravity Well2

**Purpose**: Deny or control an area. Strong objective-control tool. Punishes clustering and chokepoint pushes. Has clear counters (line-of-sight throw needed, limited range, friendly fire).

**Cost**: 60 Mana

**Constants**:
- `Tag` Spell.Constants.BlackboardTag1 = "Spell.Calculated.bRequirementsMet"
- `TagContainer` Spell.Constants.TagsBlocked = { "Spell.Cooldown.GravityWell" }
- `SoftPtr` Spell.Constants.ProjectileAsset = \<soft reference to projectile asset>
- `float` Spell.Constants.ProjectileSpeed = 2500.0f
- `float` Spell.Constants.ProjectileLifetime = 4.0f
- `float` Spell.Constants.Health = -1.0f
- `float` Spell.Constants.ManaCost = 60.0f
- `Tag` Spell.Constants.BlackboardTag2 = "Spell.Cooldown.GravityWell"
- `float` Spell.Constants.Cooldown = 18.0f
- `bool` Spell.Constants.bRequirementsMet = true
- `Tag` Spell.Constants.BlackboardTag3 = "Spell.Delivery.Projectile.Location"
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to AoE asset>
- `float` Spell.Constants.Radius = 500.0f
- `float` Spell.Constants.Lifetime = 4.0f
- `float` Spell.Constants.RadiusChangePerSecond = 100.0f
- `float` Spell.Constants.Magnitude = 200.0f // 200N
- `bool` Spell.Constants.bForceFlagDrop = false
- `float` Spell.Constants.Duration = 0.5f
- `SoftPtr` Spell.Constants.Sound = \<soft reference to failure sound>

## PrimaryRoot

**Delivery**: Instant
- **Type**: Instant
- **Inputs**: N/A
- **Behavior**:
	- OnStart
		1. AddCallback Spell.Delivery.Success

**Effects**:
1. Spell.Delivery.Success
	1. BlackboardWriteBool
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Calculated.bRequirementsMet
		- `bool` Spell.Effect.BlackboardWrite.Bool

**Mappings**:
1. Spell.Delivery.Success
	- Spell.Context.SpellBlackboard -> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag1 -> Spell.Effect.BlackboardWrite.Tag
	- Spell.Context.CasterTags,
	  Spell.Constants.TagsBlocked -> CasterTags.HasNone(TagsBlocked) -> Spell.Effect.BlackboardWrite.Bool

**Transitions**:
1. Spell.Calculated.bRequirementsMet -> LaunchProjectile
2. (no predicate) -> Failure

## LaunchProjectile

**Delivery**: Projectile (SpellInstance)
- **Type**: Instant
- **Inputs**:
	- `SoftPtr` Spell.Delivery.Projectile.Asset
	- `FVector` Spell.Delivery.Projectile.LaunchLocation
	- `FVector` Spell.Delivery.Projectile.LaunchDirection
	- `float` Spell.Delivery.Projectile.LaunchSpeed
	- `float` Spell.Delivery.Projectile.Lifetime
	- `float` Spell.Delivery.Projectile.Health
- **Behavior**
	- OnStart
		1. AddOutput `ActorHandle` Spell.Delivery.Projectile.Actor
		2. AddCallback Spell.Delivery.Success
	- OnTick
		1. AddOutput `FVector` Spell.Delivery.Projectile.Location
		2. AddOutput `FVector` Spell.Delivery.Projectile.LookDirection
		3. AddOutput `FVector` Spell.Delivery.Projectile.Velocity
		4. AddOutput `float` Spell.Delivery.Projectile.Speed
		5. AddCallback Spell.Delivery.Tick
	- OnCollision
		1. AddOutput `ActorHandle` Spell.Delivery.Projectile.Target
		2. AddOutput `ComponentHandle` Spell.Delivery.Projectile.HitComponent
		3. AddOutput `FVector` Spell.Delivery.Projectile.ImpactLocation
		4. AddOutput `FVector` Spell.Delivery.Projectile.ImpactDirection
		5. AddOutput `float` Spell.Delivery.Projectile.ImpactSeed
		6. AddOutput `FVector` Spell.Delivery.Projectile.ImpactNormal
		7. AddOutput `int` Spell.Delivery.Projectile.NthCollision
		8. AddCallback Spell.Delivery.Projectile.Collision
	- OnLifetimeExpired
		1. AddOutput `FVector` Spell.Delivery.Projectile.Location
		2. AddOutput `FVector` Spell.Delivery.Projectile.LookDirection
		3. AddOutput `FVector` Spell.Delivery.Projectile.Velocity
		4. AddOutput `float` Spell.Delivery.Projectile.Speed
		5. AddCallback Spell.Delivery.Instance.LifetimeExpired
	- OnDestroyed
		1. AddOutput `FVector` Spell.Delivery.Projectile.Location
		2. AddOutput `FVector` Spell.Delivery.Projectile.LookDirection
		3. AddOutput `FVector` Spell.Delivery.Projectile.Velocity
		4. AddOutput `float` Spell.Delivery.Projectile.Speed
		5. AddCallback Spell.Delivery.Instance.Destroyed

**Effects**:
1. Spell.Delivery.Success
	1. BlackboardClear
		- `int` Spell.Effect.BlackboardClear.Level
		- `Tag` Spell.Effect.BlackboardClear.Tag // Spell.Calculated.bRequirementsMet
	2. ManaBurn
		- `ActorHandle` Spell.Effect.ManaBurn.Target
		- `float` Spell.Effect.ManaBurn.Magnitude
	3. ApplyCooldown
		- `ActorHandle` Spell.Effect.ApplyCooldown.Target
		- `Tag` Spell.Effect.ApplyCooldown.Tag
		- `float` Spell.Effect.ApplyCooldown.Duration
2. Spell.Delivery.Projectile.LifetimeExpired
	1. BlackboardWriteBool
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Calculated.bRequirementsMet
		- `bool` Spell.Effect.BlackboardWrite.Bool
	2. BlackboardWriteVector
		- `int` Spell.Effect.BlackboardWrite.Level
		- `Tag` Spell.Effect.BlackboardWrite.Tag // Spell.Delivery.Projectile.Location
		- `FVector` Spell.Effect.BlackboardWrite.Vector

**Mappings**:
- Spell.Constants.ProjectileAsset -> Spell.Delivery.Projectile.Asset
- Spell.Context.CasterLocation -> Spell.Delivery.Projectile.LaunchLocation
- Spell.Context.CasterLookDirection -> Spell.Delivery.Projectile.LaunchDirection
- Spell.Constants.ProjectileSpeed -> Spell.Delivery.Projectile.LaunchSpeed
- Spell.Constants.ProjectileLifetime -> Spell.Delivery.Projectile.Lifetime
- Spell.Constants.Health -> Spell.Delivery.Projectile.Health
1. Spell.Delivery.Success
	- Spell.Context.SpellBlackboard -> Spell.Effect.BlackboardClear.Level
	- Spell.Constants.BlackboardTag1 -> Spell.Effect.BlackboardClear.Tag
	- Spell.Context.Caster -> Spell.Effect.ManaBurn.Target
	- Spell.Constants.ManaCost -> Spell.Effect.ManaBurn.Magnitude
	- Spell.Context.Caster -> Spell.Effect.ApplyCooldown.Target
	- Spell.Constants.BlackboardTag2 -> Spell.Effect.ApplyCooldown.Tag
	- Spell.Constants.Cooldown -> Spell.Effect.ApplyCooldown.Duration
2. Spell.Delivery.Projectile.LifetimeExpired
	- Spell.Context.SpellBlackboard -\[0]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag1 -\[0]> Spell.Effect.BlackboardWrite.Tag
	- Spell.Constants.bRequirementsMet -\[0]> Spell.Effect.BlackboardWrite.Bool
	- Spell.Context.SpellBlackboard -\[1]> Spell.Effect.BlackboardWrite.Level
	- Spell.Constants.BlackboardTag3 -\[1]> Spell.Effect.BlackboardWrite.Tag
	- Spell.Delivery.Projectile.Location -\[1]> Spell.Effect.BlackboardWrite.Vector

**Transitions**:
1. Spell.Calculated.bRequirementsMet -> CreateAoE

## CreateAoE

**Delivery**: LingeringAoE (SpellInstance)
- **Type**: Instant
- **Inputs**:
	- `SoftPtr` Spell.Delivery.LingeringAoE.Asset
	- `FVector` Spell.Delivery.LingeringAoE.Location
	- `float` Spell.Delivery.LingeringAoE.Radius
	- `float` Spell.Delivery.LingeringAoE.Lifetime
	- `float` Spell.Delivery.LingeringAoE.RadiusChangePerSecond
	- `TagContainer` Spell.Delivery.LingeringAoE.RequiredTags
	- `TagContainer` Spell.Delivery.LingeringAoE.IgnoreTags
- **Behavior**:
	- OnStart
		1. AddOutput `ActorHandle` Spell.Delivery.LingeringAoE.Actor
		2. AddOutput `TargetData` Spell.Delivery.LingeringAoE.Targets
		3. AddOutput `int` Spell.Delivery.LingeringAoE.NumberOfTargets
		4. AddCallback Spell.Delivery.Success
	- OnTick
		1. AddOutput `TargetData` Spell.Delivery.LingeringAoE.Targets
		2. AddOutput `int` Spell.Delivery.LingeringAoE.NumberOfTargets
		3. AddOutput `float` Spell.Delivery.LingeringAoE.Radius
		4. AddCallback Spell.Delivery.Instance.Tick
	- OnLifetimeExpired
		1. AddOutput `TargetData` Spell.Delivery.LingeringAoE.Targets
		2. AddOutput `int` Spell.Delivery.LingeringAoE.NumberOfTargets
		3. AddOutput `float` Spell.Delivery.LingeringAoE.Radius
		4. AddCallback Spell.Delivery.Instance.LifetimeExpired

**Effects**:
1. Spell.Delivery.Instance.Tick
	1. AddImpulse
		- `ActorHandle` Spell.Effect.AddImpulse.Target
		- `FVector` Spell.Effect.AddImpulse.Direction
		- `float` Spell.Effect.AddImpulse.Magnitude
	2. AntiCapture
		- `ActorHandle` Spell.Effect.AntiCapture.Target
		- `bool` Spell.Effect.AntiCapture.bForceFlagDrop
		- `float` Spell.Effect.AntiCapture.Duration

**Mappings**:
- Spell.Constants.SummonedActor -> Spell.Delivery.LingeringAoE.Asset
- Spell.Delivery.Projectile.Location -> Spell.Delivery.LingeringAoE.Location
- Spell.Constants.Radius -> Spell.Delivery.LingeringAoE.Radius
- Spell.Constants.Lifetime -> Spell.Delivery.LingeringAoE.Lifetime
- Spell.Constants.RadiusChangePerSecond -> Spell.Delivery.LingeringAoE.RadiusChangePerSecond
- (default) -> Spell.Delivery.LingeringAoE.RequiredTags
- (default) -> Spell.Delivery.LingeringAoE.IgnoreTags
1. Spell.Delivery.Instance.Tick
	- Spell.Delivery.LingeringAoE.Targets -> PerActor -> Spell.Effect.AddImpulse.Target
	- Spell.Delivery.Projectile.Location,
	  Spell.Delivery.LingeringAoE.Targets -> ProjectileLocation - Target.Location -> Spell.Effect.AddImpulse.Direction
	- Spell.Delivery.Projectile.Location,
	  Spell.Constants.Magnitude,
	  Spell.Delivery.LingeringAoE.Targets,
	  Spell.Delivery.LingeringAoE.Radius -> Magnitude \* (1 - Distance(Target.Location, ProjectileLocation) / Radius) -> Spell.Effect.AddImpulse.Magnitude
	- Spell.Delivery.LingeringAoE.Targets -> PerActor -> Spell.Effect.AntiCapture.Target
	- Spell.Constants.bForceFlagDrop -> Spell.Effect.AntiCapture.bForceFlagDrop
	- Spell.Constants.Duration -> Spell.Effect.AntiCapture.Duration

## Failure

**Delivery**: Instant
- **Type**: Instant
- **Inputs**: N/A
- **Behavior**
	- OnStart
		1. AddCallback Spell.Delivery.Success

**Effects**:
1. Spell.Delivery.Success
	1. PlayClientSound
		- `SoftPtr` Spell.Effect.PlayClientSound.Asset

**Mappings**:
1. Spell.Delivery.Success
	- Spell.Constants.Sound -> Spell.Effect.PlayClientSound.Asset

**Transitions**: N/A
