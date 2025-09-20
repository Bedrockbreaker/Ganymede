// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GAbilitySystemComponent.h"

UGAbilitySystemComponent::UGAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);
}
