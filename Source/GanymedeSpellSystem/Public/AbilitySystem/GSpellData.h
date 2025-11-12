// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "GSpellData.generated.h"

class UGSpellDelivery;
class UGSpellEffect;
struct FGSpellMapping;
struct FGSpellSpec;

/** Primary data asset for a spell. Primarily used to create an FGSpellSpec. */
UCLASS(BlueprintType)
class UGSpellData : public UPrimaryDataAsset
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

	UFUNCTION(BlueprintCallable, Category = "Spell System")
	FGSpellSpec MakeSpellSpec() const;
};
