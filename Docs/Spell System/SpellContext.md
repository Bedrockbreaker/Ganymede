---
aliases:
  - Spell Context
tags:
  - TODO
  - programming
  - design
  - spell_system
---
# Spell Context

`FGSpellContext` holds the data a spell needs over its lifetime: costs, delivery inputs, effect inputs, and other data that are present at ability activation. A number of values (particularly about the caster of the spell) are added to this when a spell is cast, but a designer can add constants here to be used in delivery and effects.

```cpp
struct FGSpellCastingContext
{
public:
	TArray<FGSpellData> Constants;

	// Hidden in editor
	TArray<FGSpellData> CastingContext;
	// Hidden in editor
	TArray<FGSpellData> DeliveryContext;
}
```

## Constants

Designers can add their own "constants" to a spell, to be used as inputs for the ability/delivery/effects.

Examples:
- `float` Data.Constants.MaximumDistance = 600.0f;
- `FVector` Data.Constants.Offset = FVector(100.0f, 200.0f, 300.0f);
- `bool` Data.Constants.CollectCasterTeamAsTargets = true;

## Casting Context

This array is filled with various information about the cast, such as details about the caster or environment.

- `FGSpellActorHandle` Data.Cast.Caster
- `Tag` Data.Cast.CasterTeam
- `FVector` Data.Cast.CasterLocation
- `FVector` Data.Cast.CasterLookDirection
- `float` Data.Cast.CasterRadius
- `float` Data.Cast.CasterHeight

## Delivery Context

Different delivery tasks add their own data to the spell context as well. However, deliveries can also update data over time. How often and what data it updates depends on the specific delivery used. Whenever a delivery adds/updates the spell context, all spell effects are triggered immediately afterward.

Examples:
- `FGSpellActorHandle` Data.Delivery.Targets
- `float` Data.Delivery.SphereRadius
- `float` Data.Delivery.SecondsActive
- `FVector` Data.Delivery.Location
- `float` Data.Delivery.CentimetersTravelled

## Effect Context

Effects don't add any data to the spell context. However, [Spell Mappings](./SpellMapping.md) can be used to route and transform data over the lifetime of a spell, to create dynamic values each effect should use.