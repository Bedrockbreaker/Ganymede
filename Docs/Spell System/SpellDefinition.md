---
aliases:
  - Spell Definition
  - UGSpellDefinition
tags:
  - TODO
  - spell_system
  - design
---
# Spell Definition

`USpellDefinition` is a static data asset that can act as an "archetype" for constructing a [`FGSpellSpec`](./SpellSpec.md). These are meant to act as pre-authored spells crafted by designers, and are stored as Data Assets in the project's files.

```cpp
class USpellDefinition : public UPrimaryDataAsset
{
public:
	TSubclassOf<UGSpellDelivery> Delivery;
	TArray<TSubclassOf<UGSpellEffect>> Effects;
	TArray<FGSpellMapping> Mappings;
	
	FGSpellSpec MakeSpellSpec() const;
}
```
