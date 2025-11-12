---
aliases:
  - Spell Delivery
  - UGSpellDelivery
  - delivery mechanism
tags:
  - TODO
  - programming
  - spell_system
  - design
---
# Spell Delivery

`UGSpellDelivery` is the representation of how the spell first manifests into the world, including how it collects data and targets. These are meant to be modular and hot-swappable, allowing any [`UGSpellEffect`](./SpellEffect.md) to use any delivery mechanism.

Spell deliveries can either be one-shot (i.e. raycast), or persistent (i.e. spawns a projectile). Persistent deliveries signal to their owning [UGSpellAbility](./SpellAbility) that an [`ASpellInstance`](./SpellInstance.md) has been created and that it should end (along with this delivery task). Deliveries are responsible for creating spell instances.

```cpp
class UGSpellDelivery : UAbilityTask
{
public:
	// Called from abilities using TSubclassOf<UGSpellDelivery>.GetDefaultObject()->CreateSpellDelivery(this, ...);
	virtual UGSpellDelivery CreateSpellDelivery(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FGSpellCastingContext& CastingContext);

	virtual FGSpellDeliveryContext CreateSpellContext() const;
}
```

## Interaction with Spell Mappings



## Non-static Factory Pattern

Ability tasks normally use a static factory function for creating themselves: `UMyAbilityTask::MyAbilityTask(...)`, which returns a task of that exact type. This isn't usually an issue, since abilities typically know what tasks they're creating.

However, this becomes an issue when trying to make a single, generic Spell Ability that doesn't care about what kind of spell it's holding -- any task could be stored within the [`FGSpellSpec`](./SpellSpec.md)! To get around this issue, the Class Default Object of the base `UGSpellDelivery` is retrieved to get a valid instance to a class of the correct child type, which can then be used to call the overridden `CreateSpellDelivery()` method.

```cpp
// In UGSpellDelivery:
UGSpellDelivery Delivery = SpellDelivery.GetDefaultObject()->CreateSpellDelivery(
	this,
	NAME_None,
	CastingContext);
```

Child classes of `UGSpellDelivery` can override this method to perform their own setup. Care should be taken to not mutate the current instance state, since that affects the CDO.

```cpp
// In UGSD_CapsuleTrace:
public override UGSpellDelivery UGSD_CapsuleTrace::CreateSpellDelivery(
	UGameplayAbility* OwningAbility,
	FName TaskInstanceName,
	const FGSpellCastingContext& CastingContext)
{
	UGSD_CapsuleTrace* Delivery = NewAbilityTask<UGSD_CapsuleTrace>(
		OwningAbility,
		TaskInstanceName);
	// perform setup...
	return Delivery;
}
```
