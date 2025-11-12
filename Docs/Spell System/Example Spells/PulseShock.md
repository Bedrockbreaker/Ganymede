---
aliases:
  - Pulse Shock
tags:
  - TODO
  - damage
  - design
  - spell
  - spell_system
  - standard_loadout
  - area_denial
---
# Pulse Shock

**Purpose**: Area denial & disorientation. Useful as a quick mid-range zoning tool or to disrupt pushes/flag runs.

**Cost**: 20 mana

**Constants**:
- `float` Spell.Constants.Cooldown = 6.0f
- `float` Spell.Constants.MaximumDistance = 1000.0f
- `float` Spell.Constants.Radius = 600.0f
- `float` Spell.Constants.Damage = 20.0f
- `float` Spell.Constants.Impulse = 600.0f
- `float` Spell.Constants.CameraShakeMagnitude = 10.0f // TODO: needs actually tested number
- `float` Spell.Constants.Duration = 0.8f

**Ability Activation Blocked Tags**:
- Spell.Cooldown.PulseShock

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.PulseShock

**Delivery**:
- **Type**: Instant ray trace + Instant sphere trigger
- **Behavior**: Traces an impact point a short distance away from the caster and knocks back all enemy players from the center of the impact point.
- **Inputs**:
	- `FVector` Spell.Delivery.RayTrace.StartLocation
	- `FVector` Spell.Delivery.RayTrace.Direction
	- `float` Spell.Delivery.RayTrace.MaximumDistance
	- `float` Spell.Delivery.SphereTrigger.Radius
	- `TagContainer` Spell.Delivery.SphereTrigger.IgnoreTeam
	- // KAMO: Spell.Delivery.SphereTrigger.bRequiresLineOfSight
- **Outputs**:
	- `FVector` Spell.Delivery.RayTrace.EndLocation
	- `bool` Spell.Delivery.RayTrace.bHit
	- `float` Spell.Delivery.RayTrace.CalculatedDistance
	- `TargetDataHandle` Spell.Delivery.SphereTrigger.Targets
	- `int` Spell.Delivery.SphereTrigger.NumberOfTargets

**Effects**:
- Impulse:
	- `ActorHandle` Spell.Effect.Impulse.TargetActor
	- `FVector` Spell.Effect.Impulse.Direction
	- `float` Spell.Effect.Impulse.Amount
- Damage:
	- `ActorHandle` Spell.Effect.Damage.TargetActor
	- `TagContainer` Spell.Effect.Damage.IgnoreTeam
	- `float` Spell.Effect.Damage.Amount
- CameraShake:
	- `ActorHandle` Spell.Effect.CameraShake.TargetCharacter
	- `float` Spell.Effect.CameraShake.Magnitude
	- `float` Spell.Effect.CameraShake.Duration
- SphereShockwave:
	- `FVector` Spell.Effect.SphereShockwave.Location
	- `float` Spell.Effect.SphereShockwave.Radius
	- `Color` Spell.Effect.SphereShockwave.Color

**Mappings**:
- Spell.Constants.Cooldown -> Spell.Cooldown.PulseShock (SetByCaller Duration)
- Spell.Context.CasterLocation -> Spell.Delivery.RayTrace.StartLocation
- Spell.Context.CasterLookDirection -> Spell.Delivery.RayTrace.Direction
- Spell.Constants.MaximumDistance -> Spell.Delivery.RayTrace.MaximumDistance
- Spell.Constants.Radius -> Spell.Delivery.SphereTrigger.Radius
- Spell.Context.CasterTeam -> AddUnique -> Spell.Delivery.SphereTrigger.IgnoreTeam
- Spell.Delivery.SphereTrigger.Targets -> PerActor -> Spell.Effect.Impulse.TargetActor
- Spell.Delivery.RayTrace.EndLocation -> (Target.location - x).Normalized -> Spell.Effect.Impulse.Direction
- Spell.Constants.Impulse -> Spell.Effect.Impulse.Amount
- Spell.Delivery.SphereTrigger.Targets -> PerActor -> Spell.Effect.Damage.TargetActor
- (default) -> Spell.Effect.Damage.IgnoreTeam
- Spell.Constants.Damage -> Spell.Effect.Damage.Amount
- Spell.Delivery.SphereTrigger.Targets -> PerActor -> Spell.Effect.CameraShake.TargetCharacter
- Spell.Constants.CameraShakeMagnitude -> Spell.Effect.CameraShake.Magnitude
- Spell.Constants.Duration -> Spell.Effect.CameraShake.Duration
- Spell.Delivery.RayTrace.EndLocation -> Spell.Effect.SphereShockwave.Location
- Spell.Constants.Radius -> Spell.Effect.SphereShockwave.Radius
- Spell.Context.CasterSecondaryColor -> Spell.Effect.SphereShockwave.Color