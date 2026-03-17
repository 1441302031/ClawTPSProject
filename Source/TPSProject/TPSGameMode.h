// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPSGameMode.generated.h"

/**
 * TPS 游戏模式
 * 管理游戏规则、玩家生成等
 */
UCLASS()
class TPSPROJECT_API ATPSGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ATPSGameMode();

protected:
    virtual void BeginPlay() override;

public:
    // ========== 游戏状态管理 ==========
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void StartMatch();

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void EndMatch();

    // ========== 玩家管理 ==========
    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void RestartPlayer(AController* NewPlayer);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode|Settings")
    int32 MaxPlayers;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode|Settings")
    float MatchDuration;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameMode|State")
    bool bMatchInProgress;
};
