// Copyright © Bedrockbreaker 2025. MIT License

#include "GanymedeFramework/GCombatPlayerState.h"

#include "AbilitySystem/GAbilitySystemComponent.h"
#include "AbilitySystem/GAttributeSet.h"
#include "AbilitySystemComponent.h"

AGCombatPlayerState::AGCombatPlayerState()
{
	SetNetUpdateFrequency(60.0f);

	AbilitySystemComponent = CreateDefaultSubobject<UGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UGAttributeSet>(TEXT("AttributeSet"));
}
