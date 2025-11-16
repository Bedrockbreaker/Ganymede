// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GMappingContextState.h"
#include "InputMappingContext.h"
#include "Subsystems/LocalPlayerSubsystem.h"

#include "GInputModeSubsystem.generated.h"

class UGInputModeActivationToken;
class UGInputModeProvider;
class UEnhancedInputLocalPlayerSubsystem;
struct FGScopedInputModeProviderHandle;

DECLARE_LOG_CATEGORY_EXTERN(LogGInputModeSubsystem, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGOnInputModeChangedDelegate, UGInputModeProvider*, NewProvider);

UCLASS()
class GANYMEDE_API UGInputModeSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FGOnInputModeChangedDelegate OnInputModeChanged;

	UGInputModeActivationToken* RequestActivateProvider(UGInputModeProvider* Provider);

	void RequestDeactivateProvider(UGInputModeProvider* Provider);

	UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputSubsystem() const;

private:
	UPROPERTY()
	TMap<TObjectPtr<UInputMappingContext>, FGMappingContextState> MappingStates;

	UPROPERTY()
	TSet<TObjectPtr<UGInputModeProvider>> RegisteredProviders;

	void ApplyMappingContext(UInputMappingContext* IMC, int32 Priority);
	void RemoveMappingContext(UInputMappingContext* IMC);
};
