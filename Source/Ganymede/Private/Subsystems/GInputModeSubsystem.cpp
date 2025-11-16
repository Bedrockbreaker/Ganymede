// Copyright © Bedrockbreaker 2025. MIT License

#include "Subsystems/GInputModeSubsystem.h"

#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "GInputMappingContextPriorityPair.h"
#include "GInputModeActivationToken.h"
#include "GInputModeProvider.h"

DEFINE_LOG_CATEGORY(LogGInputModeSubsystem);

UEnhancedInputLocalPlayerSubsystem* UGInputModeSubsystem::GetEnhancedInputSubsystem() const
{
	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return nullptr;
	return LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
}

UGInputModeActivationToken* UGInputModeSubsystem::RequestActivateProvider(UGInputModeProvider* Provider)
{
	check(Provider);

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetEnhancedInputSubsystem();
	if (!InputSubsystem) return nullptr;

	for (const FGInputMappingContextPriorityPair& Pair : Provider->MappingContexts)
	{
		if (!Pair.MappingContext)
		{
			UE_LOG(
				LogGInputModeSubsystem,
				Warning,
				TEXT("UGInputModeSubsystem::RequestActivateProvider: IMC is null for provider %s"),
				*Provider->ModeName.ToString());
			continue;
		}

		FGMappingContextState& State = MappingStates.FindOrAdd(Pair.MappingContext);
		++State.RefCount;
		State.MaxPriority = FMath::Max(State.MaxPriority, Pair.Priority);
		State.Providers.Add(Provider, Pair.Priority);

		// EnhancedInput will handle multiple applications properly
		ApplyMappingContext(Pair.MappingContext, State.MaxPriority);
	}

	OnInputModeChanged.Broadcast(Provider);

	UGInputModeActivationToken* Token = NewObject<UGInputModeActivationToken>(this);
	Token->Init(this, Provider);

	return Token;
}

void UGInputModeSubsystem::RequestDeactivateProvider(UGInputModeProvider* Provider)
{
	check(Provider);

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetEnhancedInputSubsystem();
	if (!InputSubsystem) return;

	for (const FGInputMappingContextPriorityPair& Pair : Provider->MappingContexts)
	{
		if (!Pair.MappingContext)
		{
			UE_LOG(
				LogGInputModeSubsystem,
				Warning,
				TEXT("UGInputModeSubsystem::RequestDeactivateProvider: IMC is null for provider %s"),
				*Provider->ModeName.ToString());
			continue;
		}

		FGMappingContextState* StatePtr = MappingStates.Find(Pair.MappingContext);
		if (!StatePtr) continue;

		FGMappingContextState& State = *StatePtr;

		int32 RemovedPriority = 0;
		if (!State.Providers.RemoveAndCopyValue(Provider, RemovedPriority)) continue;

		State.RefCount = FMath::Max(0, State.RefCount - 1);

		int32 NewMax = 0;
		for (const auto& ProviderPair : State.Providers)
		{
			NewMax = FMath::Max(NewMax, ProviderPair.Value);
		}
		State.MaxPriority = NewMax;

		if (State.RefCount == 0)
		{
			RemoveMappingContext(Pair.MappingContext);
			MappingStates.Remove(Pair.MappingContext);
		}
		else
		{
			ApplyMappingContext(Pair.MappingContext, State.MaxPriority);
		}
	}

	OnInputModeChanged.Broadcast(nullptr);
}

void UGInputModeSubsystem::ApplyMappingContext(UInputMappingContext* IMC, int32 Priority)
{
	check(IMC);

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetEnhancedInputSubsystem();
	if (!InputSubsystem) return;

	InputSubsystem->AddMappingContext(IMC, Priority);
}

void UGInputModeSubsystem::RemoveMappingContext(UInputMappingContext* IMC)
{
	check(IMC);

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetEnhancedInputSubsystem();
	if (!InputSubsystem) return;

	InputSubsystem->RemoveMappingContext(IMC);
}
