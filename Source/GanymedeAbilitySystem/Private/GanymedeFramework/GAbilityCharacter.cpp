// Copyright © Bedrockbreaker 2025. MIT License

#include "GanymedeFramework/GAbilityCharacter.h"

#include "AbilitySystem/GAbilitySystemComponent.h"
#include "AbilitySystem/GAttributeSet.h"
#include "AbilitySystem/GGameplayAbility.h"
#include "AbilitySystemComponent.h"
#include "GanymedeAbilitySystem.h"

AGAbilityCharacter::AGAbilityCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	bAlwaysRelevant = true;
}

bool AGAbilityCharacter::IsAlive() const
{
	return AttributeSet.IsValid() ? AttributeSet->GetHealth() > 0.0f : false;
}

UAbilitySystemComponent* AGAbilityCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

void AGAbilityCharacter::GiveDefaultAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid()
		|| AbilitySystemComponent->bDefaultAbilitiesGranted)
	{
		return;
	}

	for (TSubclassOf<UGGameplayAbility>& AbilityClass : DefaultAbilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1, 0, this));
	}

	AbilitySystemComponent->bDefaultAbilitiesGranted = true;
}

void AGAbilityCharacter::GiveDefaultAttributes()
{
	if (!AbilitySystemComponent.IsValid()) return;

	if (!DefaultAttributes)
	{
		UE_LOG(
			LogGanymedeAbilitySystem,
			Error,
			TEXT("%s is missing its DefaultAttributes. Please add at least one GameplayEffect."),
			*GetName());
		return;
	}

	// This is purposefully allowed to be called both on the server and the client.
	// The client will apply the attributes to itself (prediction),
	// And the values the server will send back should be the same anyway.

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle Handle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, EffectContext);
	if (Handle.IsValid()) AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*Handle.Data.Get());
}

void AGAbilityCharacter::GiveStartupEffects()
{
	if (GetLocalRole() != ROLE_Authority || !AbilitySystemComponent.IsValid()
		|| AbilitySystemComponent->bStartupEffectsApplied)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect>& EffectClass : StartupEffects)
	{
		FGameplayEffectSpecHandle Handle = AbilitySystemComponent->MakeOutgoingSpec(EffectClass, 1, EffectContext);
		if (Handle.IsValid()) AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*Handle.Data.Get());
	}

	AbilitySystemComponent->bStartupEffectsApplied = true;
}

void AGAbilityCharacter::BeginPlay()
{
	Super::BeginPlay();
}
