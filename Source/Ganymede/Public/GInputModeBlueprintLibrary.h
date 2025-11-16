// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "GInputModeBlueprintLibrary.generated.h"

class UGInputModeActivationToken;
class UGInputModeProvider;
class UGInputModeSubsystem;
class ULocalPlayer;

UCLASS()
class GANYMEDE_API UGInputModeBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Input")
	static UGInputModeSubsystem* GetInputModeSubsystem(ULocalPlayer* LocalPlayer);

	UFUNCTION(BlueprintCallable, Category = "Input")
	static UGInputModeActivationToken*
		ActivateInputModeProvider(ULocalPlayer* LocalPlayer, UGInputModeProvider* Provider);

	UFUNCTION(BlueprintCallable, Category = "Input")
	static void DeactivateInputModeProvider(ULocalPlayer* LocalPlayer, UGInputModeProvider* Provider);
};
