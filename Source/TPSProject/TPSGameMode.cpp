// Copyright 2026 YourCompany. All rights reserved.

#include "TPSGameMode.h"
#include "TPSGameState.h"
#include "TPSPlayerController.h"
#include "TPSCharacter.h"
#include "Kismet/GameplayStatics.h"

ATPSGameMode::ATPSGameMode()
{
    // 设置默认类
    static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/TPSProject.TPSCharacter"));
    if (DefaultPawnClassRef.Class != nullptr)
    {
        DefaultPawnClass = DefaultPawnClassRef.Class;
    }

    static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/TPSProject.TPSPlayerController"));
    if (PlayerControllerClassRef.Class != nullptr)
    {
        PlayerControllerClass = PlayerControllerClassRef.Class;
    }

    GameStateClass = ATPSGameState::StaticClass();
    
    MaxPlayers = 16;
    MatchDuration = 600.0f; // 10 分钟
    bMatchInProgress = false;
}

void ATPSGameMode::BeginPlay()
{
    Super::BeginPlay();
}

void ATPSGameMode::StartMatch()
{
    if (!bMatchInProgress)
    {
        bMatchInProgress = true;
        
        // 通知所有玩家游戏开始
        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            ATPSPlayerController* PC = Cast<ATPSPlayerController>(It->Get());
            if (PC)
            {
                PC->OnMatchStarted();
            }
        }

        UE_LOG(LogTemp, Log, TEXT("Match Started"));
    }
}

void ATPSGameMode::EndMatch()
{
    if (bMatchInProgress)
    {
        bMatchInProgress = false;
        
        // 通知所有玩家游戏结束
        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            ATPSPlayerController* PC = Cast<ATPSPlayerController>(It->Get());
            if (PC)
            {
                PC->OnMatchEnded();
            }
        }

        UE_LOG(LogTemp, Log, TEXT("Match Ended"));
    }
}

void ATPSGameMode::RestartPlayer(AController* NewPlayer)
{
    Super::RestartPlayer(NewPlayer);
    
    if (NewPlayer)
    {
        // 生成在默认出生点
        RestartPlayerAtDefaultLocation(NewPlayer);
    }
}
