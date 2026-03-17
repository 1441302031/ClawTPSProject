// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TPSGameplayTypes.generated.h"

/**
 * 游戏模式类型
 */
UENUM(BlueprintType)
enum class ETPSGameModeType : uint8
{
    SinglePlayer        UMETA(DisplayName = "Single Player"),
    TeamDeathmatch      UMETA(DisplayName = "Team Deathmatch"),
    FreeForAll          UMETA(DisplayName = "Free For All"),
    CaptureTheFlag      UMETA(DisplayName = "Capture The Flag"),
    Custom              UMETA(DisplayName = "Custom")
};

/**
 * 队伍类型
 */
UENUM(BlueprintType)
enum class ETPSTeam : uint8
{
    None                UMETA(DisplayName = "None"),
    Team1               UMETA(DisplayName = "Team 1"),
    Team2               UMETA(DisplayName = "Team 2"),
    Spectator           UMETA(DisplayName = "Spectator")
};

/**
 * 伤害类型
 */
UENUM(BlueprintType)
enum class ETPSDamageType : uint8
{
    Normal              UMETA(DisplayName = "Normal"),
    Headshot            UMETA(DisplayName = "Headshot"),
    Explosive           UMETA(DisplayName = "Explosive"),
    Melee               UMETA(DisplayName = "Melee"),
    Environmental       UMETA(DisplayName = "Environmental"),
    DoT                 UMETA(DisplayName = "Damage over Time")
};

/**
 * 角色状态
 */
UENUM(BlueprintType)
enum class ETPSCharacterState : uint8
{
    Idle                UMETA(DisplayName = "Idle"),
    Walking             UMETA(DisplayName = "Walking"),
    Running             UMETA(DisplayName = "Running"),
    Sprinting           UMETA(DisplayName = "Sprinting"),
    Crouching           UMETA(DisplayName = "Crouching"),
    Aiming              UMETA(DisplayName = "Aiming"),
    Firing              UMETA(DisplayName = "Firing"),
    Reloading           UMETA(DisplayName = "Reloading"),
    Melee               UMETA(DisplayName = "Melee"),
    Interacting         UMETA(DisplayName = "Interacting"),
    Dead                UMETA(DisplayName = "Dead")
};

/**
 * 游戏阶段
 */
UENUM(BlueprintType)
enum class ETPSGamePhase : uint8
{
    NotStarted          UMETA(DisplayName = "Not Started"),
    Warmup              UMETA(DisplayName = "Warmup"),
    InProgress          UMETA(DisplayName = "In Progress"),
    RoundEnd            UMETA(DisplayName = "Round End"),
    MatchEnd            UMETA(DisplayName = "Match End")
};
