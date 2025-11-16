// Copyright © Bedrockbreaker 2025. MIT License

#include "GanymedeFramework/GPlayerController.h"

#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "GanymedeCamera/GPlayerCameraManager.h"
#include "InputActionValue.h"

AGPlayerController::AGPlayerController()
{
	PlayerCameraManagerClass = AGPlayerCameraManager::StaticClass();
}
