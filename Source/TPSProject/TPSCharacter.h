// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "TPSCharacter.generated.h"

// 声明组件类
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class UTPSWeaponComponent;

/**
 * 第三人称射击游戏角色基类
 * 包含移动、视角、武器系统等核心功能
 */
UCLASS()
class TPSPROJECT_API ATPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATPSCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    // ========== 移动相关 ==========
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void JumpStart();
    void SprintStart();
    void SprintEnd();
    void CrouchStart();
    void CrouchEnd();

    // ========== 武器相关 ==========
    void Fire();
    void AimStart();
    void AimEnd();
    void Reload();
    void Melee();
    void Interact();

    // ========== 相机相关 ==========
    void UpdateCameraMode();

public:
    // ========== Getter 方法 ==========
    UFUNCTION(BlueprintCallable, Category = "Character")
    UCameraComponent* GetTPSCamera() const { return TPSCamera; }
    
    UFUNCTION(BlueprintCallable, Category = "Character")
    USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    
    UFUNCTION(BlueprintCallable, Category = "Character")
    UTPSWeaponComponent* GetWeaponComponent() const { return WeaponComponent; }
    
    UFUNCTION(BlueprintCallable, Category = "Character")
    bool IsAiming() const { return bIsAiming; }

protected:
    // ========== 组件 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* TPSCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UTPSWeaponComponent* WeaponComponent;

    // ========== 输入资源 ==========
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
    UInputAction* LookAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
    UInputAction* JumpAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
    UInputAction* SprintAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Move")
    UInputAction* CrouchAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Combat")
    UInputAction* FireAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Combat")
    UInputAction* AimAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Combat")
    UInputAction* ReloadAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Combat")
    UInputAction* MeleeAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input|Interaction")
    UInputAction* InteractAction;

    // ========== 状态变量 ==========
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Movement")
    float WalkSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Movement")
    float SprintSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
    float BaseTurnRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
    float BaseLookUpRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
    float AimFOV;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|State")
    bool bIsAiming;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|State")
    bool bIsSprinting;
};
