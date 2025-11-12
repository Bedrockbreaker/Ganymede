---
aliases:
  - Neutral Density Filter
tags:
  - TODO
  - defense
  - design
  - spell
  - spell_system
  - mobility
---
# Neutral Density Filter

**Purpose**: Temporary invisibility as a risk-reward stealth or repositioning tool. Visibility balanced by sound amplification and mana burn risk.

**Notes**:
- Effect should set the NetRelevent for other teams to false (they stop getting updates about this player from the server).
- Default gameplay should include a visual overlay for nearby noises
- Spell is early-cancellable (ability secondary action), but does not dismiss when casting a different spell

**Cost**: 0 Mana (only mana burn over time)

**Constants**:
- `float` Spell.Constants.Duration = 6.0f
- `float` Spell.Constants.Magnitude = 2.0f // Noise amplification
- `float` Spell.Constants.ManaDrain = 25.0f // -15/s base mana regen = 10/s net drain
- `bool` Spell.Constants.bManaDrainIsManaBurn = true

**Delivery**:
- **Type**: Instant cast
- **Behavior**: Turns the caster invisible and hides replication updates on other teams

**Effects**:
- Invisibility:
	- `ActorHandle` Spell.Effect.Invisibility.Target
	- `float` Spell.Effect.Invisibility.Duration
- NoiseMult:
	- `ActorHandle` Spell.Effect.NoiseMult.Target
	- `float` Spell.Effect.NoiseMult.Magnitude
	- `float` Spell.Effect.NoiseMult.Duration
- NotNetRelevant
	- `ActorHandle` Spell.Effect.NotNetRelevant.Target
	- `float` Spell.Effect.NotNetRelevant.Duration
	- `TagContainer` Spell.Effect.NotNetRelevant.IgnoreTeam
- ManaDrain
	- `ActorHandle` Spell.Effect.ManaDrain.Target
	- `float` Spell.Effect.ManaDrain.AmountPerSecond
	- `float` Spell.Effect.ManaDrain.Duration
	- `bool` Spell.Effect.ManaDrain.bManaBurn

**Mappings**:
- Spell.Context.Caster -> Spell.Effect.Invisibility.Target
- Spell.Constants.Duration -> Spell.Effect.Invisibility.Duration
- Spell.Context.Caster -> Spell.Effect.NoiseMult.Target
- Spell.Constants.Magnitude -> Spell.Effect.NoiseMult.Magnitude
- Spell.Constants.Duration -> Spell.Effect.NoiseMult.Duration
- Spell.Context.Caster -> Spell.Effect.NotNetRelevant.Target
- Spell.Constants.Duration -> Spell.Effect.NotNetRelevant.Duration
- Spell.Context.CasterTeam -> AddUnique -> Spell.Effect.NotNetRelevant.IgnoreTeam
- Spell.Context.Caster -> Spell.Effect.ManaDrain.Target
- Spell.Context.ManaDrain -> Spell.Effect.ManaDrain.AmountPerSecond
- Spell.Constants.Duration -> Spell.Effect.ManaDrain.Duratoin
- Spell.Constants.bManaDrainIsManaBurn -> Spell.Effect.ManaDrain.bManaBurn
