---
aliases:
  - Kinetic Bolt
tags:
  - TODO
  - design
  - programming
  - spell
  - spell_system
  - damage
  - standard_loadout
---
# Kinetic Bolt

**Purpose**: Low-cost, accurate, skill-based, baseline damage dealer.

**Notes**:
- ~0.1m collision radius
- Probably low air resistance (needs experimentation)

**Cost**: 7 mana (~14 shots with full mana)

**Constants**:
- `float` Spell.Constants.Cooldown = 0.3f
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to projectile asset>
- `float` Spell.Constants.ProjectileSpeed = 12000.0f
- `float` Spell.Constants.ProjectileLifetime = 1.2f
- `float` Spell.Constants.Damage = 20.0f

**Ability Activation Blocked Tags**:
- Spell.Cooldown.KineticBolt

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.KineticBolt

**Delivery**:
- **Type**: Instant Projectile
- **Behavior**: Fires a basic, fast-moving projectile that deals damage upon impact. Does not friendly fire.
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
- Damage:
	- `ActorHandle` Spell.Effect.Damage.TargetActor
	- `TagContainer` Spell.Effect.Damage.IgnoreTeam
	- `float` Spell.Effect.Damage.Amount
- MagicBurst:
	- `FVector` Spell.Effect.MagicBurst.Location
	- `FVector` Spell.Effect.MagicBurst.BurstDirection
	- `float` Spell.Effect.MagicBurst.BurstStrength
	- `Color` Spell.Effect.MagicBurst.Color1
	- `Color` Spell.Effect.MagicBurst.Color2

**Mappings**:
- Spell.Constants.Cooldown -> Spell.Cooldown.KineticBolt (SetByCaller Duration)
- Spell.Constants.SummonedActor -> Spell.Delivery.Projectile.ProjectileAsset
- Spell.Context.CasterMuzzleLocation -> Spell.Delivery.Projectile.LaunchLocation
- Spell.Context.CasterLookRotation -> Spell.Delivery.Projectile.LaunchRotation
- Spell.Constants.ProjectileSpeed -> Spell.Delivery.Projectile.ProjectileSpeed
- Spell.Constants.ProjectileLifetime -> Spell.Delivery.Projectile.ProjectileLifetime
- Spell.Delivery.Projectile.TargetActor -> Spell.Effect.Damage.TargetActor
- Spell.Context.CasterTeam -> AddUnique -> Spell.Effect.Damage.IgnoreTeam
- Spell.Constants.Damage -> Spell.Effect.Damage.Amount
- Spell.Delivery.Projectile.ImpactLocation -> Spell.Effect.MagicBurst.Location
- Spell.Delivery.Projectile.ImpactDirection -> Spell.Effect.MagicBurst.BurstDirection
- Spell.Delivery.Projectile.ImpactSpeed -> log(x) -> Spell.Effect.MagicBurst.BurstStrength
- Spell.Context.CasterTrailColor1 -> Spell.Effect.MagicBurst.Color1
- Spell.Context.CasterTrailColor2 -> Spell.Effect.MagicBurst.Color2
