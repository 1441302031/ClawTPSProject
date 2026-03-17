// Copyright 2026 YourCompany. All rights reserved.

#include "TPSPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ATPSPlayerController::ATPSPlayerController()
{
    bIsPaused = false;
    bShowCrosshair = true;
    PauseMenuClass = nullptr;
    PauseMenuWidget = nullptr;
}

void ATPSPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // 默认显示准星
    ShowCrosshair(true);
}

void ATPSPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATPSPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // 如果使用 Enhanced Input，可以在这里绑定暂停菜单输入
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // 暂停菜单绑定可以在这里添加
    }
}

void ATPSPlayerController::OnMatchStarted()
{
    UE_LOG(LogTemp, Log, TEXT("Match Started for Player: %s"), *GetName());
    
    // 隐藏鼠标光标
    bShowMouseCursor = false;
    SetInputMode(FInputModeGameOnly());
}

void ATPSPlayerController::OnMatchEnded()
{
    UE_LOG(LogTemp, Log, TEXT("Match Ended for Player: %s"), *GetName());
    
    // 显示鼠标光标
    bShowMouseCursor = true;
    SetInputMode(FInputModeUIOnly());
}

void ATPSPlayerController::ShowPauseMenu()
{
    if (PauseMenuClass && !PauseMenuWidget)
    {
        PauseMenuWidget = CreateWidget<UUserWidget>(this, PauseMenuClass);
        if (PauseMenuWidget)
        {
            PauseMenuWidget->AddToViewport();
        }
    }

    bIsPaused = true;
    bShowMouseCursor = true;
    SetInputMode(FInputModeUIOnly());
}

void ATPSPlayerController::HidePauseMenu()
{
    if (PauseMenuWidget)
    {
        PauseMenuWidget->RemoveFromParent();
        PauseMenuWidget = nullptr;
    }

    bIsPaused = false;
    bShowMouseCursor = false;
    SetInputMode(FInputModeGameOnly());
}

void ATPSPlayerController::ShowCrosshair(bool bShow)
{
    bShowCrosshair = bShow;
    // TODO: 通知 HUD 更新准星显示
}

void ATPSPlayerController::TogglePause()
{
    if (bIsPaused)
    {
        HidePauseMenu();
    }
    else
    {
        ShowPauseMenu();
    }
}

void ATPSPlayerController::PauseMenu_Open()
{
    ShowPauseMenu();
}

void ATPSPlayerController::PauseMenu_Close()
{
    HidePauseMenu();
}
