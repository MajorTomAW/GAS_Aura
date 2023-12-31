// Copyright © 2023 MajorT. All rights reserved.


#include "TargetDataUnderMouse.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility, FName TaskInstanceName)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility, TaskInstanceName);
	
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHitResult;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, CursorHitResult);
	OnTargetDataReady.Broadcast(CursorHitResult.Location);
}
