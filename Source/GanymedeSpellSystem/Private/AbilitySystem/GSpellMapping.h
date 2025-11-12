// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GSpellMapping.generated.h"

class UCurveFloat;

UENUM(BlueprintType)
enum class EGSpellMappingType : uint8
{
	Direct,
	Linear,
	ClampedLinear,
	Curve,
	// Custom
};

USTRUCT(BlueprintType)
struct FGSpellMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	FGameplayTag TagIn;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	FGameplayTag TagOut;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	EGSpellMappingType Type = EGSpellMappingType::Direct;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	float TransformScale = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	float TransformOffset = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	float TransformClampMin = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	float TranformClampMax = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	TObjectPtr<UCurveFloat> TransformCurve;

	// UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spell System|Mapping")
	// TObjectPtr<UGTransformCustom> TransformCustom;
};
