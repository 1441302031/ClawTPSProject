// Copyright 2026 YourCompany. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "TPSAnimNotify.generated.h"

/**
 * 动画通知 - 装弹
 */
UCLASS(meta = (DisplayName = "TPS Reload"))
class TPSPROJECT_API UTPSAnimNotify_Reload : public UAnimNotify
{
    GENERATED_BODY()

public:
    UTPSAnimNotify_Reload();

    virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify")
    bool bStartReload;
};
