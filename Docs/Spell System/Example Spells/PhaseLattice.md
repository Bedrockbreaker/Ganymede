---
aliases:
  - Phase Lattice
tags:
  - TODO
  - design
  - spell
  - spell_system
  - defense
  - area_denial
---
# Phase Lattice

**Purpose**: Create temporary impassable and opaque walls for enemy projectiles and enemy players. Acts as a tactical zoning tool to cut off sightlines or delay flag recovery.

**Notes**:
- Wall is transparent for same-team players (no collision as well)
- The previous wall, if any, is destroyed when a new one is cast
- The shield gains the team tag of the caster (outline, target-able)
- Shield drains caster's mana while active
- If the caster runs out of mana, the shield dies
- When the shield dies (via damage, lifetime, caster out of mana, or caster dead), the shield flickers for 1 second before collapsing. The wall is invulnerable during this time.

**Cost**: 45 mana

**Constants**:
- `float` Spell.Constants.MaximumDistance = 10.0f
- `FVector` Spell.Constants.Offset = { 0.0f, 0.0f, 100.0f }
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to shield asset>
- `float` Spell.Constants.Radius = 250.0f
- `float` Spell.Constants.Health = 200.0f
- `float` Spell.Constants.Lifetime = 8.0f
- `float` Spell.Constants.ManaDrain = 10.0f
- `bool` Spell.Constants.bManaDrainIsManaBurn = false

**Delivery**:
- **Type**: Instant ray trace + actor summon (specific child class for summoning shield) // TODO: use delivery pattern from RespawnBeacon
- **Behavior**: Projects a semicircular lattice at target point, anchored to world geometry
- **Inputs**:
	- `FVector` Spell.Delivery.RayTrace.StartLocation
	- `FVector` Spell.Delivery.RayTrace.Direction
	- `float` Spell.Delivery.RayTrace.MaximumDistance
- **Outputs**:
	- `FVector` Spell.Delivery.RayTrace.EndLocation
	- `bool` Spell.Delivery.RayTrace.bHit
	- `float` Spell.Delivery.RayTrace.CalculatedDistance

**Effects**:
- Shield:
	- `SoftPtr` Spell.Effect.Shield.ShieldAsset
	- `FVector` Spell.Effect.Shield.Location
	- `float` Spell.Effect.Shield.Radius
	- `float` Spell.Effect.Shield.Health
	- `float` Spell.Effect.Shield.Lifetime
	- `float` Spell.Effect.Shield.ManaDrain
	- `bool` Spell.Effect.Shield.bManaDrainIsManaBurn
	- `Color` Spell.Effect.Shield.PrimaryColor
	- `Color` Spell.Effect.Shield.SecondaryColor

**Mappings**:
- Spell.Context.CasterLocation -> Spell.Delivery.RayTrace.StartLocation
- Spell.Context.CasterLookDirection -> Spell.Delivery.RayTrace.Direction
- Spell.Constants.MaximumDistance -> Spell.Delivery.RayTrace.MaximumDistance
- Spell.Constants.SummonedActor -> Spell.Delivery.Shield.ShieldAsset
- Spell.Delivery.RayTrace.EndLocation,
  Spell.Constants.Offset -> x + y -> Spell.Effect.Shield.Location
- Spell.Constants.Radius -> Spell.Effect.Shield.Radius
- Spell.Constants.Health -> Spell.Effect.Shield.Health
- Spell.Constants.Lifetime -> Spell.Effect.Shield.Lifetime
- Spell.Constants.ManaDrain -> Spell.Effect.Shield.ManaDrain
- Spell.Constants.bManaDrainIsManaBurn -> Spell.Effect.Shield.ManaDrainIsManaBurn
- Spell.Context.CasterPrimaryColor -> Spell.Effect.Shield.PrimaryColor
- Spell.Context.CasterSecondaryColor -> Spell.Effect.ShieldSecondaryColor
