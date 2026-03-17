// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TPSGameState.generated.h"

/**
 * TPS 游戏状态
 * 存储游戏的全局状态信息
 */
UCLASS()
class TPSPROJECT_API ATPSGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    ATPSGameState();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // ========== 游戏时间 ==========
    UFUNCTION(BlueprintCallable, Category = "GameState")
    float GetMatchTimeRemaining() const;

    UFUNCTION(BlueprintCallable, Category = "GameState")
    float GetMatchElapsedTime() const;

    // ========== 分数管理 ==========
    UFUNCTION(BlueprintCallable, Category = "GameState")
    void AddScore(AController* Scorer, int32 Points);

    UFUNCTION(BlueprintCallable, Category = "GameState")
    int32 GetScore(AController* Player) const;

    // ========== Getter 方法 ==========
    UFUNCTION(BlueprintCallable, Category = "GameState")
    bool IsMatchInProgress() const { return bMatchInProgress; }

protected:
    // ========== 游戏状态 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameState")
    bool bMatchInProgress;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameState")
    float MatchElapsedTime;

    // ========== 分数映射 ==========
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameState")
    TMap<AController*, int32> PlayerScores;
};
