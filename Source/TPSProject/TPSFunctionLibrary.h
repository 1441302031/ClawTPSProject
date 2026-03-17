// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TPSFunctionLibrary.generated.h"

/**
 * TPS 功能函数库 - 提供蓝图可调用的工具函数
 */
UCLASS()
class TPSPROJECT_API UTPSFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // ========== 战斗相关 ==========
    
    /** 计算伤害（考虑护甲、爆头等） */
    UFUNCTION(BlueprintCallable, Category = "TPS|Combat")
    static float CalculateDamage(float BaseDamage, float ArmorValue, bool bIsHeadshot, float HeadshotMultiplier = 2.0f);

    /** 获取射击方向（考虑散布） */
    UFUNCTION(BlueprintCallable, Category = "TPS|Combat")
    static FVector GetAimedDirection(const FVector& Start, const FVector& End, float Spread);

    // ========== 角色相关 ==========
    
    /** 获取角色移动速度 */
    UFUNCTION(BlueprintCallable, Category = "TPS|Character")
    static float GetCharacterSpeed(ACharacter* Character);

    /** 检查角色是否在地面 */
    UFUNCTION(BlueprintCallable, Category = "TPS|Character")
    static bool IsCharacterOnGround(ACharacter* Character);

    // ========== UI 相关 ==========
    
    /** 格式化弹药显示 */
    UFUNCTION(BlueprintCallable, Category = "TPS|UI")
    static FText FormatAmmoDisplay(int32 CurrentAmmo, int32 MaxAmmo);

    /** 格式化时间显示 */
    UFUNCTION(BlueprintCallable, Category = "TPS|UI")
    static FText FormatTimeDisplay(float TimeSeconds);

    // ========== 工具函数 ==========
    
    /** 获取随机点（在指定范围内） */
    UFUNCTION(BlueprintCallable, Category = "TPS|Utility")
    static FVector GetRandomPointInRadius(const FVector& Center, float Radius);

    /** 角度归一化（-180 到 180） */
    UFUNCTION(BlueprintCallable, Category = "TPS|Utility")
    static float NormalizeAngle(float Angle);
};
