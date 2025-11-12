---
aliases:
  - Gravity Well
tags:
  - TODO
  - area_denial
  - crowd_control
  - design
  - spell
  - spell_system
---
# Gravity Well

**Purpose**: Deny or control an area. Strong objective-control tool. Punishes clustering and chokepoint pushes. Has clear counters (line-of-sight throw needed, limited range, friendly fire).

**Cost**: 60 Mana

**Constants**:
- `float` Spell.Constants.Cooldown = 18.0f
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to projectile asset>
- `float` Spell.Constants.ProjectileSpeed = 2500.0f
- `float` Spell.Constants.ProjectileLifetime = 3.0f
- `Tag` Spell.Constants.ChainedDelivery = "Spell.Delivery.LingeringAoE"
- `bool` Spell.Constants.bContinueIfCasterDied = true
- `SoftPtr` Spell.Constants.SummonedActor2 = \<soft reference to AoE asset>
- `float` Spell.Constants.Radius = 500.0f
- `float` Spell.Constants.Lifetime = 4.0f
- `float` Spell.Constants.RadiusChange = 100.0f
- `float` Spell.Constants.Magnitude = 200.0f // 200N
- `float` Spell.Constants.Duration = 0.5f

**Ability Activation Blocked Tags**:
- Spell.Cooldown.GravityWell

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.GravityWell

**Delivery**:
- **Type**: Instant projectile
- **Behavior**: Throws a bouncy grenade-like object. Triggers effects at lifetime expired.
- **Inputs**:
	- `SoftPtr` Spell.Delivery.Projectile.ProjectileAsset
	- `FVector` Spell.Delivery.Projectile.LaunchLocation
	- `FVector` Spell.Delivery.Projectile.LaunchDirection
	- `float` Spell.Delivery.Projectile.ProjectileSpeed
	- `float` Spell.Delivery.Projectile.ProjectileLifetime
- **Outputs**:
	- `ActorHandle` Spell.Delivery.Projectile.ProjectileActor
	- `ActorHandle` Spell.Delivery.Projectile.TargetActor
	- `ComponentHandle` Spell.Delivery.Projectile.HitComponent
	- `FVector` Spell.Delivery.Projectile.ImpactLocation
	- `FVector` Spell.Delivery.Projectile.ImpactDirection
	- `float` Spell.Delivery.Projectile.ImpactSpeed
	- `FVector` Spell.Delivery.Projectile.ImpactNormal

**Effects**:
- ChainDelivery:
	- `Tag` Spell.Effect.ChainDelivery.AbilityTag
	- `bool` Spell.Effect.ChainDelivery.bContinueIfCasterDied

**Delivery 2**:
- **Type**: Lingering AoE
- **Behavior**: Creates a strong pulling force toward the AoE's center
- **Inputs**:
	- `SoftPtr` Spell.Delivery.LingeringAoE.Asset
	- `FVector` Spell.Delivery.LingeringAoE.Location
	- `float` Spell.Delivery.LingeringAoE.Radius
	- `float` Spell.Delivery.LingeringAoE.Lifetime
	- `float` Spell.Delivery.LingeringAoE.RadiusChangePerSecond
	- `TagContainer` Spell.Delivery.LingeringAoE.IgnoreTags
- **Outputs**:
	- `ActorHandle` Spell.Delivery.LingeringAoE.AoEActor
	- `TargetDataHandle` Spell.Delivery.LingeringAoE.Targets
	- `int` Spell.Delivery.LingeringAoE.NumberOfTargets
	- `float` Spell.Delivery.LingeringAoE.Radius

**Effects 2**:
- Impulse:
	- `ActorHandle` Spell.Effect.Impulse.TargetActor
	- `FVector` Spell.Effect.Impulse.Direction
	- `float` Spell.Effect.Impulse.Amount
- AntiCapture:
	- `ActorHandle` Spell.Effect.AntiCapture.Target
	- `float` Spell.Effect.AntiCapture.Duration

**Mappings**:
- Spell.Constants.Cooldown -> Spell.Cooldown.GravityWell (SetByCaller Magnitude)
- Spell.Constants.SummonedActor -> Spell.Delivery.Projectile.ProjectileAsset
- Spell.Context.CasterMuzzle -> Spell.Delivery.Projectile.LaunchLocation
- Spell.Context.CasterLookRotation -> Spell.Delivery.Projectile.LaunchDirection
- Spell.Constants.ProjectileSpeed -> Spell.Delivery.Projectile.ProjectileSpeed
- Spell.Constants.ProjectileLifetime -> Spell.Delivery.Projectile.ProjectileLifetime
- Spell.Constants.ChainedDelivery -> Spell.Delivery.ChainDelivery.AbilityTag
- Spell.Constants.bContinueIfCasterDied -> Spell.Delivery.ChainDelivery.bContinueIfCasterDied
- Spell.Constants.SummonedActor2 -> Spell.Delivery.LingeringAoE.Asset
- Spell.Delivery.Projectile.EndLocation -> Spell.Delivery.LingeringAoE.Locaton
- Spell.Constants.Radius -> Spell.Delivery.LingeringAoE.Radius
- Spell.Constants.Lifetime -> Spell.Delivery.LingeringAoE.Lifetime
- Spell.Constants.RadiusChange -> Spell.Delivery.LingeringAoE.RadiusChangePerSecond
- (default) -> Spell.Delivery.LingeringAoe.IgnoreTeam
- Spell.Delivery.LingeringAoE.Targets -> PerActor -> Spell.Effect.Impulse.TargetActor
- Spell.Delivery.Projectile.EndLocation,
  Spell.Delivery.LingeringAoE.Targets -> EndLocation - Target.Location -> Spell.Effect.Impulse.Direction
- Spell.Delivery.Projectile.EndLocation,
  Spell.Constants.Magnitude,
  Spell.Delivery.LingeringAoE.Targets,
  Spell.Constants.Radius -> Magnitude * (1 - Distance(Target.Location, EndLocation)/Radius) ->Spell.Effect.Impulse.Amount
- Spell.Delivery.LingeringAoE.Targets -> PerActor -> Spell.Effect.AntiCapture.Target
- Spell.Constants.Duration -> Spell.Effect.AntiCapture.Duration
