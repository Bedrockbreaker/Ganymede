// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GanymedeFramework/GPlayerState.h"

#include "GCombatPlayerState.generated.h"

class UGAbilitySystemComponent;
class UGAttributeSet;

UCLASS()
class COMBATSYSTEM_API AGCombatPlayerState : public AGPlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGCombatPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	virtual UGAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UGAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UGAttributeSet> AttributeSet;
};
