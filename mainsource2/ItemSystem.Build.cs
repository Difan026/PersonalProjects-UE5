// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ItemSystem : ModuleRules
{
	public ItemSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GameplayTags",//向数组中添加gameplayTags，让我们能在编辑器内部访问gameplay tags
			"DeveloperSettings"//添加开发者选项
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ItemSystem",
			"ItemSystem/Variant_Platforming",
			"ItemSystem/Variant_Platforming/Animation",
			"ItemSystem/Variant_Combat",
			"ItemSystem/Variant_Combat/AI",
			"ItemSystem/Variant_Combat/Animation",	
			"ItemSystem/Variant_Combat/Gameplay",
			"ItemSystem/Variant_Combat/Interfaces",
			"ItemSystem/Variant_Combat/UI",
			"ItemSystem/Variant_SideScrolling",
			"ItemSystem/Variant_SideScrolling/AI",
			"ItemSystem/Variant_SideScrolling/Gameplay",
			"ItemSystem/Variant_SideScrolling/Interfaces",
			"ItemSystem/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
