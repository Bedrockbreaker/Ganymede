// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GGameplayAbility.h"

#include "GA_GSprint.generated.h"

UCLASS()
class COMBATSYSTEM_API UGA_GSprint : public UGGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GSprint();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle	 Handle,
		const FGameplayAbilityActorInfo*	 ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData*			 TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle	 Handle,
		const FGameplayAbilityActorInfo*	 ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool								 bReplicateEndAbility,
		bool								 bWasCancelled) override;

private:
	bool bEndAbility = false;

	FTimerHandle PredictSprintTimerHandle;

	UFUNCTION()
	virtual void WaitNetSync();

	UFUNCTION()
	virtual void PredictSprint();
};
