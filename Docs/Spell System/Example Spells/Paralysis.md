---
aliases:
  - Paralysis
tags:
  - TODO
  - design
  - spell
  - spell_system
  - crowd_control
  - anti-carrier
  - defense
---
# Paralysis

**Purpose**: Trap and slow opponents in a small area; disrupts movement-based abilities. Effective anti-mobility control for defense or flag protection. Balanced by the fact this friendly fires.

**Notes**:
- ~0.1m collision radius
- High air resistance (grenade-like)

**Cost**: 40 Mana

**Constants**:
- `float` Spell.Constants.Cooldown = 12.0f
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to projectile asset>
- `float` Spell.Constants.ProjectileSpeed = 2500.0f
- `float` Spell.Constants.ProjectileLifetime = 10.0f
- `Tag` Spell.Constants.ChainedDelivery = "Spell.Delivery.LingeringAoE"
- `bool` Spell.Constants.bContinueIfCasterDied = true
- `SoftPtr` Spell.Constants.SummonedActor2 = \<soft reference to AoE asset> // TODO: better name than "SummonedActor2"
- `float` Spell.Constants.Radius = 450.0f
- `float` Spell.Constants.Lifetime = 4.0f
- `float` Spell.Constants.Magnitude = 0.5f
- `float` Spell.Constants.Duration = 3.5f

**Ability Activation Blocked Tags**:
- Spell.Cooldown.Paralysis

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.Paralysis

**Delivery**:
- **Type**: Instant Projectile
- **Behavior**: Launches a projectile which creates a new delivery upon impact
- **Inputs**:
	- `SoftPtr` Spell.Delivery.Projectile.ProjectileAsset
	- `FVector` Spell.Delivery.Projectile.LaunchLocation
	- `FVector` Spell.Delivery.Projectile.LaunchRotation
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
- **Behavior**: Creates a slowing field
- **Inputs**:
	- `SoftPtr` Spell.Delivery.LingeringAoE.Asset
	- `FVector` Spell.Delivery.LingeringAoE.Location
	- `float` Spell.Delivery.LingeringAoE.Radius
	- `float` Spell.Delivery.LingeringAoE.Lifetime
	- `float` Spell.Delivery.LingeringAoE.RadiusChangePerSecond
	- `TagContainer` Spell.Delivery.LingeringAoE.IgnoreTeam
- **Outputs**:
	- `ActorHandle` Spell.Delivery.LingeringAoE.AoEActor
	- `TargetDataHandle` Spell.Delivery.LingeringAoE.Targets
	- `int` Spell.Delivery.LingeringAoE.NumberOfTargets
	- `float` Spell.Delivery.LingeringAoE.Radius

**Effects 2**:
- MovementSpeedMult
	- `ActorHandle` Spell.Effect.MovementSpeedMult.TargetActor
	- `float` Spell.Effect.MovementSpeedMult.Magnitude
	- `float` Spell.Effect.MovementSpeedMult.Duration
- ChaosState
	- `ActorHandle` Spell.Effect.ChaosState.TargetActor
	- `float` Spell.Effect.ChaosState.Duration

**Mappings**:
- Spell.Constants.Paralysis -> Spell.Cooldown.Paralysis (SetByCaller Duration)
- Spell.Constants.SummonedActor -> Spell.Delivery.Projectile.ProjectileAsset
- Spell.Context.CasterMuzzleLocation -> Spell.Delivery.Projectile.LaunchLocation
- Spell.Context.CasterLookRotation -> Spell.Delivery.Projectile.LaunchRotation
- Spell.Constants.ProjectileSpeed -> Spell.Delivery.Projectile.ProjectileSpeed
- Spell.Constants.ProjectileLifetime -> Spell.Delivery.Projectile.ProjectileLifetime
- Spell.Constants.ChainedDelivery -> Spell.Effect.ChainDelivery.AbilityTag
- Spell.Constants.bContinueIfCasterDied -> Spell.Effect.ChainDelivery.bContinueIfCasterDied
- Spell.Constants.SummonedActor2 -> Spell.Delivery.LingeringAoE.Asset
- Spell.Delivery.Projectile.EndLocation -> Spell.Delivery.LingeringAoE.Location
- Spell.Constants.Radius -> Spell.Delivery.LingeringAoE.Radius
- Spell.Constants.Lifetime -> Spell.Delivery.LingeringAoE.Lifetime
- (default: 0.0f) -> Spell.Delivery.LingeringAoE.RadiusChangePerSecond
- (default) -> Spell.Delivery.LingeringAoE.IgnoreTeam
- Spell.Delivery.LingeringAoE.Targets -> PerActor -> Spell.Effect.MovementSpeedMult.TargetActor
- Spell.Constants.Magnitude -> Spell.Effect.MovementSpeedMult.Magnitude
- Spell.Constants.Duration -> Spell.Effect.MovementSpeedMult.Duration
- Spell.Delivery.LingeringAoETargets -> PerActor -> Spell.Effect.ChaosState.TargetActor
- Spell.Constants.Duration -> Spell.Effect.ChaosState.Duration
