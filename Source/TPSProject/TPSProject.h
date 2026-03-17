// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FTPSProjectModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
