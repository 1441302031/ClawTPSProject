// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UTPSWeaponComponent.generated.h"

// 前向声明
class UTPSWeaponBase;

/**
 * 武器组件 - 管理角色的所有武器
 * 支持多武器切换、装弹、射击等功能
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TPSPROJECT_API UTPSWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UTPSWeaponComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ========== 武器操作 ==========
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void Fire();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void Reload();

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void SwitchWeapon(int32 WeaponIndex);

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    void EquipWeapon(UTPSWeaponBase* NewWeapon);

    // ========== Getter 方法 ==========
    UFUNCTION(BlueprintCallable, Category = "Weapon")
    UTPSWeaponBase* GetCurrentWeapon() const { return CurrentWeapon; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    TArray<UTPSWeaponBase*> GetAllWeapons() const { return Weapons; }

    UFUNCTION(BlueprintCallable, Category = "Weapon")
    bool IsReloading() const { return bIsReloading; }

protected:
    // ========== 武器列表 ==========
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    TArray<UTPSWeaponBase*> Weapons;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UTPSWeaponBase* CurrentWeapon;

    // ========== 状态变量 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    bool bIsReloading;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float ReloadTime;

    // ========== 定时器 ==========
    FTimerHandle ReloadTimerHandle;

    // ========== 内部方法 ==========
    void OnReloadComplete();
};
