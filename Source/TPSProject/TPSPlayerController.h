// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPSPlayerController.generated.h"

/**
 * TPS 玩家控制器
 * 处理玩家输入和 UI 显示
 */
UCLASS()
class TPSPROJECT_API ATPSPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ATPSPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupInputComponent() override;

public:
    // ========== 游戏事件 ==========
    UFUNCTION(BlueprintCallable, Category = "Events")
    virtual void OnMatchStarted();

    UFUNCTION(BlueprintCallable, Category = "Events")
    virtual void OnMatchEnded();

    // ========== UI 控制 ==========
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowPauseMenu();

    UFUNCTION(BlueprintCallable, Category = "UI")
    void HidePauseMenu();

    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowCrosshair(bool bShow);

    // ========== 暂停控制 ==========
    UFUNCTION(BlueprintCallable, Category = "Pause")
    void TogglePause();

    UFUNCTION(BlueprintCallable, Category = "Pause")
    bool IsPaused() const { return bIsPaused; }

protected:
    // ========== 暂停菜单输入 ==========
    void PauseMenu_Open();
    void PauseMenu_Close();

    // ========== 状态变量 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bIsPaused;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bShowCrosshair;

    // ========== UI 引用 ==========
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PauseMenuClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UUserWidget* PauseMenuWidget;
};
