// Copyright © 2023 MajorT. All rights reserved.


#include "AuraHUD.h"

#include "Aura/UserInterface/UserWidgets/AuraUserWidget.h"
#include "Aura/UserInterface/WidgetController/Attributes/AttributeMenuWidgetController.h"
#include "Aura/UserInterface/WidgetController/Overlay/OverlayWidgetController.h"
#include "Blueprint/UserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& InParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(InParams);
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& InParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(InParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies();

		return AttributeMenuWidgetController;
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is nullptr, please set it in AuraHUD BP"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is nullptr, please set it in AuraHUD BP"));
	
	UUserWidget* Overlay = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Overlay);

	const FWidgetControllerParams Params(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(Params);
	
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
}
