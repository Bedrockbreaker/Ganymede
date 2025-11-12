// Copyright © Bedrockbreaker 2025. MIT License

using UnrealBuildTool;

public class GanymedePlayerFramework : ModuleRules
{
	public GanymedePlayerFramework(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",

			"InputCore",
			"EnhancedInput",

			"Ganymede"
		});
	}
}
