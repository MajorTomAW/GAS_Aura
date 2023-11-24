// Copyright © 2023 MajorT. All rights reserved.


#include "AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& InParams)
{
	PlayerController = InParams.PlayerController;
	PlayerState = InParams.PlayerState;
	AbilitySystemComponent = InParams.AbilitySystemComponent;
	AttributeSet = InParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	// Override this function in child classes
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	// Override this function in child classes
}
