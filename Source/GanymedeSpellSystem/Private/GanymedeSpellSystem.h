// Copyright © Bedrockbreaker 2025. MIT License

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGanymedeSpellSystem, Log, All);

class FGanymedeSpellSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override {};
	virtual void ShutdownModule() override {};
};
