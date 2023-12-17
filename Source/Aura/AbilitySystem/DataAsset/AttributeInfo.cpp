// Copyright © 2023 MajorT. All rights reserved.


#include "AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoFromTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributesInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(Tag))
		{
			return Info;
		}
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find attribute info for tag %s"), *Tag.ToString())
	}

	return FAuraAttributeInfo();
}
