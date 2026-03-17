// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TPSGameInstance.generated.h"

/**
 * TPS 游戏实例
 * 管理持久化数据、会话信息等
 */
UCLASS()
class TPSPROJECT_API UTPSGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    // ========== 会话管理 ==========
    UFUNCTION(BlueprintCallable, Category = "Session")
    void CreateSession(int32 MaxPlayers = 4);

    UFUNCTION(BlueprintCallable, Category = "Session")
    void JoinSession(int32 SessionIndex);

    UFUNCTION(BlueprintCallable, Category = "Session")
    void DestroySession();

    // ========== 玩家数据 ==========
    UFUNCTION(BlueprintCallable, Category = "Player")
    void SavePlayerData();

    UFUNCTION(BlueprintCallable, Category = "Player")
    void LoadPlayerData();

    // ========== Getter/Setter ==========
    UFUNCTION(BlueprintCallable, Category = "Data")
    int32 GetPlayerLevel() const { return PlayerLevel; }

    UFUNCTION(BlueprintCallable, Category = "Data")
    void SetPlayerLevel(int32 NewLevel) { PlayerLevel = NewLevel; }

protected:
    virtual void Init() override;
    virtual void Shutdown() override;

    // ========== 玩家持久化数据 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Data")
    int32 PlayerLevel;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Data")
    int32 PlayerXP;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Data")
    TArray<FName> UnlockedWeapons;

    // ========== 会话状态 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Session")
    bool bIsInSession;
};
