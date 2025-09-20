// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GGameplayAbility.h"

#include "Abilities/GameplayAbilityTypes.h"
#include "AbilitySystem/GAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"

UGGameplayAbility::UGGameplayAbility()
{
	// Default to instancing per actor
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	// Default tags that prevent this ability from activating
	ActivationBlockedTags.AddTagFast(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
}

void UGGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnAvatarSet(ActorInfo, Spec);

	if (bActivateAbilityOnGranted) ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
}
