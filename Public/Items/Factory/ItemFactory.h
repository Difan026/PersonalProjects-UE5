// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Instances/ConsumableItemInstance.h"
#include "Items/Instances/ItemInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemFactory.generated.h"

class ASpawnedItemActor;
class UConsumableItemDefinition;
class UEquippableItemDefinition;
class UEquippableItemInstance;
class UItemInstance;

/**
 * 
 */

UCLASS()
class ITEMSYSTEM_API UItemFactory : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()  
	
public:
	
	UFUNCTION(BlueprintCallable,Category = "Item Creation",meta=(WorldContext = "WorldContextObject"))//告诉蓝图节点，这里传入的UObject是我们的世界上下文或一个uWorld或uObject实例
	static UItemInstance* CreateItemFromItemDefinition(UObject* WorldContextObject,UItemDefinition* Definition,int32 Quantity = 1);
	//根据世界上下文和物品定义创建物品实例（数量Quantity）
	//创建一个需要世界下上下文对象（能够引用当前游戏世界对象的 对象函数）
	UFUNCTION(BlueprintCallable,Category = "Item Creation",meta=(WorldContext = "WorldContextObject"))//告诉蓝图节点，这里传入的UObject是我们的世界上下文或一个uWorld或uObject实例
    static ASpawnedItemActor* SpawnItemInWorld(UObject* WorldContextObject,UItemInstance*InItemInstance,FVector SpawnLocation,FRotator SpawnRotation);
	private:
	static   UEquippableItemInstance*CreateEquippableItem(UObject* WorldContextObject,UEquippableItemDefinition*EquippableItemDefinition,int32 Quantity);
	
	

	static    UConsumableItemInstance*CreateConsumableItem(UObject* WorldContextObject,UConsumableItemDefinition*ConsumableItemDefinition,int32 Quantity);
	
	 
};
