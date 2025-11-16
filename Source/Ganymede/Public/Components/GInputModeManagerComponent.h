// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "Components/ActorComponent.h"

#include "GInputModeManagerComponent.generated.h"

class UGInputModeActivationToken;
class UGInputModeProvider;
class ULocalPlayer;

UCLASS(ClassGroup = (Input), meta = (BlueprintSpawnableComponent))
class GANYMEDE_API UGInputModeManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGInputModeManagerComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TArray<TSoftObjectPtr<UGInputModeProvider>> Providers;

	UFUNCTION(BlueprintCallable, Category = "Input")
	void ActivateProvider(UGInputModeProvider* Provider);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void DeactivateProvider(UGInputModeActivationToken* Token);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TArray<UGInputModeActivationToken*> ActiveProviders;

	ULocalPlayer* GetLocalPlayer() const;
};
