// Copyright © Bedrockbreaker 2025. MIT License

#include "GInputModeBlueprintLibrary.h"

#include "Engine/LocalPlayer.h"
#include "GInputModeActivationToken.h"
#include "Subsystems/GInputModeSubsystem.h"

UGInputModeSubsystem* UGInputModeBlueprintLibrary::GetInputModeSubsystem(ULocalPlayer* LocalPlayer)
{
	if (!LocalPlayer) return nullptr;
	return LocalPlayer->GetSubsystem<UGInputModeSubsystem>();
}

UGInputModeActivationToken*
	UGInputModeBlueprintLibrary::ActivateInputModeProvider(ULocalPlayer* LocalPlayer, UGInputModeProvider* Provider)
{
	if (!LocalPlayer || !Provider) return nullptr;
	UGInputModeSubsystem* IMS = GetInputModeSubsystem(LocalPlayer);
	return IMS ? IMS->RequestActivateProvider(Provider) : nullptr;
}

void UGInputModeBlueprintLibrary::DeactivateInputModeProvider(ULocalPlayer* LocalPlayer, UGInputModeProvider* Provider)
{
	if (!LocalPlayer || !Provider) return;
	UGInputModeSubsystem* IMS = GetInputModeSubsystem(LocalPlayer);
	if (IMS) IMS->RequestDeactivateProvider(Provider);
}
