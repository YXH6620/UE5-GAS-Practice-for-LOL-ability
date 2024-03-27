// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "Abilities/GameplayAbility.h"
#include "FireAroundTargetActor.generated.h"

/**
 * 
 */
UCLASS()
class GAS_DEMO_API AFireAroundTargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	virtual void StartTargeting(UGameplayAbility* Ability) override;
	virtual void ConfirmTargetingAndContinue() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "BlastSelect")
	float FireAroundRadius;
};
