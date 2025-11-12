// Copyright © Bedrockbreaker 2025. MIT License

using UnrealBuildTool;

public class GanymedeSpellSystem : ModuleRules
{
	public GanymedeSpellSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",

			"Ganymede",
			"GanymedeAbilitySystem"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});
	}
}
