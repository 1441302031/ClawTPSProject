// Copyright 2026 YourCompany. All rights reserved.

#include "TPSFunctionLibrary.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

float UTPSFunctionLibrary::CalculateDamage(float BaseDamage, float ArmorValue, bool bIsHeadshot, float HeadshotMultiplier)
{
    float Damage = BaseDamage;
    
    // 爆头伤害
    if (bIsHeadshot)
    {
        Damage *= HeadshotMultiplier;
    }
    
    // 护甲减伤（简单线性计算）
    if (ArmorValue > 0)
    {
        float DamageReduction = FMath::Clamp(ArmorValue / 100.0f, 0.0f, 0.75f);
        Damage *= (1.0f - DamageReduction);
    }
    
    return FMath::Max(Damage, 1.0f); // 至少造成 1 点伤害
}

FVector UTPSFunctionLibrary::GetAimedDirection(const FVector& Start, const FVector& End, float Spread)
{
    FVector Direction = (End - Start).GetSafeNormal();
    
    if (Spread > 0.0f)
    {
        // 添加随机散布
        float YawOffset = FMath::FRandRange(-Spread, Spread);
        float PitchOffset = FMath::FRandRange(-Spread, Spread);
        
        FRotator Rotation = Direction.Rotation();
        Rotation.Yaw += YawOffset;
        Rotation.Pitch += PitchOffset;
        
        Direction = Rotation.Vector();
    }
    
    return Direction;
}

float UTPSFunctionLibrary::GetCharacterSpeed(ACharacter* Character)
{
    if (!Character)
    {
        return 0.0f;
    }
    
    return Character->GetVelocity().Size2D();
}

bool UTPSFunctionLibrary::IsCharacterOnGround(ACharacter* Character)
{
    if (!Character)
    {
        return false;
    }
    
    return Character->GetCharacterMovement()->IsMovingOnGround();
}

FText UTPSFunctionLibrary::FormatAmmoDisplay(int32 CurrentAmmo, int32 MaxAmmo)
{
    return FText::Format(FText::FromString(TEXT("{0} / {1}")), 
        FText::AsNumber(CurrentAmmo), 
        FText::AsNumber(MaxAmmo));
}

FText UTPSFunctionLibrary::FormatTimeDisplay(float TimeSeconds)
{
    int32 Minutes = FMath::FloorToInt(TimeSeconds / 60.0f);
    int32 Seconds = FMath::FloorToInt(TimeSeconds) % 60;
    
    return FText::Format(FText::FromString(TEXT("{0}:{1}")), 
        FText::AsNumber(Minutes), 
        FText::AsNumber(Seconds, FNumberFormattingOptions().SetMinimumDigits(2)));
}

FVector UTPSFunctionLibrary::GetRandomPointInRadius(const FVector& Center, float Radius)
{
    return UKismetMathLibrary::RandomPointInBoundingBox(Center, FVector(Radius));
}

float UTPSFunctionLibrary::NormalizeAngle(float Angle)
{
    while (Angle > 180.0f)
    {
        Angle -= 360.0f;
    }
    while (Angle < -180.0f)
    {
        Angle += 360.0f;
    }
    return Angle;
}
