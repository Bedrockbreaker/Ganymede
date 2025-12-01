// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/SaveGame.h"

#include "GSaveGame.generated.h"

UCLASS()
class UGSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MainVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MusicVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SFXVolume = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<bool> LevelsCompleted;
};
