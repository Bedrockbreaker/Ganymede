// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GSpellEffect.h"

#include "AbilitySystem/GSpellContext.h"

FGameplayEffectSpecHandle UGSpellEffect::MakeEffectSpec(UAbilitySystemComponent* ASC, FGSpellContext SpellContext) const
{
	return FGameplayEffectSpecHandle();
}

void UGSpellEffect::ExecuteTask(UGameplayAbility* OwningAbility, FGSpellContext SpellContext) const {};

void UGSpellEffect::FireGameplayCue(UAbilitySystemComponent* ASC, FGSpellContext SpellContext) const {};
