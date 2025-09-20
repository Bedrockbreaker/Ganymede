// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

#include "GAttributeSet.generated.h"

#define NUMERIC_VALUE(AttributeSetName, PropertyName) \
	AttributeSetName->Get##PropertyName##Attribute().GetNumericValue(AttributeSetName)

/**
 * Attribute set for Ganymede, intended for any actor.
 * Handles health, stamina, and mana.
 */
UCLASS()
class GANYMEDEABILITYSYSTEM_API UGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGAttributeSet();

	/**
	 * Current health.
	 * Positive changes can be directly applied to this attribute.
	 * Negative changes should be applied via the Damage meta attribute.
	 */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, Health)

	/** Maximum health */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, MaxHealth)

	/**
	 * Meta attribute to subtract from health.
	 * Ephemeral value that is server-side only; not replicated.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, Damage)

	/** Current stamina */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Stamina", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, Stamina)

	/** Maximum stamina */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxStamina", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, MaxStamina)

	/** Stamina regen rate, in points/second */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_StaminaRegenRate", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData StaminaRegenRate;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, StaminaRegenRate)

	/** Current mana */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Mana", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, Mana)

	/** Maximum mana */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxMana", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, MaxMana)

	/** Mana regen rate, in points/second */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_ManaRegenRate", Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData ManaRegenRate;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, ManaRegenRate)

	/**
	 * Meta attribute used by GManaBurnExecCalculation to calculate final mana and health costs.
	 * Ephemeral value that is server-side only; not replicated.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Ability | Gameplay Attribute")
	FGameplayAttributeData ManaBurn;
	ATTRIBUTE_ACCESSORS_BASIC(UGAttributeSet, ManaBurn)

	/** Replicated properties */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/** Post gameplay effects, clamp attribute values as needed */
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

protected:
	/** Replicate health */
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	/** Replicate max health */
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	/** Replicate stamina */
	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	/** Replicate max stamina */
	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;

	/** Replicate stamina regen rate */
	UFUNCTION()
	virtual void OnRep_StaminaRegenRate(const FGameplayAttributeData& OldStaminaRegenRate) const;

	/** Replicate mana */
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	/** Replicate max mana */
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

	/** Replicate mana regen rate */
	UFUNCTION()
	virtual void OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate) const;
};
