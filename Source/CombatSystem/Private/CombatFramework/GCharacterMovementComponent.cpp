// Copyright © Bedrockbreaker 2025. MIT License

#include "CombatFramework/GCharacterMovementComponent.h"

#include "AbilitySystemComponent.h"
#include "CombatFramework/GCombatCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/NetworkPredictionInterface.h"

DEFINE_LOG_CATEGORY(LogGCharacterMovementComponent);

void FGSavedMove::Clear()
{
	Super::Clear();

	SavedRequestToStartSprinting = false;
}

uint8 FGSavedMove::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();

	if (SavedRequestToStartSprinting) Result |= FSavedMove_Character::FLAG_Custom_0;

	return Result;
}

bool FGSavedMove::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const
{
	return SavedRequestToStartSprinting != ((FGSavedMove*) &NewMove)->SavedRequestToStartSprinting
		&& Super::CanCombineWith(NewMove, Character, MaxDelta);
}

void FGSavedMove::SetMoveFor(
	ACharacter*								 Character,
	float									 InDeltaTime,
	const FVector&							 NewAccel,
	FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	UGCharacterMovementComponent* GCharacterMovement =
		Cast<UGCharacterMovementComponent>(Character->GetCharacterMovement());
	if (GCharacterMovement) SavedRequestToStartSprinting = GCharacterMovement->RequestToStartSprinting;
}

void FGSavedMove::PrepMoveFor(ACharacter* Character)
{
	Super::PrepMoveFor(Character);

	// ???

	// UGCharacterMovementComponent* GCharacterMovement =
	// Cast<UGCharacterMovementComponent>(Character->GetCharacterMovement());

	// if (GCharacterMovement) GCharacterMovement->RequestToStartSprinting = SavedRequestToStartSprinting;
}

FSavedMovePtr FGNetworkPredictionData_Client::AllocateNewMove()
{
	return FSavedMovePtr(new FGSavedMove());
}

UGCharacterMovementComponent::UGCharacterMovementComponent()
{
	StunnedTag = FGameplayTag::RequestGameplayTag(FName("State.Debuff.Stunned"));
}

float UGCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();

	AGCombatCharacter* Owner = Cast<AGCombatCharacter>(GetOwner());
	if (!Owner)
	{
		UE_LOG(LogGCharacterMovementComponent, Error, TEXT("%s is not an AGCombatCharacter"), *GetName());
		return MaxSpeed;
	}

	if (!Owner->IsAlive()) return 0.0f;

	UAbilitySystemComponent* ASC = Owner->GetAbilitySystemComponent();
	if (!ASC) return MaxSpeed;

	if (ASC->HasMatchingGameplayTag(StunnedTag)) return 0.0f;

	if (RequestToStartSprinting) return MaxSpeed * SprintSpeedMultiplier;

	return MaxSpeed;
}

void UGCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	RequestToStartSprinting = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
}

FNetworkPredictionData_Client* UGCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner);

	if (!ClientPredictionData)
	{
		UGCharacterMovementComponent* MutableThis = const_cast<UGCharacterMovementComponent*>(this);

		MutableThis->ClientPredictionData = new FGNetworkPredictionData_Client(*this);
		MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.0f;
		MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.0f;
	}

	return ClientPredictionData;
}
