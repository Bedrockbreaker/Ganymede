// Copyright © Bedrockbreaker 2025. MIT License

using UnrealBuildTool;

public class GanymedeAbilitySystem : ModuleRules
{
	public GanymedeAbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",

			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",

			"Ganymede"
		});
	}
}
