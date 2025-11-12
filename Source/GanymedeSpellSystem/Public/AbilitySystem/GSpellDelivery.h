// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Abilities/Tasks/AbilityTask.h"

#include "GSpellDelivery.generated.h"

struct FGameplayAbilityTargetDataHandle;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FGSpellContextReadyDelegate, const FGameplayAbilityTargetDataHandle&, SpellContextHandle);

UCLASS(Abstract)
class GANYMEDESPELLSYSTEM_API UGSpellDelivery : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(
		BlueprintCallable,
		Category = "Spell System",
		meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UGSpellDelivery* StartDelivery(UGameplayAbility* OwningAbility, FName TaskInstanceName);

	UGSpellDelivery();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spell System|Mapping")
	FGameplayTagContainer ContextOutputs;

	UPROPERTY(BlueprintAssignable, Category = "Spell System|Delivery Mechanism")
	FGSpellContextReadyDelegate OnSpellContextReady;

	virtual void Activate() override;

	virtual void OnDestroy(bool bInOwnerFinished) override;

	virtual void TickTask(float DeltaSeconds) override;

protected:
	virtual CreateSpellContext() const;
};
