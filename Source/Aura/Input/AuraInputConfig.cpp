// Copyright © 2023 MajorT. All rights reserved.


#include "AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FAuraInputAction& InputAction : AbilityInputActions)
	{
		if (InputAction.InputTag.MatchesTagExact(Tag) && InputAction.InputAction != nullptr)
		{
			return InputAction.InputAction;
		}
	}
	if (bLogNotFound) UE_LOG(LogTemp, Warning, TEXT("No InputAction found for Tag %s"), *Tag.ToString());
	return nullptr;
}
