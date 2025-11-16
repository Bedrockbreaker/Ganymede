// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Engine/DataAsset.h"

#include "GInputModeProvider.generated.h"

class UGInputModeSubsystem;
class UInputMappingContext;
struct FGInputMappingContextPriorityPair;

UCLASS()
class GANYMEDE_API UGInputModeProvider : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	FName ModeName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<FGInputMappingContextPriorityPair> MappingContexts;
};
