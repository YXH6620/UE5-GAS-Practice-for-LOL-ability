// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h" // 5.3 AttributeSet需要加该头文件;在ASC下有AS的配表功能
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_DEMO_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData MP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxMP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMP);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxStrength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStrength);

	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
