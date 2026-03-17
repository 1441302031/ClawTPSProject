// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UTPSWeaponBase.generated.h"

// 武器类型枚举
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
    AssaultRifle    UMETA(DisplayName = "Assault Rifle"),
    Shotgun         UMETA(DisplayName = "Shotgun"),
    SniperRifle     UMETA(DisplayName = "Sniper Rifle"),
    Pistol          UMETA(DisplayName = "Pistol"),
    SMG             UMETA(DisplayName = "SMG"),
    Melee           UMETA(DisplayName = "Melee")
};

// 武器数据
USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float FireRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float Range;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    int32 MagazineSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ReloadTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float Spread;

    FWeaponData()
        : Damage(25.0f)
        , FireRate(10.0f)
        , Range(10000.0f)
        , MagazineSize(30)
        , ReloadTime(2.0f)
        , Spread(1.0f)
    {}
};

/**
 * 武器基类 - 所有武器的父类
 */
UCLASS()
class TPSPROJECT_API ATPSWeaponBase : public AActor
{
    GENERATED_BODY()

public:
    ATPSWeaponBase();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // ========== 武器操作 ==========
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void Fire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void StartReload();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual void FinishReload();

    // ========== 状态检查 ==========
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual bool CanFire() const;

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    virtual bool CanReload() const;

    // ========== Getter 方法 ==========
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    EWeaponType GetWeaponType() const { return WeaponType; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    int32 GetCurrentAmmo() const { return CurrentAmmo; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    int32 GetMaxAmmo() const { return WeaponData.MagazineSize; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    float GetDamage() const { return WeaponData.Damage; }

protected:
    // ========== 武器配置 ==========
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    EWeaponType WeaponType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FWeaponData WeaponData;

    // ========== 弹药状态 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|Ammo")
    int32 CurrentAmmo;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|Ammo")
    int32 ReserveAmmo;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|State")
    bool bIsFiring;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon|State")
    bool bIsReloading;

    // ========== 计时器 ==========
    FTimerHandle FireTimerHandle;

    // ========== 内部方法 ==========
    virtual void ProcessFire();
    virtual void OnFireTimerComplete();

    // ========== 事件 ==========
    UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
    void OnFireEvent();

    UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
    void OnReloadEvent();

    UFUNCTION(BlueprintImplementableEvent, Category = "Weapon")
    void OnEmptyMagEvent();
};
