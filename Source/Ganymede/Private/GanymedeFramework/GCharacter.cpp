// Copyright © Bedrockbreaker 2025. MIT License

#include "GanymedeFramework/GCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/GInputModeManagerComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GInputModeBlueprintLibrary.h"
#include "GInputModeProvider.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogGCharacter);

AGCharacter::AGCharacter(const FObjectInitializer& ObjectInitializer)
{
	InputModeManagerComponent = CreateDefaultSubobject<UGInputModeManagerComponent>(TEXT("Input Mode Manager"));

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(2.8f, 0.0f, 70.0f)); // Some magic numbers, but they work
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bEnableFirstPersonFieldOfView = true;
	FirstPersonCameraComponent->bEnableFirstPersonScale = true;
	FirstPersonCameraComponent->FirstPersonFieldOfView = 70.0f;
	FirstPersonCameraComponent->FirstPersonScale = 0.6f;

	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));
	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	GetCapsuleComponent()->InitCapsuleSize(34.0f, 96.0f);

	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::WorldSpaceRepresentation;

	GetCharacterMovement()->BrakingDecelerationWalking = 1500.0f;
	GetCharacterMovement()->AirControl = 0.5f;
}

void AGCharacter::Move(const FInputActionValue& Value)
{
	if (!GetController()) return;

	FVector2D InputVector = Value.Get<FVector2D>();
	AddMovementInput(GetActorRightVector(), InputVector.X);
	AddMovementInput(GetActorForwardVector(), InputVector.Y);
}

void AGCharacter::Look(const FInputActionValue& Value)
{
	if (!GetController()) return;

	FVector2D InputVector = Value.Get<FVector2D>();
	AddControllerYawInput(InputVector.X);
	AddControllerPitchInput(InputVector.Y);
}

void AGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		UE_LOG(LogGCharacter, Error, TEXT("%s failed to find EnhancedInputComponent"), *GetNameSafe(this));
		return;
	}

	if (InputModeManagerComponent)
	{
		for (TSoftObjectPtr<UGInputModeProvider> ProviderAsset : InputModeManagerComponent->Providers)
		{
			UGInputModeProvider* Provider = ProviderAsset.LoadSynchronous();
			check(Provider);
			InputModeManagerComponent->ActivateProvider(Provider);
		}
	}

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AGCharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AGCharacter::StopJumping);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGCharacter::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGCharacter::Look);
}
