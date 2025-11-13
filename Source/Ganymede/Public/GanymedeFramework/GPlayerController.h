// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/PlayerController.h"

#include "GPlayerController.generated.h"

class UInputMappingContext;

/** Base player controller for Ganymede */
UCLASS()
class GANYMEDE_API AGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGPlayerController();

protected:
	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	virtual void SetupInputComponent() override;
};
