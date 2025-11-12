// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GSpellAbility.h"
#include "AbilitySystem/GSpellDelivery.h"

UGSpellAbility::UGSpellAbility()
{
	// Override to instancing per execution
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerExecution;
}
