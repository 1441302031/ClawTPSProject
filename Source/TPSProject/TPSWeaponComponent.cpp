// Copyright 2026 YourCompany. All rights reserved.

#include "TPSWeaponComponent.h"
#include "TPSWeaponBase.h"

UTPSWeaponComponent::UTPSWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsReloading = false;
    ReloadTime = 2.0f;
    CurrentWeapon = nullptr;
}

void UTPSWeaponComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UTPSWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTPSWeaponComponent::Fire()
{
    if (CurrentWeapon && !bIsReloading && CurrentWeapon->CanFire())
    {
        CurrentWeapon->Fire();
    }
}

void UTPSWeaponComponent::Reload()
{
    if (CurrentWeapon && !bIsReloading && CurrentWeapon->CanReload())
    {
        bIsReloading = true;
        CurrentWeapon->StartReload();
        
        // 设置装弹定时器
        GetWorld()->GetTimerManager().SetTimer(
            ReloadTimerHandle,
            this,
            &UTPSWeaponComponent::OnReloadComplete,
            ReloadTime,
            false
        );
    }
}

void UTPSWeaponComponent::SwitchWeapon(int32 WeaponIndex)
{
    if (Weapons.IsValidIndex(WeaponIndex))
    {
        if (CurrentWeapon)
        {
            CurrentWeapon->SetActorHiddenInGame(true);
            CurrentWeapon->SetActorTickEnabled(false);
        }

        CurrentWeapon = Weapons[WeaponIndex];
        
        if (CurrentWeapon)
        {
            CurrentWeapon->SetActorHiddenInGame(false);
            CurrentWeapon->SetActorTickEnabled(true);
            CurrentWeapon->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
        }
    }
}

void UTPSWeaponComponent::EquipWeapon(UTPSWeaponBase* NewWeapon)
{
    if (NewWeapon && !Weapons.Contains(NewWeapon))
    {
        Weapons.Add(NewWeapon);
        
        if (!CurrentWeapon)
        {
            SwitchWeapon(0);
        }
    }
}

void UTPSWeaponComponent::OnReloadComplete()
{
    bIsReloading = false;
    
    if (CurrentWeapon)
    {
        CurrentWeapon->FinishReload();
    }
}
