// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GMappingContextState.generated.h"

class UGInputModeProvider;

USTRUCT(BlueprintType)
struct FGMappingContextState
{
	GENERATED_BODY()

public:
	int32 RefCount = 0;
	int32 MaxPriority = 0;

	TMap<TWeakObjectPtr<UGInputModeProvider>, int32> Providers;
};
