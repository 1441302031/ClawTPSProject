// Copyright 2026 YourCompany. All rights reserved.

#include "TPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TPSWeaponComponent.h"

ATPSCharacter::ATPSCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // ========== 初始化移动组件 ==========
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
    GetCharacterMovement()->JumpZVelocity = 600.f;
    GetCharacterMovement()->AirControl = 0.2f;
    GetCharacterMovement()->MaxWalkSpeed = 500.f;
    GetCharacterMovement()->MaxWalkSpeedCrouched = 300.f;

    // ========== 创建相机臂 ==========
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(GetMesh());
    CameraBoom->TargetArmLength = 400.f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 60.f));

    // ========== 创建第三人称相机 ==========
    TPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPSCamera"));
    TPSCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    TPSCamera->bUsePawnControlRotation = false;

    // ========== 创建武器组件 ==========
    WeaponComponent = CreateDefaultSubobject<UTPSWeaponComponent>(TEXT("WeaponComponent"));
    WeaponComponent->SetupAttachment(GetMesh());

    // ========== 默认状态 ==========
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    WalkSpeed = 500.f;
    SprintSpeed = 800.f;
    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;
    AimFOV = 55.f;
    bIsAiming = false;
    bIsSprinting = false;
}

void ATPSCharacter::BeginPlay()
{
    Super::BeginPlay();

    // 添加输入映射上下文
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            if (DefaultMappingContext)
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 1);
            }
        }
    }
}

void ATPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // 转换为 Enhanced Input Component
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // ========== 移动绑定 ==========
        if (MoveAction)
        {
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATPSCharacter::Move);
        }
        if (LookAction)
        {
            EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATPSCharacter::Look);
        }
        if (JumpAction)
        {
            EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ATPSCharacter::JumpStart);
        }
        if (SprintAction)
        {
            EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ATPSCharacter::SprintStart);
            EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ATPSCharacter::SprintEnd);
        }
        if (CrouchAction)
        {
            EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &ATPSCharacter::CrouchStart);
            EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &ATPSCharacter::CrouchEnd);
        }

        // ========== 战斗绑定 ==========
        if (FireAction)
        {
            EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &ATPSCharacter::Fire);
        }
        if (AimAction)
        {
            EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Started, this, &ATPSCharacter::AimStart);
            EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &ATPSCharacter::AimEnd);
        }
        if (ReloadAction)
        {
            EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Started, this, &ATPSCharacter::Reload);
        }
        if (MeleeAction)
        {
            EnhancedInputComponent->BindAction(MeleeAction, ETriggerEvent::Started, this, &ATPSCharacter::Melee);
        }

        // ========== 交互绑定 ==========
        if (InteractAction)
        {
            EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ATPSCharacter::Interact);
        }
    }
}

void ATPSCharacter::Move(const FInputActionValue& Value)
{
    FVector MovementVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(ForwardDirection, MovementVector.Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void ATPSCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        AddControllerYawInput(LookAxisVector.X * BaseTurnRate * GetWorld()->GetDeltaSeconds());
        AddControllerPitchInput(LookAxisVector.Y * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
    }
}

void ATPSCharacter::JumpStart()
{
    if (!bIsCrouched)
    {
        Jump();
    }
}

void ATPSCharacter::SprintStart()
{
    bIsSprinting = true;
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ATPSCharacter::SprintEnd()
{
    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ATPSCharacter::CrouchStart()
{
    if (!IsCrouched())
    {
        Crouch();
    }
    else
    {
        UnCrouch();
    }
}

void ATPSCharacter::CrouchEnd()
{
    // 可选：松开按键时自动站起
}

void ATPSCharacter::AimStart()
{
    bIsAiming = true;
    
    // 降低相机臂长度以获得更好的瞄准视角
    CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, 200.f, GetWorld()->GetDeltaSeconds(), 10.f);
    
    // 缩小 FOV 以获得更好的瞄准体验
    TPSCamera->SetFieldOfView(AimFOV);
}

void ATPSCharacter::AimEnd()
{
    bIsAiming = false;
    
    // 恢复相机臂长度
    CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, 400.f, GetWorld()->GetDeltaSeconds(), 10.f);
    
    // 恢复 FOV
    TPSCamera->SetFieldOfView(90.f);
}

void ATPSCharacter::Fire()
{
    if (WeaponComponent)
    {
        WeaponComponent->Fire();
    }
}

void ATPSCharacter::Reload()
{
    if (WeaponComponent)
    {
        WeaponComponent->Reload();
    }
}

void ATPSCharacter::Melee()
{
    // TODO: 实现近战攻击
    UE_LOG(LogTemp, Log, TEXT("Melee Attack"));
}

void ATPSCharacter::Interact()
{
    // TODO: 实现交互逻辑
    UE_LOG(LogTemp, Log, TEXT("Interact"));
}

void ATPSCharacter::UpdateCameraMode()
{
    // 可选：根据状态更新相机模式
}
