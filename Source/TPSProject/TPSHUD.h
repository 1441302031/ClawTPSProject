// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TPSHUD.generated.h"

/**
 * TPS 游戏 HUD
 * 管理游戏界面显示
 */
UCLASS()
class TPSPROJECT_API ATPSHUD : public AHUD
{
    GENERATED_BODY()

public:
    ATPSHUD();

protected:
    virtual void BeginPlay() override;
    virtual void DrawHUD() override;

public:
    // ========== HUD 元素控制 ==========
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ShowCrosshair(bool bShow);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ShowAmmoCounter(bool bShow);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void ShowHealthBar(bool bShow);

    // ========== 数据更新 ==========
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateAmmoDisplay(int32 CurrentAmmo, int32 MaxAmmo);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateHealthDisplay(float CurrentHealth, float MaxHealth);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void UpdateScoreDisplay(int32 Score);

    // ========== Widget 管理 ==========
    UFUNCTION(BlueprintCallable, Category = "HUD")
    void AddGameWidget(TSubclassOf<UUserWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void RemoveGameWidget(TSubclassOf<UUserWidget> WidgetClass);

protected:
    // ========== HUD 状态 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|State")
    bool bShowCrosshair;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|State")
    bool bShowAmmoCounter;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|State")
    bool bShowHealthBar;

    // ========== Widget 引用 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|Widgets")
    UUserWidget* CrosshairWidget;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|Widgets")
    UUserWidget* AmmoCounterWidget;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HUD|Widgets")
    UUserWidget* HealthBarWidget;

    // ========== 绘制辅助 ==========
    void DrawCrosshair();
    void DrawTextureSimple(UTexture2D* Texture, float ScreenX, float ScreenY, float Scale = 1.0f);
};
