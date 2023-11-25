// Copyright © 2023 MajorT. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Aura/Interfaces/Combat/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}
	
protected:
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Aura|Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Aura|Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	
	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass, float Level = 1.f) const;
	void InitDefaultAttributes() const;

	virtual void InitAbilityActorInfo();
};
