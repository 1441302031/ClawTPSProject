// Copyright 2026 YourCompany. All rights reserved.

using UnrealBuildTool;

public class TPSProject : ModuleRules
{
    public TPSProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore",
            "EnhancedInput",
            "GameplayTags",
            "GameplayTasks",
            "GameplayAbilities"
        });

        PrivateDependencyModuleNames.AddRange(new string[] 
        { 
            "Slate", 
            "SlateCore",
            "UMG",
            "AIModule",
            "Niagara"
        });

        // 启用 Enhanced Input 系统（UE5 推荐）
        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.Add("UnrealEd");
        }
    }
}
