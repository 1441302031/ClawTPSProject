// Copyright 2026 YourCompany. All rights reserved.

#include "TPSGameState.h"

ATPSGameState::ATPSGameState()
{
    bMatchInProgress = false;
    MatchElapsedTime = 0.0f;
}

void ATPSGameState::BeginPlay()
{
    Super::BeginPlay();
}

void ATPSGameState::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bMatchInProgress)
    {
        MatchElapsedTime += DeltaTime;
    }
}

float ATPSGameState::GetMatchTimeRemaining() const
{
    ATPSGameMode* GameMode = Cast<ATPSGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        return GameMode->GetMatchDuration() - MatchElapsedTime;
    }
    return 0.0f;
}

float ATPSGameState::GetMatchElapsedTime() const
{
    return MatchElapsedTime;
}

void ATPSGameState::AddScore(AController* Scorer, int32 Points)
{
    if (Scorer)
    {
        int32& CurrentScore = PlayerScores.FindOrAdd(Scorer, 0);
        CurrentScore += Points;

        // 通知所有玩家分数更新
        OnRep_PlayerScores();
    }
}

int32 ATPSGameState::GetScore(AController* Player) const
{
    if (Player && PlayerScores.Contains(Player))
    {
        return PlayerScores[Player];
    }
    return 0;
}
