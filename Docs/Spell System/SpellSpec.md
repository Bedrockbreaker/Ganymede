---
aliases:
  - Spell Spec
  - FGSpellSpec
tags:
  - TODO
  - spell_system
  - programming
---
# Spell Spec

`FGSpellSpec` holds all the data necessary to cast a spell:

```cpp
struct FGSpellSpec
{
public:
	// TODO: Need ability-related information here, such as costs?
	FGSpellCastingContext CastingContext;
	TSubclassOf<UGSpellDelivery> Delivery;
	TArray<TSubclassOf<UGSpellEffect>> Effects;
	TArray<FGSpellMapping> Mappings;
}
```

Spell specs are POD structs since they don't require any special methods or capabilities to function. Their sole purpose is to act as a data container.

They can be created from a [`UGSpellDefinition`](./SpellDefinition.md).