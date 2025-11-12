// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GSpellMapping.h"
#include "Engine/DataTable.h"

#include "GSpellSpec.generated.h"

class UGSpellDelivery;
class UGSpellEffect;

/** Definition of a spell, including its data, delivery mechanism, and effects. */
USTRUCT(BlueprintType)
struct GANYMEDESPELLSYSTEM_API FGSpellSpec
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Spell Data")
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Spell Data")
	FGameplayTagContainer GameplayCueTags;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Spell Data")
	TSubclassOf<UGSpellDelivery> DeliveryMechanism;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Spell Data")
	TArray<TSubclassOf<UGSpellEffect>> SpellEffects;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Spell Data")
	TArray<FGSpellMapping> ContextMappings;
};
