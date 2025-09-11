// Copyright © Bedrockbreaker 2025. MIT License

using UnrealBuildTool;

public class GanymedeEditorTarget : TargetRules
{
	public GanymedeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("Ganymede");
	}
}
