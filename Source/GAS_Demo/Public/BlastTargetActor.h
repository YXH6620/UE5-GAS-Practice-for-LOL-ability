// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "Abilities/GameplayAbility.h"
#include "BlastTargetActor.generated.h"

/**
 * 
 */
UCLASS()
class GAS_DEMO_API ABlastTargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	virtual void StartTargeting(UGameplayAbility* Ability) override;
	virtual void ConfirmTargetingAndContinue() override;

	UFUNCTION(BlueprintCallable, Category = "BlastSelect")
	bool GetPlayerLookAtPoint(FVector& Out_LookPoint);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = "BlastSelect")
	float SelectRadius;
};
