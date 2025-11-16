// Copyright © Bedrockbreaker 2025. MIT License

#include "GInputModeActivationToken.h"

#include "Subsystems/GInputModeSubsystem.h"

void UGInputModeActivationToken::Init(UGInputModeSubsystem* InSubsystem, UGInputModeProvider* InProvider)
{
	Subsystem = InSubsystem;
	Provider = InProvider;
}

void UGInputModeActivationToken::BeginDestroy()
{
	Super::BeginDestroy();

	if (Subsystem && Provider) Subsystem->RequestDeactivateProvider(Provider);

	Subsystem = nullptr;
	Provider = nullptr;
}
