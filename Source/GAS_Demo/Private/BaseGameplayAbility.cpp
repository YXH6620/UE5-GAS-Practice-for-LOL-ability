// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayAbility.h"

FGameplayAbilityInfo::FGameplayAbilityInfo()
	:CD(0), CostType(ECostType::MP), CostValue(0.0f), IconMaterial(nullptr), AbilityClass(nullptr)
{
	
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float CD, ECostType CostType, float CostValue,
	UMaterialInstance* MaterialInstance, TSubclassOf<UBaseGameplayAbility> AbilityClass)
	:CD(CD), CostType(CostType), CostValue(CostValue), IconMaterial(MaterialInstance), AbilityClass(AbilityClass)
{
	
}

FGameplayAbilityInfo UBaseGameplayAbility::GetAbilityInfo(int level)
{
	UGameplayEffect* CDEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();
	float CD = 0;
	float CostValue = 0;
	ECostType CostType = ECostType::MP;
	if(CDEffect && CostEffect)
	{
		CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(level, CD);
		if(CostEffect->Modifiers.Num() > 0)
		{
			// 获取花费的是哪一个类型
			FGameplayModifierInfo CostEffectModifierInfo = CostEffect->Modifiers[0];
			CostEffectModifierInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(level, CostValue);
			FString CostTypeName = CostEffectModifierInfo.Attribute.AttributeName;
			
			if(CostTypeName == "HP")
			{
				CostType = ECostType::HP;
			}
			if(CostTypeName == "MP")
			{
				CostType = ECostType::MP;
			}
			if(CostTypeName == "Strength")
			{
				CostType = ECostType::Strength;
			}
			return FGameplayAbilityInfo(CD, CostType, CostValue, IconMaterial, GetClass());
		}
	}
	
	return FGameplayAbilityInfo();
}
