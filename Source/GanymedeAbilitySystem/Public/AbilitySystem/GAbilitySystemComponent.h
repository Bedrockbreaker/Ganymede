// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystemComponent.h"

#include "GAbilitySystemComponent.generated.h"

/** Ability system component for Ganymede. Manages abilities and attributes for any actors. */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GANYMEDEABILITYSYSTEM_API UGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UGAbilitySystemComponent();

	/** Whether the avatar actor has had its default abilities granted */
	bool bDefaultAbilitiesGranted = false;

	/** Whether the avatar actor has had its startup effects applied */
	bool bStartupEffectsApplied = false;
};
