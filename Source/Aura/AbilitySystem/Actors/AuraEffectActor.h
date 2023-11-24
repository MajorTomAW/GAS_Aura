// Copyright © 2023 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAuraEffectActor();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* InTarget, TSubclassOf<UGameplayEffect> InGameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnTargetOverlap(AActor* InTargetActor);

	UFUNCTION(BlueprintCallable)
	void OnTargetEndOverlap(AActor* InTargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects")
	bool bDestroyOnEffectRemoval = false;

	/** Application policies */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Instant")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Duration")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Infinte")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	/** Removal policies */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Infinte")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::DoNotRemove;

	/** Gameplay effect classes */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Instant")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Duration")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects|Infinte")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|AppliedEffects")
	float ActorLevel = 1.f;

};
