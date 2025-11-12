---
aliases:
  - Capsule Trace
tags:
  - TODO
  - spell_system
  - programming
---
# Capsule Trace

The Capsule Trace Spell Delivery is a specific Delivery Task used in spells. It performs a capsule trace according to the inputs, and returns the outputs as [context](../SpellMapping.md).

Inputs:
- FVector StartLocation
- FVector Direction
- float MaximumDistance
- FVector EndLocation
- float CapsuleRadius
- float CapsuleHeight

Outputs:
- FVector EndLocation
- float Distance
- bool bHit