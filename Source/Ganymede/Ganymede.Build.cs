// Copyright © Bedrockbreaker 2025. MIT License

using UnrealBuildTool;

public class Ganymede : ModuleRules
{
	public Ganymede(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",

			"InputCore",
			"EnhancedInput"
		});
	}
}
