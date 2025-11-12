---
aliases:
  - Blink
tags:
  - TODO
  - design
  - spell_system
  - spell
  - mobility
---
# Blink

**Purpose**: Strategic movement option to instantly move forward.

**Cost**: 35 Mana

**Constants**:
- `float` Spell.Constants.Cooldown = 18.0f
- `float` Spell.Constants.MaximumDistance = 600.0f
- `bool` Spell.Constants.bSweep = true
- `FVector` Spell.Constants.Offset = { 0.0f, 0.0f, 0.0f }

**Ability Activation Blocked Tags**:
- Status.ChaosState
- Spell.Cooldown.Blink

**Ability Gameplay Effects Applied to Source Tags**:
- Spell.Cooldown.Blink

**Delivery**:
- **Type**: Instant capsule trace
- **Behavior**: Capsule-traces the caster forward (look vector) and teleports them to the farthest location that doesn't intersect geometry or within some maximum distance.
- **Inputs**:
	- `FVector` Spell.Delivery.CapsuleTrace.StartLocation
	- `FVector` Spell.Delivery.CapsuleTrace.Direction
	- `float` Spell.Delivery.CapsuleTrace.MaximumDistance
	- `float` Spell.Delivery.CapsuleTrace.Radius
	- `float` Spell.Delivery.CapsuleTrace.Height
- **Outputs**:
	- `FVector` Spell.Delivery.CapsuleTrace.EndLocation
	- `bool` Spell.Delivery.CapsuleTrace.bHit
	- `float` Spell.Delivery.CapsuleTrace.CalculatedDistance

**Effects**:
- TeleportActor:
	- `ActorHandle` Spell.Effect.TeleportActor.Target
	- `FVector` Spell.Effect.TeleportActor.TeleportLocation
	- `FVector` Spell.Effect.TeleportActor.LookRotation
	- `bool` Spell.Effect.TeleportActor.bSweep
	- // KAMO: Spell.Effect.TeleportActor.bSnapToGround
- SetVelocity:
	- `ActorHandle` Spell.Effect.SetVelocity.Target
	- `FVector` Spell.Effect.SetVelocity.Velocity
- MagicParticlesLine:
	- `FVector` Spell.Effect.MagicParticlesLine.StartLocation
	- `FVector` Spell.Effect.MagicParticlesLine.EndLocation
	- `Color` Spell.Effect.MagicParticlesLine.Color1
	- `Color` Spell.Effect.MagicParticlesLine.Color2

**Mappings**:
- Spell.Constants.Cooldown -> Spell.Cooldown.Blink (SetByCaller Magnitude)
- Spell.Context.CasterLocation -> Spell.Delivery.CapsuleTrace.StartLocation
- Spell.Context.CasterLookRotation -> Spell.Delivery.CapsuleTrace.Direction
- Spell.Constants.MaximumDistance -> Spell.Delivery.CapsuleTrace.MaximumDistance
- Spell.Context.CasterRadius -> Spell.Delivery.CapsuleTrace.Radius
- Spell.Context.CasterHeight -> Spell.Delivery.CapsuleTrace.Height
- Spell.Context.Caster -> Spell.Effect.TeleportActor.Target
- Spell.Delivery.CapsuleTrace.EndLocation -> Spell.Effect.TeleportActor.TeleportLocation
- Spell.Context.CasterLookRotation -> Spell.Effect.TeleportActor.LookRotation
- Spell.Constants.bSweep -> Spell.Effect.TeleportActor.bSweep
- Spell.Context.CasterLocation -> Spell.Effect.SetVelocity.Target
- Spell.Constants.Offset -> Spell.Effect.SetVelocity.Velocity
- Spell.Context.CasterLocation -> Spell.Effect.MagicParticlesLine.StartLocation
- Spell.Delivery.CapsuleTrace.EndLocation -> Spell.Effect.MagicParticlesLine.EndLocation
- Spell.Context.CasterTrailColor1 -> Spell.Effect.MagicParticlesLine.Color1
- Spell.Context.CasterTrailColor2 -> Spell.Effect.MagicParticlesLine.Color2
