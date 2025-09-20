// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Abilities/GameplayAbility.h"

#include "GGameplayAbility.generated.h"

struct FGameplayAbilityActorInfo;
struct FGameplayAbilitySpec;

/**
 * Base class for all gameplay abilities in Ganymede.
 * Defaults to allowing health substitution in place of mana.
 */
UCLASS()
class GANYMEDEABILITYSYSTEM_API UGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGGameplayAbility();

	/**
	 * Whether to activate the ability as soon as it is granted.
	 * Can be used for passive abilities or abilities forced on others.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
	bool bActivateAbilityOnGranted = false;

	/**
	 * Allows immediate activation of the ability when it is granted.
	 * Other "BeginPlay" logic can be handled here as well.
	 */
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
