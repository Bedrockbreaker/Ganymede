---
aliases:
  - Reverberation
tags:
  - TODO
  - crowd_control
  - defense
  - spell
  - design
  - spell_system
  - team_utility
---
# Reverberation

**Purpose**: Information reveal and sustained effect denial. Combines recon and counterplay against long-lasting effects (like AoE zones).

**Cost**: 30 Mana

**Constants**:
- `float` Spell.Constants.Cooldown = 7.0f
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to projectile asset>
- `float` Spell.Constants.ProjectileSpeed = 2500.0f
- `float` Spell.Constants.ProjectileLifetime = 10.0f
- `Tag` Spell.Constants.ChainedDelivery = "Spell.Delivery.SphereTrigger"
- `bool` Spell.Constants.bContinueIfCasterDied = false
- `float` Spell.Constants.Radius = 1000.0f
- `float` Spell.Constants.Duration = 4.0f
- `float` Spell.Constants.Magnitude = 0.5f

**Ability Activation Blocked Tags**:
- Spell.Cooldown.Reverberation

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.Reverberation

**Delivery**:
- **Type**: Instant Projectile
- **Behavior**: Throws a projectile that activates on first impact
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
- **Type**: Sphere Trigger
- **Behavior**: Marks all enemies within radius as visible through walls, and suppresses active deliveries (i.e. AoE effects).
- **Inputs**:
	- `float` Spell.Delivery.SphereTrigger.Radius
	- `TagContainer` Spell.Delivery.SphereTrigger.IgnoreTeam
	- // KAMO: Spell.Delivery.SphereTrigger.bRequiresLineOfSight
- **Outputs**:
	- `TargetDataHandle` Spell.Delivery.SphereTrigger.Targets
	- `int` Spell.Delivery.SphereTrigger.NumberOfTargets

**Effects 2**:
- Mark:
	- `ActorHandle` Spell.Effect.Mark.Target
	- `float` Spell.Effect.AntiCapture.Duration
- SuppressDelivery:
	- `ActorHandle` Spell.Effect.SuppressDelivery.TargetActor
	- `float` Spell.Effect.SuppressDelivery.Duration
- SphereShockwave:
	- `FVector` Spell.Effect.SphereShockwave.Location
	- `float` Spell.Effect.SphereShockwave.Radius
	- `Color` Spell.Effect.SphereShockwave.Color

**Mappings**:
- Spell.Constants.Cooldown -> Spell.Cooldown.Reverberation (SetByCaller Magnitude)
- Spell.Constants.SummonedActor -> Spell.Delivery.Projectile.ProjectileAsset
- Spell.Context.CasterMuzzle -> Spell.Delivery.Projectile.LaunchLocation
- Spell.Context.CasterLookRotation -> Spell.Delivery.Projectile.LaunchDirection
- Spell.Constants.ProjectileSpeed -> Spell.Delivery.Projectile.ProjectileSpeed
- Spell.Constants.ProjectileLifetime -> Spell.Delivery.Projectile.ProjectileLifetime
- Spell.Constants.ChainedDelivery -> Spell.Effect.ChainDelivery.AbilityTag
- Spell.Constants.bContinueIfCasterDied -> Spell.Effect.ChainDelivery.bContinueIfCasterDied
- Spell.Constants.Radius -> Spell.Delivery.SphereTrigger
- Spell.Context.CasterTeam -> AddUnique -> Spell.Delivery.IgnoreTeam
- Spell.Delivery.SphereTrigger.Targets -> PerActor -> Spell.Effect.Mark.Target
- Spell.Constants.Duration -> Spell.Effect.Mark.Duration
- Spell.Delivery.SphereTrigger.Targets -> Filter for Spell Instances -> Spell.Effect.SuppressDelivery.TargetActor
- Spell.Constants.Magnitude -> Spell.Effect.SuppressDelivery.Duration
- Spell.Delivery.Projectile.EndLocation -> Spell.Effect.SphereShockwave.Location
- Spell.Constants.Radius -> Spell.Effect.SphereShockwave.Radius
- Spell.Context.CasterSecondaryColor -> Spell.Effect.SphereShockwave.Color
