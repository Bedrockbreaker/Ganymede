// Copyright © Bedrockbreaker 2025. MIT License

#include "Abilities/GA_GSprint.h"
#include "Abilities/Tasks/AbilityTask_NetworkSyncPoint.h"
#include "CombatFramework/GCharacterMovementComponent.h"
#include "TimerManager.h"

UGA_GSprint::UGA_GSprint()
{
	SetAssetTags(FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("Ability.Sprint"))));
	ActivationOwnedTags.AddTagFast(FGameplayTag::RequestGameplayTag(FName("Ability.Sprint")));
	ActivationOwnedTags.AddTagFast(FGameplayTag::RequestGameplayTag(FName("State.Sprinting")));
}

void UGA_GSprint::ActivateAbility(
	const FGameplayAbilitySpecHandle	 Handle,
	const FGameplayAbilityActorInfo*	 ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData*			 TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UE_LOG(LogTemp, Warning, TEXT("Sprint Activated."));

	UGCharacterMovementComponent* GCharacterMovement =
		Cast<UGCharacterMovementComponent>(GetActorInfo().MovementComponent.Get());
	if (!GCharacterMovement) return;

	UWorld* World = GetWorld();
	if (!World) return;

	bEndAbility = false;
	GCharacterMovement->StartSprinting();
	WaitNetSync();
}

void UGA_GSprint::EndAbility(
	const FGameplayAbilitySpecHandle	 Handle,
	const FGameplayAbilityActorInfo*	 ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	bool								 bReplicateEndAbility,
	bool								 bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	UE_LOG(LogTemp, Warning, TEXT("Sprint Deactivated."));

	bEndAbility = true;

	UGCharacterMovementComponent* GCharacterMovement =
		Cast<UGCharacterMovementComponent>(GetActorInfo().MovementComponent.Get());
	if (!GCharacterMovement) return;

	GCharacterMovement->StopSprinting();
}

void UGA_GSprint::WaitNetSync()
{
	UAbilityTask_NetworkSyncPoint* NetSyncTask =
		UAbilityTask_NetworkSyncPoint::WaitNetSync(this, EAbilityTaskNetSyncType::OnlyServerWait);
	NetSyncTask->OnSync.AddDynamic(this, &UGA_GSprint::PredictSprint);
	NetSyncTask->ReadyForActivation();
}

void UGA_GSprint::PredictSprint()
{
	UGCharacterMovementComponent* GCharacterMovement =
		Cast<UGCharacterMovementComponent>(GetActorInfo().MovementComponent.Get());
	if (!GCharacterMovement) return;

	if (!GCharacterMovement->GetCurrentAcceleration().IsNearlyZero() && !GCharacterMovement->IsFalling())
	{
		bool bSuccess = CommitAbilityCost(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo);
		if (!bSuccess)
		{
			bEndAbility = true;
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, false);
			return;
		}
	}

	if (bEndAbility) return;

	UWorld* World = GetWorld();
	if (!World) return;

	World->GetTimerManager().SetTimer(PredictSprintTimerHandle, this, &UGA_GSprint::WaitNetSync, 0.05f, false);
}
