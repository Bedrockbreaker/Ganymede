// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagContainer.h"

#include "GCharacterMovementComponent.generated.h"

// KAMO: Implement aim down sights?

class FNetworkPredictionData_Client;
class FNetworkPredictionData_Client_Character;

DECLARE_LOG_CATEGORY_EXTERN(LogGCharacterMovementComponent, Log, All);

class FGSavedMove : public FSavedMove_Character
{
public:
	typedef FSavedMove_Character Super;

	uint8 SavedRequestToStartSprinting : 1;

	virtual void Clear() override;

	virtual uint8 GetCompressedFlags() const override;

	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const override;

	virtual void SetMoveFor(
		ACharacter*								 Character,
		float									 InDeltaTime,
		const FVector&							 NewAccel,
		FNetworkPredictionData_Client_Character& ClientData) override;

	virtual void PrepMoveFor(ACharacter* Character) override;
};

class FGNetworkPredictionData_Client : public FNetworkPredictionData_Client_Character
{
public:
	typedef FNetworkPredictionData_Client_Character Super;

	FGNetworkPredictionData_Client(const UCharacterMovementComponent& ClientMovement) : Super(ClientMovement) {};

	virtual FSavedMovePtr AllocateNewMove() override;
};

UCLASS()
class COMBATSYSTEM_API UGCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UGCharacterMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintSpeedMultiplier = 1.5f;

	uint8 RequestToStartSprinting : 1;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StartSprinting() { RequestToStartSprinting = true; }

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StopSprinting() { RequestToStartSprinting = false; }

	virtual float GetMaxSpeed() const override;

	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

private:
	FGameplayTag StunnedTag;
};
