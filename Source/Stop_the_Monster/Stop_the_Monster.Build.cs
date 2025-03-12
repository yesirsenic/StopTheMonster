// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Stop_the_Monster : ModuleRules
{
	public Stop_the_Monster(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
