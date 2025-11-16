// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/GameModeBase.h"
#include "GGameMode.generated.h"

/** Default game mode for Ganymede. Does not contain rules for actual gameplay. */
UCLASS(Abstract)
class GANYMEDE_API AGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGGameMode();
};
