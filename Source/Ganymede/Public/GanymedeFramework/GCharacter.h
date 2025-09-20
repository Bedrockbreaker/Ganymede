// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/Character.h"

#include "GCharacter.generated.h"

/**
 * Base character for Ganymede. Handles character movement, etc.
 * Knows nothing about player input, AI senses, GAS abilities, etc.
 */
UCLASS(abstract)
class GANYMEDE_API AGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGCharacter();
};
