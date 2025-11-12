---
aliases:
  - Spell Ability
  - UGSpellAbility
tags:
  - TODO
  - programming
  - spell_system
---
# Spell Ability

`UGSpellAbility` is the generic, catch-all ability used for casting spells. It mostly acts as just a wrapper for a [`UGSpellSpec`](./SpellSpec.md). When a persistent spell is spawned, it will transfer ownership of the spell spec to a [`AGSpellInstance`](./SpellInstance.md), allowing this ability to end.

```cpp
class UGSpellAbility : UGGameplayAbility
{
public:
	UGSpellSpec
}
```

This class specifically inherits from `UGGameplayAbility`, which is a subclass of `UGameplayAbility`. This provides some sensible defaults for Ganymede, such as the `InstancedPerActor` instancing policy, `bActivateAbilityOnGranted` to allow forcefully activating abilities on actors, and default `ActivationBlockedTags`.