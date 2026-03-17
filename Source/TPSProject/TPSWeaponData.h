// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TPSWeaponData.generated.h"

/**
 * 武器数据行 - 用于 DataTable 配置武器属性
 */
USTRUCT(BlueprintType)
struct FTPSWeaponData : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FName WeaponID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FText WeaponName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float FireRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float Range;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    int32 MagazineSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float ReloadTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float Spread;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Stats")
    float EquipTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Audio")
    USoundBase* FireSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Audio")
    USoundBase* ReloadSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Audio")
    USoundBase* EmptySound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Visual")
    USkeletalMesh* WeaponMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Visual")
    UMaterialInterface* OverrideMaterial;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Visual")
    UNiagaraSystem* MuzzleFlash;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Visual")
    UNiagaraSystem* HitEffect;

    FTPSWeaponData()
        : Damage(25.0f)
        , FireRate(10.0f)
        , Range(10000.0f)
        , MagazineSize(30)
        , ReloadTime(2.0f)
        , Spread(1.0f)
        , EquipTime(0.5f)
        , FireSound(nullptr)
        , ReloadSound(nullptr)
        , EmptySound(nullptr)
        , WeaponMesh(nullptr)
        , OverrideMaterial(nullptr)
        , MuzzleFlash(nullptr)
        , HitEffect(nullptr)
    {}
};
