// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystemInterface.h"
#include "GanymedeFramework/GCharacter.h"

#include "GAbilityCharacter.generated.h"

class UGGameplayAbility;
class UGAbilitySystemComponent;
class UGameplayEffect;
class UGAttributeSet;

/** Ability-aware character. Does not know about player input, AI senses, etc. */
UCLASS(abstract)
class GANYMEDEABILITYSYSTEM_API AGAbilityCharacter : public AGCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGAbilityCharacter();

	UFUNCTION(BlueprintCallable, Category = "GAbilityCharacter")
	virtual bool IsAlive() const;

	//~ IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

protected:
	/** Pointer to the AbilitySystemComponent on the Player/AIAgent State */
	TWeakObjectPtr<UGAbilitySystemComponent> AbilitySystemComponent;

	/** Pointer to the attribute set on the Player/AIAgent State */
	TWeakObjectPtr<UGAttributeSet> AttributeSet;

	/**
	 * Default abilities for the character.
	 * Will be removed on character death, and re-added on character spawn.
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GAbilityCharacter|Abilities")
	TArray<TSubclassOf<UGGameplayAbility>> DefaultAbilities;

	/**
	 * Default attributes for the character for both initialization and respawn.
	 * This should be an instant GE that overrides the values for attributes that get reset on spawn.
	 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GAbilityCharacter|Abilities")
	TSubclassOf<UGameplayEffect> DefaultAttributes;

	/** Effects that only apply on character initialization. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GAbilityCharacter|Abilities")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	/** Grant the default abilities, both on initialization and on respawn */
	virtual void GiveDefaultAbilities();

	/** Grant the default attributes, both on initialization and on respawn */
	virtual void GiveDefaultAttributes();

	/** Grant the startup effects, only on initialization */
	virtual void GiveStartupEffects();

	virtual void BeginPlay() override;
};
