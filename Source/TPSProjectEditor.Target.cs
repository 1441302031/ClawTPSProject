// Copyright 2026 YourCompany. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TPSProjectEditorTarget : TargetRules
{
    public TPSProjectEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        ExtraModuleNames.Add("TPSProject");
    }
}
