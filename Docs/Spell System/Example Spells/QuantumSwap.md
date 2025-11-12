---
aliases:
  - Quantum Swap
tags:
  - TODO
  - design
  - mobility
  - spell
  - spell_system
  - team_utility
---
# Quantum Swap

**Purpose**: Swap locations/velocities for tactical misdirection to enable quick retreats, offensive dives, or defensive saves of flag carriers.

**Notes**:
- Mana cost is only applied to original caster

**Cost**: 55 Mana / 80 Mana (if swapping with flag carrier)

**Constants**:
- `TagContainer` Spell.Constants.BlockedTags = { "Status.ChaosState" }
- `float` Spell.Constants.MaximumDistance = -1
- `float` Spell.Constants.Magnitude = 360.0f // Maximum cone degrees
- `float` Spell.Constants.ProjectileSpeed = 1200.0f // Maximum speed after swap; default sprint speed
- `float` Spell.Constants.ManaDrain = 25.0f // Extra mana burn

**Ability Activation Blocked Tags**:
- Status.ChaosState

**Delivery**:
- **Type**: Instant cast
- **Behavior**: Find all teammates within line-of-sight. Pick the closest, and swap positions and velocities with them. Clamp velocities to avoid suicide swaps.
- **Inputs**:
	- `TagContainer` Spell.Delivery.LOSCharacters.RequiredTags
	- `TagContainer` Spell.Delivery.LOSCharacters.BlockedTags
	- `FVector` Spell.Delivery.LOSCharacters.StartLocation
	- `FVector` Spell.Delivery.LOSCharacters.ConeDirection
	- `float` Spell.Delivery.LOSCharacters.MaximumDistance
	- `float` Spell.Delivery.LOSCharacters.MaximumConeDegrees
- **Outputs**:
	- `TargetDataHandle` Spell.Delivery.LOSCharacters.Targets
	- `int` Spell.Delivery.LOSCharacters.NumberOfTargets

**Effects**:
- QuantumSwap // Custom effect for this, since it requires very specific logic
	- `ActorHandle` Spell.Effect.QuantumSwap.FirstTarget
	- `ActorHandle` Spell.Effect.QuantumSwap.SecondTarget
	- `float` Spell.Effect.QuantumSwap.MaximumSpeed
	- `float` Spell.Effect.QuantumSwap.ExtraManaBurnIfAnyTargetIsFlagCarrier
	- `Color` Spell.Effect.QuantumSwap.Color1 // Integrated VFX effect
	- `Color` Spell.Effect.QuantumSwap.Color2

**Mappings**:
- Spell.Context.CasterTeam -> AddUnique -> Spell.Delivery.LOSCharacters.RequiredTags
- Spell.Constants.BlockedTags -> AddAllUnique -> Spell.Delivery.LOSCharacters.BlockedTags
- Spell.Context.CasterEyeLocation -> Spell.Delivery.LOSCharacters.StartLocation
- Spell.Context.CasterLookDirection -> Spell.Delivery.LOSCharacters.ConeDirection
- Spell.Constants.MaximumDistance -> Spell.Delivery.LOSCharacters.MaximumDistance
- Spell.Constants.Magnitude -> Spell.Delivery.LOSCharacters.MaximumConeDegrees
- Spell.Context.Caster -> Spell.Effect.QuantumSwap.FirstTarget
- Spell.Delivery.LOSCharacters.Targets,
  Spell.Context.CasterLocation -> PickClosestTo(CasterLocation) -> Spell.Effect.QuantumSwap.SecondTarget
- Spell.Constants.ProjectileSpeed -> Spell.Effect.QuantumSwap.MaximumSpeed
- Spell.Constants.ManaDrain -> Spell.Effect.QuantumSwap.ExtraManaBurnIfAnyTargetIsFlagCarrier
- Spell.Context.CasterTrailColor1 -> Spell.Effect.QuantumSwap.Color1
- Spell.Context.CasterTrailColor2 -> Spell.Effect.QuantumSwap.Color2
