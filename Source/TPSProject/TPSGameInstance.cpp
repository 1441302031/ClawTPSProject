// Copyright 2026 YourCompany. All rights reserved.

#include "TPSGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UTPSGameInstance::Init()
{
    Super::Init();

    UE_LOG(LogTemp, Log, TEXT("TPSGameInstance Initialized"));

    // 初始化玩家数据
    PlayerLevel = 1;
    PlayerXP = 0;
    bIsInSession = false;

    // 加载玩家数据
    LoadPlayerData();
}

void UTPSGameInstance::Shutdown()
{
    // 保存玩家数据
    SavePlayerData();

    Super::Shutdown();

    UE_LOG(LogTemp, Log, TEXT("TPSGameInstance Shutdown"));
}

void UTPSGameInstance::CreateSession(int32 MaxPlayers)
{
    // TODO: 实现在线会话创建
    // 这里使用简化版本
    bIsInSession = true;
    UE_LOG(LogTemp, Log, TEXT("Session Created with MaxPlayers: %d"), MaxPlayers);
}

void UTPSGameInstance::JoinSession(int32 SessionIndex)
{
    // TODO: 实现加入会话逻辑
    bIsInSession = true;
    UE_LOG(LogTemp, Log, TEXT("Joined Session: %d"), SessionIndex);
}

void UTPSGameInstance::DestroySession()
{
    bIsInSession = false;
    UE_LOG(LogTemp, Log, TEXT("Session Destroyed"));
}

void UTPSGameInstance::SavePlayerData()
{
    // TODO: 实现数据持久化（保存到 SaveGame）
    UE_LOG(LogTemp, Log, TEXT("Player Data Saved"));
}

void UTPSGameInstance::LoadPlayerData()
{
    // TODO: 实现数据加载（从 SaveGame 读取）
    UE_LOG(LogTemp, Log, TEXT("Player Data Loaded"));
}
