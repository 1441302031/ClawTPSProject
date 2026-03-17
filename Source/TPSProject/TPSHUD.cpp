// Copyright 2026 YourCompany. All rights reserved.

#include "TPSHUD.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "Engine/Font.h"

ATPSHUD::ATPSHUD()
{
    bShowCrosshair = true;
    bShowAmmoCounter = true;
    bShowHealthBar = true;
    
    CrosshairWidget = nullptr;
    AmmoCounterWidget = nullptr;
    HealthBarWidget = nullptr;
}

void ATPSHUD::BeginPlay()
{
    Super::BeginPlay();
    
    // TODO: 初始化 HUD Widgets
}

void ATPSHUD::DrawHUD()
{
    Super::DrawHUD();
    
    // 绘制准星
    if (bShowCrosshair)
    {
        DrawCrosshair();
    }
}

void ATPSHUD::ShowCrosshair(bool bShow)
{
    bShowCrosshair = bShow;
    
    if (CrosshairWidget)
    {
        CrosshairWidget->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void ATPSHUD::ShowAmmoCounter(bool bShow)
{
    bShowAmmoCounter = bShow;
    
    if (AmmoCounterWidget)
    {
        AmmoCounterWidget->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void ATPSHUD::ShowHealthBar(bool bShow)
{
    bShowHealthBar = bShow;
    
    if (HealthBarWidget)
    {
        HealthBarWidget->SetVisibility(bShow ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void ATPSHUD::UpdateAmmoDisplay(int32 CurrentAmmo, int32 MaxAmmo)
{
    // TODO: 更新弹药显示 Widget
    UE_LOG(LogTemp, Verbose, TEXT("Ammo: %d / %d"), CurrentAmmo, MaxAmmo);
}

void ATPSHUD::UpdateHealthDisplay(float CurrentHealth, float MaxHealth)
{
    // TODO: 更新生命值显示 Widget
    UE_LOG(LogTemp, Verbose, TEXT("Health: %.1f / %.1f"), CurrentHealth, MaxHealth);
}

void ATPSHUD::UpdateScoreDisplay(int32 Score)
{
    // TODO: 更新分数显示 Widget
    UE_LOG(LogTemp, Verbose, TEXT("Score: %d"), Score);
}

void ATPSHUD::AddGameWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    if (WidgetClass && GetOwningPlayerController())
    {
        UUserWidget* NewWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), WidgetClass);
        if (NewWidget)
        {
            NewWidget->AddToViewport();
        }
    }
}

void ATPSHUD::RemoveGameWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    // TODO: 实现 Widget 移除逻辑
}

void ATPSHUD::DrawCrosshair()
{
    if (!Canvas)
    {
        return;
    }
    
    FVector2D Center(Canvas->ClipX / 2.0f, Canvas->ClipY / 2.0f);
    float CrosshairSize = 10.0f;
    
    // 绘制简单的十字准星
    FCanvasLineItem LineItem(FVector2D(Center.X - CrosshairSize, Center.Y), FVector2D(Center.X + CrosshairSize, Center.Y));
    LineItem.LineColor = FLinearColor::White;
    Canvas->DrawItem(LineItem);
    
    LineItem = FCanvasLineItem(FVector2D(Center.X, Center.Y - CrosshairSize), FVector2D(Center.X, Center.Y + CrosshairSize));
    LineItem.LineColor = FLinearColor::White;
    Canvas->DrawItem(LineItem);
}

void ATPSHUD::DrawTextureSimple(UTexture2D* Texture, float ScreenX, float ScreenY, float Scale)
{
    if (Texture && Canvas)
    {
        float Width = Texture->GetSurfaceWidth() * Scale;
        float Height = Texture->GetSurfaceHeight() * Scale;
        
        FCanvasTileItem TileItem(
            FVector2D(ScreenX - Width / 2.0f, ScreenY - Height / 2.0f),
            Texture->GetResource(),
            FVector2D(Width, Height),
            FLinearColor::White
        );
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}
