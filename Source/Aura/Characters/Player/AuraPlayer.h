// Copyright © 2023 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Aura/Characters/AuraCharacterBase.h"
#include "AuraPlayer.generated.h"

UCLASS()
class AURA_API AAuraPlayer : public AAuraCharacterBase
{
	GENERATED_BODY()

protected:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Combat Interface
	virtual int32 GetPlayerLevel() override;
	
public:
	// Sets default values for this character's properties
	AAuraPlayer();

private:
	virtual void InitAbilityActorInfo() override;
};
