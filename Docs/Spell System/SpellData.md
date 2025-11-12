---
aliases:
  - Spell Data
tags:
  - TODO
  - spell_system
  - programming
---
# Spell Data

`FGSpellData` is a wrapper around an `FGameplayTag`, with an additional associated *type* and *value*.

```cpp
enum class EGSpellDataType
{
	Actor,
	Float,
	Vector,
	Bool
	// Color?
	// What other data could I need?
};

struct FGSpellData
{
public:
	FGameplayTag Tag;
	EGSpellDataType Type;

	FGSpellActorHandle GetActorHandle() const;
	float GetFloatValue() const;
	FVector GetVectorValue() const;
	bool GetBoolValue() const;

private:
	FGSpellActorHandle ActorHandle;
	float FloatValue;
	FVector VectorValue;
	bool bBoolValue;
};
```

## What about `TVariant<>`?

Unfortunately, `TVariant<>`, which acts like a union of multiple types and could theoretically be beneficial here for saving memory costs, does not participate in Unreal's reflection system, and therefore can't be used in blueprints. There would be no way for designers to fill in the appropriate data, since they wouldn't be able to see the input field in the editor.

## `FGSpellActorHandle`?

Although `TWeakObjectPtr<AActor>` could work for the majority of spell interactions, some spells require a reference back to an actor that was not established on the local client. (i.e. client 1 adds a weak pointer to the caster of a spell, and on client 2, that weak pointer isn't valid because it's different game instance). `FGSpellActorHandle` wraps around `FGameplayAbilityTargetData` to provide a stable reference to actors across different peers.