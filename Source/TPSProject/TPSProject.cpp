// Copyright 2026 YourCompany. All rights reserved.

#include "TPSProject.h"
#include "Modules/ModuleManager.h"

void FTPSProjectModule::StartupModule()
{
    // 模块启动时初始化
    UE_LOG(LogTemp, Log, TEXT("TPSProject Module Started"));
}

void FTPSProjectModule::ShutdownModule()
{
    // 模块关闭时清理
    UE_LOG(LogTemp, Log, TEXT("TPSProject Module Shutdown"));
}

IMPLEMENT_MODULE(FDefaultModuleImpl, TPSProject)
