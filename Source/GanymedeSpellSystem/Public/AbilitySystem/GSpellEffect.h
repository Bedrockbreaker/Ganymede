// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameplayTagContainer.h"

#include "GSpellEffect.generated.h"

class UAbilitySystemComponent;
class UAbilityTask;
class UGameplayAbility;
class UGameplayEffect;
struct FGameplayEffectSpecHandle;
struct FGSpellContext;

UENUM(BlueprintType)
enum class ESpellEffectType : uint8
{
	GameplayEffect,
	AbilityTask,
	GameplayCue
};

UCLASS(Abstract)
class GANYMEDESPELLSYSTEM_API UGSpellEffect : public UObject
{
	GENERATED_BODY()

public:
	ESpellEffectType EffectType;

	TSubclassOf<UGameplayEffect> GameplayEffect;
	TSubclassOf<UAbilityTask>	 AbilityTask;
	FGameplayTag				 GameplayCueTag;

	TMap<FGameplayTag, float> DataTags;
	float					  Level;
	FGameplayTagContainer	  ContextInputs;

	FGameplayEffectSpecHandle MakeEffectSpec(UAbilitySystemComponent* ASC, FGSpellContext SpellContext) const;

	void ExecuteTask(UGameplayAbility* OwningAbility, FGSpellContext SpellContext) const;

	void FireGameplayCue(UAbilitySystemComponent* ASC, FGSpellContext SpellContext) const;
};
