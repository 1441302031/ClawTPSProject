// Copyright 2026 YourCompany. All rights reserved.

#include "TPSWeaponBase.h"
#include "Components/SphereComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ATPSWeaponBase::ATPSWeaponBase()
{
    PrimaryActorTick.bCanEverTick = true;

    // 创建根组件
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // 创建武器网格体
    USkeletalMeshComponent* WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    WeaponMesh->SetupAttachment(RootComponent);

    // 默认武器数据
    WeaponType = EWeaponType::AssaultRifle;
    CurrentAmmo = 30;
    ReserveAmmo = 120;
    bIsFiring = false;
    bIsReloading = false;
}

void ATPSWeaponBase::BeginPlay()
{
    Super::BeginPlay();
}

void ATPSWeaponBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATPSWeaponBase::Fire()
{
    if (CanFire())
    {
        bIsFiring = true;
        ProcessFire();

        // 如果是自动武器，设置连发定时器
        if (WeaponData.FireRate > 1.0f)
        {
            float FireInterval = 1.0f / WeaponData.FireRate;
            GetWorld()->GetTimerManager().SetTimer(
                FireTimerHandle,
                this,
                &ATPSWeaponBase::OnFireTimerComplete,
                FireInterval,
                true
            );
        }
    }
    else if (CurrentAmmo <= 0)
    {
        OnEmptyMagEvent();
    }
}

void ATPSWeaponBase::StartReload()
{
    if (CanReload())
    {
        bIsReloading = true;
        OnReloadEvent();
    }
}

void ATPSWeaponBase::FinishReload()
{
    int32 AmmoNeeded = WeaponData.MagazineSize - CurrentAmmo;
    int32 AmmoToReload = FMath::Min(AmmoNeeded, ReserveAmmo);
    
    CurrentAmmo += AmmoToReload;
    ReserveAmmo -= AmmoToReload;
    bIsReloading = false;
}

bool ATPSWeaponBase::CanFire() const
{
    return CurrentAmmo > 0 && !bIsReloading && !bIsFiring;
}

bool ATPSWeaponBase::CanReload() const
{
    return CurrentAmmo < WeaponData.MagazineSize && ReserveAmmo > 0 && !bIsReloading;
}

void ATPSWeaponBase::ProcessFire()
{
    if (CurrentAmmo > 0)
    {
        CurrentAmmo--;
        OnFireEvent();

        // 执行射线检测
        AActor* Owner = GetOwner();
        if (Owner)
        {
            AController* InstigatorController = Owner->GetInstigatorController();
            if (InstigatorController)
            {
                FVector Start;
                FVector End;
                
                // 获取相机位置和方向
                if (APlayerController* PC = Cast<APlayerController>(InstigatorController))
                {
                    APlayerCameraManager* CameraManager = PC->PlayerCameraManager;
                    if (CameraManager)
                    {
                        Start = CameraManager->GetCameraLocation();
                        End = Start + CameraManager->GetActorRotation().Vector() * WeaponData.Range;
                    }
                }
                else
                {
                    Start = Owner->GetActorLocation();
                    End = Start + Owner->GetActorForwardVector() * WeaponData.Range;
                }

                // 添加散布
                End = UKismetMathLibrary::RandomPointInBoundingBox(End, FVector(WeaponData.Spread));

                // 执行射线检测
                FHitResult HitResult;
                FCollisionQueryParams QueryParams;
                QueryParams.AddIgnoredActor(Owner);
                QueryParams.bTraceComplex = true;

                if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams))
                {
                    // 应用伤害
                    UGameplayStatics::ApplyDamage(
                        HitResult.GetActor(),
                        WeaponData.Damage,
                        InstigatorController,
                        Owner,
                        UDamageType::StaticClass()
                    );

                    // 生成命中效果（可选）
                    // TODO: 添加 Niagara 效果
                }
            }
        }
    }
}

void ATPSWeaponBase::OnFireTimerComplete()
{
    // 检查是否继续射击（由 Character 控制）
    // 这里只是定时器回调
}
