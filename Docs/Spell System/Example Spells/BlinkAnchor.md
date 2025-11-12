---
aliases:
  - Blink Anchor
tags:
  - TODO
  - design
  - mobility
  - spell
  - spell_system
  - team_utility
---
# Blink Anchor

**Purpose**: Controlled repositioning and flag-running tool. Powerful for flag steals or feints, but mana-intensive and punishable if chased.

**Notes**:
- When cast, if the caster has another anchor object anywhere in the world and is outside of its maximum distance, the spell fails harmlessly.
- When the caster dies, the anchor object is immediately destroyed.
- The anchor can be remotely destroyed by the caster through using the spell's secondary ability.
- After teleporting back to an anchor, the anchor is immediately destroyed.

**Cost**: 40 Mana (initial) / X Mana (on recall)

**Constants**:
- `SoftPtr` Spell.Constants.SummonedActor = \<soft reference to anchor asset>
- `float` Spell.Constants.Lifetime = -1.0f
- `float` Spell.Constants.Health = 100.0f
- `float` Spell.Constants.MaximumDistance = 4000.0f
- `float` Spell.Constants.ManaDrain = .0333f // Recall cost per cm, ~= 3.33 Mana/m
- `bool` Spell.Constants.bSweep = false
- `FVector` Spell.Constants.Offset = { 0.0f, 0.0f, 0.0f }

**Ability Activation Blocked Tags**:
- Status.ChaosState

**Delivery** (if no anchor exists):
- **Type**: Instant cast (custom child class for handling statefulness)
- **Behavior**: Places an anchor at the caster's position (with the caster's rotation).

**Effects** (if no anchor exists):
- Anchor:
	- `SoftPtr` Spell.Effect.Anchor.Asset
	- `FVector` Spell.Effect.Anchor.Location
	- `FVector` Spell.Effect.Anchor.LookRotation
	- `float` Spell.Effect.Anchor.Lifetime
	- `float` Spell.Effect.Anchor.Health

**Delivery 2** (If anchor exists):
- **Type**: Instant cast (custom child class for handling statefulness)
- **Behavior**: Allows teleporting back to the anchor if within a maximum distance for an additional cost.
- **Inputs**:
	- `float` Spell.Delivery.Anchor.MaximumDistance
- **Outputs**:
	- `FVector` Spell.Delivery.Anchor.Location
	- `FVector` Spell.Delivery.Anchor.LookRotation
	- `FVector` Spell.Delivery.Anchor.VectorBetween
	- `float` Spell.Delivery.Anchor.CalculatedDistance

**Effects 2** (if anchor exists):
- TeleportActor:
	- `ActorHandle` Spell.Effect.TeleportActor.Target
	- `FVector` Spell.Effect.TeleportActor.TeleportLocation
	- `FVector` Spell.Effect.TeleportActor.LookRotation
	- `bool` Spell.Effect.TeleportActor.bSweep
	- // KAMO: Spell.Effect.TeleportActor.bSnapToGround
- SetVelocity:
	- `ActorHandle` Spell.Effect.SetVelocity.Target
	- `FVector` Spell.Effect.SetVelocity.Velocity
- ManaBurn:
	- `ActorHandle` Spell.Effect.ManaBurn.Target
	- `float` Spell.Effect.ManaBurn.Magnitude
- MagicParticlesLine:
	- `FVector` Spell.Effect.MagicParticlesLine.StartLocation
	- `FVector` Spell.Effect.MagicParticlesLine.EndLocation
	- `Color` Spell.Effect.MagicParticlesLine.Color1
	- `Color` Spell.Effect.MagicParticlesLine.Color2

**Mappings**:
- Spell.Constants.SummonedActor -> Spell.Effect.Anchor.Asset
- Spell.Context.CasterLocation -> Spell.Effect.Anchor.Location
- Spell.Context.CasterLookDirection -> Spell.Effect.Anchor.LookRotation
- Spell.Constants.Lifetime -> Spell.Effect.Anchor.Lifetime
- Spell.Constants.Health -> Spell.Effect.Anchor.Health
- Spell.Constants.MaximumDistance -> Spell.Delivery.Anchor.MaximumDistance
- Spell.Context.Caster -> Spell.Effect.TeleportActor.Target
- Spell.Delivery.Anchor.Location -> Spell.Effect.TeleportActor.TeleportLocation
- Spell.Delivery.Anchor.LookRotation -> Spell.Effect.TeleportActor.LookRotation
- Spell.Constants.bSweep -> Spell.Effect.TeleportActor.bSweep
- Spell.Context.Caster -> Spell.Effect.SetVelocity.Target
- Spell.Constants.Offset -> Spell.Effect.SetVelocity.Velocity
- Spell.Context.Caster -> Spell.Effect.ManaBurn.Target
- Spell.Constants.ManaDrain,
  Spell.Delivery.Anchor.CalculatedDistance -> x \* y -> Spell.Effect.ManaBurn.Magnitude
- Spell.Context.CasterLocation -> Spell.Effect.MagicParticlesLine.StartLocation
- Spell.Delivery.Anchor.Location -> Spell.Effect.MagicParticlesLine.EndLocation
- Spell.Context.CasterTrailColor1 -> Spell.Effect.MagicParticlesLine.Color1
- Spell.Context.CasterTrailColor2 -> Spell.Effect.MagicParticlesLine.Color2
