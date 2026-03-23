// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"
#include "Effects/ConsumableItemEffect.h"
#include "ConsumableItemDefinition.generated.h"

/**
 * 
 */
UCLASS()
class ITEMSYSTEM_API UConsumableItemDefinition : public UItemDefinition
{
	GENERATED_BODY()
	
public:
	//消耗品定义函数
	UConsumableItemDefinition();
	//消耗品消耗时触发的效果数组
public:
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Instanced)//意味着创建UConsumableItemEffect实例时，会被存储在OnConsumeEffects数组
	TArray<TObjectPtr<UConsumableItemEffect>>OnConsumeEffects;

	
};
