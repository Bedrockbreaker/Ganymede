// Copyright © Bedrockbreaker 2025. MIT License

#include "GanymedeFramework/GGameMode.h"

#include "GanymedeFramework/GCharacter.h"
#include "GanymedeFramework/GPlayerController.h"

AGGameMode::AGGameMode()
{
	DefaultPawnClass = AGCharacter::StaticClass();
	PlayerControllerClass = AGPlayerController::StaticClass();
}
