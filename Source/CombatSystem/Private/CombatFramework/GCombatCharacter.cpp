// Copyright © Bedrockbreaker 2025. MIT License

#include "CombatFramework/GCombatCharacter.h"

#include "Abilities/GA_GSprint.h"
#include "AbilitySystem/GGameplayAbility.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "CombatFramework/GCharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "EnhancedInputComponent.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffectTypes.h"
#include "GanymedeFramework/GCharacter.h"
#include "GanymedeFramework/GCombatPlayerState.h"

AGCombatCharacter::AGCombatCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UGCharacterMovementComponent>(
		  ACharacter::CharacterMovementComponentName))
{
	SprintAbilityClass = UGA_GSprint::StaticClass();

	MeleeAttackCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MeleeAttackCollisionComponent"));
	MeleeAttackCollisionComponent->SetupAttachment(GetMesh(), HasAuthority() ? FName("Muzzle_01") : NAME_None);
	MeleeAttackCollisionComponent->SetIsReplicated(true);
	MeleeAttackCollisionComponent->SetSphereRadius(30.0f);
	MeleeAttackCollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeleeAttackCollisionComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeleeAttackCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECR_Overlap);
	MeleeAttackCollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Vehicle, ECR_Overlap);
}

void AGCombatCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	GiveDefaultAttributes();
	InitHUD();
}

void AGCombatCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	// Don't give abilities on clients, they are only given on the server.
	GiveDefaultAttributes();
	InitHUD();
}

void AGCombatCharacter::StartSprinting(const FInputActionValue& Value)
{
	// BUG: This actually isn't replicated properly. Ability input bindings should be done through their proper channel.
	// Doing it like this doesn't inform the server.
	check(AbilitySystemComponent);
	if (!SprintAbilitySpecHandle.IsValid()) return;

	UE_LOG(LogTemp, Warning, TEXT("Sprint Activated (input)."));

	OnStartSprint();
	AbilitySystemComponent->TryActivateAbility(SprintAbilitySpecHandle);
}

void AGCombatCharacter::StopSprinting(const FInputActionValue& Value)
{
	check(AbilitySystemComponent);
	if (!SprintAbilitySpecHandle.IsValid()) return;

	UE_LOG(LogTemp, Warning, TEXT("Sprint Deactivated (input)."));

	OnStopSprint();
	AbilitySystemComponent->CancelAbilityHandle(SprintAbilitySpecHandle);
}

void AGCombatCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (MeleeAttackCollisionComponent != nullptr)
	{
		MeleeAttackCollisionComponent->OnComponentBeginOverlap.AddDynamic(
			this, &AGCombatCharacter::OnMeleeComponentBeginOverlap);
	}
}

void AGCombatCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!EnhancedInputComponent) return;

	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AGCombatCharacter::StartSprinting);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AGCombatCharacter::StopSprinting);
}

void AGCombatCharacter::OnMeleeComponentBeginOverlap(
	UPrimitiveComponent* OverlappedComponent,
	AActor*				 OtherActor,
	UPrimitiveComponent* OtherComp,
	int32				 OtherBodyIndex,
	bool				 bFromSweep,
	const FHitResult&	 SweepResult)
{
	// TODO: stub

	// if (OtherActor == nullptr || OtherActor == this) return;

	// UAbilitySystemComponent* OtherASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(OtherActor);
	// if (OtherASC == nullptr) return;

	// FGameplayTag EventTag = FGameplayTag::RequestGameplayTag(FName("Event.Melee.Hit"));

	// FGameplayEffectContextHandle	 EffectContext = OtherASC->MakeEffectContext();
	// FGameplayAbilityTargetDataHandle TargetData =
	// 	UAbilitySystemBlueprintLibrary::AbilityTargetDataFromActor(OtherActor);

	// FGameplayEventData Payload;
	// Payload.EventTag = EventTag;
	// Payload.Instigator = this;
	// Payload.Target = OtherActor;
	// Payload.ContextHandle = EffectContext;
	// Payload.TargetData = TargetData;

	// UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(this, EventTag, Payload);
}

void AGCombatCharacter::InitAbilitySystemComponent()
{
	AGCombatPlayerState* GPlayerState = GetPlayerStateChecked<AGCombatPlayerState>();
	AbilitySystemComponent = CastChecked<UGAbilitySystemComponent>(GPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(GPlayerState, this);

	AttributeSet = GPlayerState->GetAttributeSet();
}

void AGCombatCharacter::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	if (!HasAuthority()) return;

	if (SprintAbilityClass)
		SprintAbilitySpecHandle =
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(SprintAbilityClass, 1, 0, this));

	for (TSubclassOf<UGGameplayAbility>& AbilityClass : DefaultAbilities)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1, 0, this));
	}
}

void AGCombatCharacter::GiveDefaultAttributes()
{
	check(AbilitySystemComponent && AttributeSet);

	// TODO: Handling player rejoin needs extra logic, so they don't reset their stats after their network drops
	// connection for a few seconds.

	if (!DefaultAttributes)
	{
		UE_LOG(
			LogGCharacter,
			Error,
			TEXT("%s is missing its DefaultAttributes. Please add at least one GameplayEffect."),
			*GetName());
		return;
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle SpecHandle =
		AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, EffectContext);
	if (SpecHandle.IsValid()) AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AGCombatCharacter::InitHUD() const
{
	// TODO: stub

	// AGPlayerController* PlayerController = GetController<AGPlayerController>();
	// if (PlayerController == nullptr) return;

	// AGCombatHUD* HUD = PlayerController->GetHUD<AGCombatHUD>();
	// if (HUD == nullptr) return;

	// HUD->Init();
}
