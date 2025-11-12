// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GSpellDelivery.h"

#include "AbilitySystem/GSpellContext.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

UGSpellDelivery::UGSpellDelivery()
{
	bTickingTask = false;
}

UGSpellDelivery UGSpellDelivery::SpellDelivery(
	UGameplayAbility* OwningAbility, FName TaskInstanceName, TSubclassOf<UGSpellDelivery> DeliveryMechanism)
{
	check(OwningAbility);

	T* MyObj = NewObject<T>();
	MyObj->InitTask(*OwningAbility, OwningAbility->GetGameplayTaskDefaultPriority());

	UAbilityTask::DebugRecordAbilityTaskCreatedByAbility(OwningAbility);

	MyObj->InstanceName = InstanceName;
	return MyObj;
}

UGSpellDelivery* UGSpellDelivery::StartDelivery(UGameplayAbility* OwningAbility, FName TaskInstanceName)
{
	UGSpellDelivery* DeliveryTask = NewAbilityTask<UGSpellDelivery>(OwningAbility, TaskInstanceName);

	return DeliveryTask;
}

void UGSpellDelivery::Activate()
{
	Super::Activate();
}

void UGSpellDelivery::OnDestroy(bool bInOwnerFinished)
{
	Super::OnDestroy(bInOwnerFinished);
}

void UGSpellDelivery::TickTask(float DeltaSeconds)
{
	Super::TickTask(DeltaSeconds);

	if (ShouldBroadcastAbilityTaskDelegates()) OnSpellContextReady.Broadcast(CreateSpellContext());
}

FGSpellContext UGSpellDelivery::CreateSpellContext() const
{
	return FGSpellContext();
}
