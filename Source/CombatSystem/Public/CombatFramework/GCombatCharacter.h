// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystem/GAbilitySystemComponent.h"
#include "AbilitySystem/GAttributeSet.h"
#include "AbilitySystemInterface.h"
#include "GanymedeFramework/GCharacter.h"

#include "GCombatCharacter.generated.h"

class USphereComponent;
class UGGameplayAbility;
class UGA_GSprint;

UCLASS()
class COMBATSYSTEM_API AGCombatCharacter : public AGCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGCombatCharacter(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Combat")
	bool IsAlive() const { return AttributeSet && AttributeSet->GetHealth() > 0.0f; }

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

	virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	/** Pointer to the AbilitySystemComponent in the PlayerState/AI Controller */
	UPROPERTY()
	TObjectPtr<UGAbilitySystemComponent> AbilitySystemComponent;

	/** Pointer to the AttributeSet in the PlayerState/AI Controller */
	UPROPERTY()
	TObjectPtr<UGAttributeSet> AttributeSet;

	/** Handles sprint inputs */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void StartSprinting(const FInputActionValue& Value);

	/** Handles stop sprint inputs */
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void StopSprinting(const FInputActionValue& Value);

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> MeleeAttackCollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abiliities", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGameplayEffect> DefaultAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abiliities", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<UGGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abiliities", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UGA_GSprint> SprintAbilityClass;

	FGameplayAbilitySpecHandle SprintAbilitySpecHandle;

	UFUNCTION()
	void OnMeleeComponentBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor*				 OtherActor,
		UPrimitiveComponent* OtherComp,
		int32				 OtherBodyIndex,
		bool				 bFromSweep,
		const FHitResult&	 SweepResult);

	void InitAbilitySystemComponent();

	void GiveDefaultAbilities();

	void GiveDefaultAttributes();

	void InitHUD() const;
};
