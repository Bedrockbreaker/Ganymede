// Copyright © Bedrockbreaker 2025. MIT License

#include "Components/GInputModeManagerComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "GInputModeActivationToken.h"
#include "GInputModeBlueprintLibrary.h"
#include "GInputModeProvider.h"

UGInputModeManagerComponent::UGInputModeManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UGInputModeManagerComponent::ActivateProvider(UGInputModeProvider* Provider)
{
	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return;

	UGInputModeActivationToken* Token = UGInputModeBlueprintLibrary::ActivateInputModeProvider(LocalPlayer, Provider);

	if (Token) ActiveProviders.Add(Token);
}

void UGInputModeManagerComponent::DeactivateProvider(UGInputModeActivationToken* Token)
{
	ActiveProviders.Remove(Token);
}

ULocalPlayer* UGInputModeManagerComponent::GetLocalPlayer() const
{
	AActor* Owner = GetOwner();
	if (!Owner) return nullptr;

	APawn* Pawn = Cast<APawn>(Owner);
	if (!Pawn)
	{
		APlayerController* PlayerController = Cast<APlayerController>(Owner);
		return PlayerController ? PlayerController->GetLocalPlayer() : nullptr;
	}

	APlayerController* PlayerController = Pawn->GetController<APlayerController>();
	return PlayerController ? PlayerController->GetLocalPlayer() : nullptr;
}
