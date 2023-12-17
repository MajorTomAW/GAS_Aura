// Copyright © 2023 MajorT. All rights reserved.


#include "AuraAbilitySystemLibrary.h"
#include "Aura/PlayerStates/AuraPlayerState.h"
#include "Aura/UserInterface/HUD/AuraHUD.h"
#include "Aura/UserInterface/WidgetController/AuraWidgetController.h"
#include "Kismet/GameplayStatics.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* HUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
			UAttributeSet* AS = PS->GetAttributeSet();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			const FWidgetControllerParams Params(PC, PS, ASC, AS);
			
			return HUD->GetOverlayWidgetController(Params);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UAuraAbilitySystemLibrary::GetOverlayWidgetController: HUD is not of type UAuraHUD!"));
			return nullptr;
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* HUD = Cast<AAuraHUD>(PC->GetHUD()))
		{
			AAuraPlayerState* PS = PC->GetPlayerState<AAuraPlayerState>();
			UAttributeSet* AS = PS->GetAttributeSet();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			const FWidgetControllerParams Params(PC, PS, ASC, AS);
			
			return HUD->GetAttributeMenuWidgetController(Params);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController: HUD is not of type UAuraHUD!"));
			return nullptr;
		}
	}
	return nullptr;
}
