// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEAISample : ModuleRules
{
	public UEAISample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
            "SlateCore",
			"NavigationSystem",
			"AIModule"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UEAISample",
			"UEAISample/Variant_Platforming",
			"UEAISample/Variant_Platforming/Animation",
			"UEAISample/Variant_Combat",
			"UEAISample/Variant_Combat/AI",
			"UEAISample/Variant_Combat/Animation",
			"UEAISample/Variant_Combat/Gameplay",
			"UEAISample/Variant_Combat/Interfaces",
			"UEAISample/Variant_Combat/UI",
			"UEAISample/Variant_SideScrolling",
			"UEAISample/Variant_SideScrolling/AI",
			"UEAISample/Variant_SideScrolling/Gameplay",
			"UEAISample/Variant_SideScrolling/Interfaces",
			"UEAISample/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
