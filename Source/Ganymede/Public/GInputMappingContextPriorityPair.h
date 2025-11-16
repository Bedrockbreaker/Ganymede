// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GInputMappingContextPriorityPair.generated.h"

class UInputMappingContext;

USTRUCT(BlueprintType)
struct GANYMEDE_API FGInputMappingContextPriorityPair
{
	GENERATED_BODY()

public:
	FGInputMappingContextPriorityPair() : MappingContext(nullptr), Priority(0) {}
	FGInputMappingContextPriorityPair(UInputMappingContext* InMappingContext, int32 InPriority)
		: MappingContext(InMappingContext),
		  Priority(InPriority)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	int32 Priority;
};
