// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GInputModeActivationToken.generated.h"

class UGInputModeSubsystem;
class UGInputModeProvider;

UCLASS(BlueprintType)
class GANYMEDE_API UGInputModeActivationToken : public UObject
{
	GENERATED_BODY()

public:
	void Init(UGInputModeSubsystem* InSubsystem, UGInputModeProvider* InProvider);

protected:
	virtual void BeginDestroy() override;

private:
	UPROPERTY()
	TObjectPtr<UGInputModeSubsystem> Subsystem;

	UPROPERTY()
	TObjectPtr<UGInputModeProvider> Provider;
};
