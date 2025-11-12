// Copyright © Bedrockbreaker 2025. MIT License

#include "AbilitySystem/GAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/Controller.h"
#include "GameplayEffectExtension.h"
#include "GanymedeAbilitySystem.h"
#include "GanymedeFramework/GAbilityCharacter.h"
#include "Net/UnrealNetwork.h"

UGAttributeSet::UGAttributeSet()
{
	// Default debug values
	InitHealth(80.0f);
}

void UGAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, HealthRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, StaminaRegenRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGAttributeSet, ManaRegenRate, COND_None, REPNOTIFY_Always);
}

void UGAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// Gather data about the source of the gameplay effect

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent*	 SourceASC = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	FGameplayTagContainer		 SpecAssetTags;
	Data.EffectSpec.GetAllAssetTags(SpecAssetTags);

	AActor*				SourceActor = nullptr;
	AController*		SourceController = nullptr;
	AGAbilityCharacter* SourceCharacter = nullptr;
	if (SourceASC && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		SourceActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
		SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
		if (!SourceController && SourceActor)
		{
			APawn* Pawn = Cast<APawn>(SourceActor);
			if (Pawn) SourceController = Pawn->GetController();
		}

		SourceCharacter = SourceController ? Cast<AGAbilityCharacter>(SourceController->GetPawn())
										   : Cast<AGAbilityCharacter>(SourceActor);

		if (Context.GetEffectCauser()) SourceActor = Context.GetEffectCauser();
	}

	// Gather data about the target (the owner of this attribute set instance)

	UAbilitySystemComponent* TargetASC = GetOwningAbilitySystemComponent();

	AActor*				TargetActor = nullptr;
	AController*		TargetController = nullptr;
	AGAbilityCharacter* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AGAbilityCharacter>(TargetActor);
	}

	// Evaluate the gameplay effect

	if (Data.EvaluatedData.Attribute == GetManaBurnAttribute())
	{
		// Copy a local value and clear the attribute
		float ManaBurned = GetManaBurn();
		SetManaBurn(0);

		float CurrentMana = GetMana();

		if (CurrentMana >= ManaBurned && ManaBurned > 0.0f)
		{
			SetMana(CurrentMana - ManaBurned);
		}
		else if (ManaBurned > 0.0f)
		{
			float RemainingCost = ManaBurned - CurrentMana;
			SetMana(0.0f);

			// Apply remaining cost as damage to self

			UGameplayEffect* DamageGE = NewObject<UGameplayEffect>(GetTransientPackage(), FName(TEXT("Damage")));
			DamageGE->DurationPolicy = EGameplayEffectDurationType::Instant;

			int32 index = DamageGE->Modifiers.Num();
			DamageGE->Modifiers.SetNum(index + 1);

			FGameplayModifierInfo& DamageInfo = DamageGE->Modifiers[index];
			DamageInfo.Attribute = GetDamageAttribute();
			DamageInfo.ModifierOp = EGameplayModOp::Additive;
			DamageInfo.ModifierMagnitude = FScalableFloat(RemainingCost);

			TargetASC->ApplyGameplayEffectToSelf(DamageGE, 1.0f, TargetASC->MakeEffectContext());
		}
	}
	else if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		// Copy a local value and clear the attribute
		float DamageDone = GetDamage();
		SetDamage(0.0f);

		if (DamageDone > 0.0f)
		{
			bool bAliveBeforeDamage = true;

			if (TargetCharacter) bAliveBeforeDamage = TargetCharacter->IsAlive();

			if (!TargetCharacter->IsAlive())
			{
				UE_LOG(
					LogGanymedeAbilitySystem,
					Warning,
					TEXT("%s is not alive when taking damage"),
					*TargetCharacter->GetName());
			}

			SetHealth(FMath::Clamp(GetHealth() - DamageDone, 0.0f, GetMaxHealth()));

			if (TargetCharacter && bAliveBeforeDamage)
			{
				UE_LOG(
					LogGanymedeAbilitySystem, Log, TEXT("%s took %f damage"), *TargetCharacter->GetName(), DamageDone);

				// TODO: Play damage cue notification for hit/death
			}
		}
	}
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.0f, GetMaxStamina()));
	}
	else if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
	}
}

void UGAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Health, OldHealth);
}

void UGAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, MaxHealth, OldMaxHealth);
}

void UGAttributeSet::OnRep_HealthRegenRate(const FGameplayAttributeData& OldHealthRegenRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, MaxHealth, OldHealthRegenRate);
}

void UGAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Stamina, OldStamina);
}

void UGAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, MaxStamina, OldMaxStamina);
}

void UGAttributeSet::OnRep_StaminaRegenRate(const FGameplayAttributeData& OldStaminaRegenRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, StaminaRegenRate, OldStaminaRegenRate);
}

void UGAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, Mana, OldMana);
}

void UGAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, MaxMana, OldMaxMana);
}

void UGAttributeSet::OnRep_ManaRegenRate(const FGameplayAttributeData& OldManaRegenRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGAttributeSet, ManaRegenRate, OldManaRegenRate);
}
