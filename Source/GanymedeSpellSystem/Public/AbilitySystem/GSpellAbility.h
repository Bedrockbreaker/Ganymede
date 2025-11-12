// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GGameplayAbility.h"
#include "AbilitySystem/GSpellSpec.h"

#include "GSpellAbility.generated.h"

/** Catch-all for all spell abilities. Thin dispatcher that wraps around UGSpellSpec. */
UCLASS()
class GANYMEDESPELLSYSTEM_API UGSpellAbility : public UGGameplayAbility
{
	GENERATED_BODY()

public:
	UGSpellAbility();

	UPROPERTY(EditDefaultsOnly, Category = "Spell System")
	FGSpellSpec SpellSpec;
};
