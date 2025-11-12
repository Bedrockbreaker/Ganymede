// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "AbilitySystemComponent.h"

#include "GAbilitySystemComponent.generated.h"

/** Ability system component for Ganymede. Manages abilities and attributes for any actors. */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GANYMEDEABILITYSYSTEM_API UGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UGAbilitySystemComponent();

	/** Whether the avatar actor has had its default abilities granted */
	bool bDefaultAbilitiesGranted = false;

	/** Whether the avatar actor has had its startup effects applied */
	bool bStartupEffectsApplied = false;

	// TODO: override OnGameplayEffectAppliedToSelf (or OnGameplayEffectAppliedToTarget) to trigger secondary effects
	// FIXME: On second thought, the ASC should instead cache the most recent EffectContext (PostGameplayEffectExecute)
	//        only when a Damage GE is applied. Then, when the ASC's GetGameplayAttributeValueChangeDelegate is called,
	//        the player state/character/whatever can do something with that EffectContext (such as attribute a bounty).
	//        Responses to this delegate *do* need to be guarded by HasAuthority() to avoid clients mispredicting
	//        important information, such as actor deaths or other things related to "game rules".
	// BUG: In fact, if the original idea is used, it breaks for periodic/infinite GEs.
	//      The ASC's OnGameplayEffectAppliedToSelf is only called once upon GE *application*, not upon GE *execution*.
	/* e.g.:

	// In UGAbilitySystemComponent
	DECLARE_MULTICAST_DYNAMIC_DELEGATE_TwoParams(
		FGOnDamageGEAppliedDelegate,
		UAbilitySystemComponent*,
		Instigator,
		const FGameplayEffectContextHandle&,
		EffectContext);

	// In UGAbilitySystemComponent
	public FGOnDamageGEAppliedDelegate OnDamageGEApplied;

	public void UGAbilitySystemComponent::OnGameplayEffectAppliedToSelf(
		UAbilitySystemComponent* Source,
		const FGameplayEffectSpec& SpecApplied,
		FActiveGameplayEffectHandle ActiveHandle) override
	{
		Super::OnGameplayEffectAppliedToSelf(Source, SpecApplied, ActiveHandle);

		OnDamageGEApplied.Broadcast(Source, SpecApplied.GetEffectContext());
	}

	public AGCharacter::AGCharacter()
	{
		// Or after the ASC for this actor is created
		UGAbilitySystemComponent* ASC = Cast<UGAbilitySystemComponent>(GetAbilitySystemComponent());
		if (ASC)
		{
			ASC->OnDamageGEApplied.AddUObject(this, &AGCharacter::OnDamageGEApplied);
		}
	}

	public void AGCharacter::OnDamageGEApplied(
		UAbilitySystemComponent* Source, const FGameplayEffectContextHandle& EffectContext)
	{
		UGAttributeSet* AttributeSet = Cast<UGAttributeSet>(GetAttributeSet());
		if (AttributeSet && AttributeSet->GetHealth() <= 0.0f)
		{
			// Do not call death functions/animations here.
			// That should be handled via the ASC's GetGameplayAttributeValueChangeDelegate for Health

			if (GetLocalRole() != ROLE_Authority) return;

			AActor* Instigator = EffectContext.GetOriginalInstigator();
			if (!Instigator) return;

			UGameplayEffect* GEBounty = NewObject<UGameplayEffect>(GetTransientPackage(), FName(TEXT("Bounty")));
			GEBounty->DurationPolicy = EGameplayEffectDurationType::Instant;

			int32 Index = GEBounty->Modifiers.Num();
			GEBounty->Modifiers.SetNum(Index + 2);

			FGameplayModifierInfo& ModXP = GEBounty->Modifiers[Index++];
			ModXP.ModifierMagnitude = FScalableFloat(GetXPBounty());
			ModXP.ModifierOp = EGameplayModOp::Additive;
			ModXP.Attribute = UGAttributeSet::GetXPAttribute();

			FGameplayModifierInfo& ModGold = GEBounty->Modifiers[Index++];
			ModGold.ModifierMagnitude = FScalableFloat(GetGoldBounty());
			ModGold.ModifierOp = EGameplayModOp::Additive;
			ModGold.Attribute = UGAttributeSet::GetGoldAttribute();

			Source->ApplyGameplayEffectToSelf(GEBounty, 1.0f, Source->MakeEffectContext());
		}
	}
	*/
};
