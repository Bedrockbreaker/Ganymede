// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "GameFramework/Character.h"

#include "GCharacter.generated.h"

class UCameraComponent;
class UGInputModeManagerComponent;
class UInputAction;
class USkeletalMeshComponent;
struct FInputActionValue;

GANYMEDE_API DECLARE_LOG_CATEGORY_EXTERN(LogGCharacter, Log, All);

/**
 * Base character for Ganymede. Handles character movement, etc.
 */
UCLASS(Abstract)
class GANYMEDE_API AGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGCharacter(const FObjectInitializer& ObjectInitializer);

	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	USkeletalMeshComponent* GetFirstPersonMeshComponent() const { return FirstPersonMesh; }

protected:
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	/** Handles move inputs */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void Move(const FInputActionValue& Value);

	/** Handles look inputs */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void Look(const FInputActionValue& Value);

	/** Called when a UPlayerController possesses this Character */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// TODO: Replace with just a socket. Have the CameraManager attach the camera instead.
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> FirstPersonCameraComponent;

	/** First person mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<USkeletalMeshComponent> FirstPersonMesh;

	/** Handles input modes */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UGInputModeManagerComponent> InputModeManagerComponent;
};
