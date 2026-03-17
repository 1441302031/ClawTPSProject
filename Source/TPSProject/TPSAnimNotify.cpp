// Copyright 2026 YourCompany. All rights reserved.

#include "TPSAnimNotify.h"
#include "TPSCharacter.h"
#include "TPSWeaponComponent.h"

UTPSAnimNotify_Reload::UTPSAnimNotify_Reload()
{
    bStartReload = true;
}

void UTPSAnimNotify_Reload::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::Notify(MeshComp, Animation, EventReference);

    if (MeshComp && MeshComp->GetOwner())
    {
        ATPSCharacter* Character = Cast<ATPSCharacter>(MeshComp->GetOwner());
        if (Character)
        {
            UTPSWeaponComponent* WeaponComponent = Character->GetWeaponComponent();
            if (WeaponComponent)
            {
                if (bStartReload)
                {
                    WeaponComponent->Reload();
                }
                else
                {
                    // 结束装弹动画
                }
            }
        }
    }
}
