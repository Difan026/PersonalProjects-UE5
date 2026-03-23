// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemInstance.h"
#include "Items/Interfaces/ConsumableItemInterface.h"
#include "ConsumableItemInstance.generated.h"

/**
 * 
 */
UCLASS()
class ITEMSYSTEM_API UConsumableItemInstance : public UItemInstance,public IConsumableItemInterface//引入创建的接口

{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	bool ConsumeItem_Implementation(AActor*TargetActor);//默认消耗物品实现行为
	
};
