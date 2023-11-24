// Copyright © 2023 MajorT. All rights reserved.


#include "AuraPlayer.h"

#include "Aura/AbilitySystem/Component/AuraAbilitySystemComponent.h"
#include "Aura/PlayerController/AuraPlayerController.h"
#include "Aura/PlayerStates/AuraPlayerState.h"
#include "Aura/UserInterface/HUD/AuraHUD.h"
#include "GameFramework/CharacterMovementComponent.h"


void AAuraPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Initialize ASC on the Server. This isn't called on the Client.
	InitAbilityActorInfo();
}

void AAuraPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Initialize ASC on the Server. This is called on the Client when the PlayerState is replicated.
	InitAbilityActorInfo();
}

void AAuraPlayer::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
	
	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}

// Sets default values

AAuraPlayer::AAuraPlayer()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}