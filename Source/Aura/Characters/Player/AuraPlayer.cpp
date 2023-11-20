// Copyright © 2023 MajorT. All rights reserved.


#include "AuraPlayer.h"


// Sets default values
AAuraPlayer::AAuraPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAuraPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuraPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAuraPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

