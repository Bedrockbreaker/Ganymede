---
aliases:
  - Respawn Beacon
tags:
  - TODO
  - defense
  - mobility
  - design
  - spell
  - spell_system
  - team_utility
---
# Respawn Beacon

**Purpose**: Establish temporary respawn anchor near mid-field. Encourages offensive pushes and control over map territory with positional counterplay (beacon can be destroyed). Self-damage to caster adds strategic timing tension.

**Notes**:
- Beacon has team outline that is visible to all players on the map and becomes target-able.
- When cast, the last team's respawn beacon, if present, is immediately destroyed (potentially dealing damage to its caster).
- When the owning caster dies, the respawn beacon is immediately destroyed
- The beacon *forces* the team to respawn at this anchor until it's destroyed

**Cost**: 100 Mana (full mana bar, forces mana exhaustion)

**Constants**:
- `float` Spell.Constants.MaximumDistance = 100.0f
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to beacon asset>
- `bool` Spell.Constants.bGrounded = true
- `float` Spell.Constants.Lifetime = 20.0f
- `float` Spell.Constants.Health = 200.0f
- `float` Spell.Constants.Magnitude = 500.0f // Respawn radius
- `float` Spell.Constants.Damage = 35.0f

**Delivery**:
- **Type**: Object Construction
- **Behavior**: Places a beacon on the ground in a flat area. Requires a minimum distance from enemy spawns/flags.
- **Inputs**:
	- `FVector` Spell.Delivery.RayTrace.StartLocation
	- `FVector` Spell.Delivery.RayTrace.Direction
	- `float` Spell.Delivery.RayTrace.MaximumDistance
	- `FVector` Spell.Delivery.PlaceObject.Rotation
	- `float` Spell.Delivery.PlaceObject.RequiredFreeRadius
	- `bool` Spell.Delivery.PlaceObject.bRequireGroundedPlacement
	- `TagContainer` Spell.Delivery.PlaceObject.SafeTeam
	- `float` Spell.Delivery.PlaceObject.MinimumSafeDistance
	- // KAMO: `SoftPtr` Spell.Delivery.PlaceObject.Visualizer
- **Outputs**:
	- `FVector` Spell.Delivery.RayTrace.EndLocation
	- `bool` Spell.Delivery.RayTrace.bHit
	- `float` Spell.Delivery.RayTrace.CalculatedDistance

**Effects**:
- Beacon:
	- `SoftPtr` Spell.Effect.Beacon.Asset
	- `FVector` Spell.Effect.Beacon.Location
	- `float` Spell.Effect.Beacon.Lifetime
	- `float` Spell.Effect.Beacon.Health
	- `float` Spell.Effect.Beacon.RespawnRadius
	- `float` Spell.Effect.Beacon.DamageToOwner
	- `Color` Spell.Effect.Beacon.PrimaryColor
	- `Color` Spell.Effect.Beacon.SecondaryColor
	- `Color` Spell.Effect.Beacon.TertiaryColor

**Mappings**:
- Spell.Context.CasterLocation -> Spell.Delivery.RayTrace.StartLocation
- Spell.Context.CasterLookDirection -> Spell.Delivery.RayTrace.Direction
- Spell.Constants.MaximumDistance -> Spell.Delivery.RayTrace.MaximumDistance
- (default) -> Spell.Delivery.PlaceObject.Rotation
- Spell.Constants.Magnitude -> Spell.Delivery.PlaceObject.RequiredFreeRadius
- Spell.Constants.bGrounded -> Spell.Delivery.PlaceObject.RequiredGroundedPlacement
- Spell.Context.CasterTeam -> Spell.Delivery.PlaceObject.SafeTeam
- Spell.Context.MinimumBuildingDistance -> Spell.Delivery.PlaceObject.MinimumSafeDistance
- Spell.Constants.SummonedActor -> Spell.Effect.Beacon.Asset
- Spell.Delivery.RayTrace.EndLocation -> Spell.Effect.Beacon.Location
- Spell.Constants.Lifetime -> Spell.Effect.Beacon.Lifetime
- Spell.Constants.Health -> Spell.Effect.Beacon.Health
- Spell.Constants.Magnitude -> Spell.Effect.Beacon.RespawnRadius
- Spell.Constants.Damage -> Spell.Effect.Beacon.DamageToOwner
- Spell.Context.CasterPrimaryColor -> Spell.Effect.Beacon.PrimaryColor
- Spell.Context.CasterSecondaryColor -> Spell.Effect.Beacon.SecondaryColor
- Spell.Context.CasterTertiaryColor -> Spell.Effect.Beacon.TertiaryColor
