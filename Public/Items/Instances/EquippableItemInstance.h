// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemInstance.h"
#include "EquippableItemInstance.generated.h"

/**
 * 专为可装备物品设计的特殊实例，基于我们的物品实例
 */
UCLASS()
class ITEMSYSTEM_API UEquippableItemInstance : public UItemInstance//已经继承物品定义中的所有属性，只需编写特有属性
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag,float>Attributes;//属性由物品工厂确定，映射物品最终拥有的属性
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FGameplayTag,float>ItemValue;
public:
	virtual bool InitializeItemFromSave(UItemDefinition* ItemDefinition,FItemInstanceSaveData ItemSaveData)override;
	
	virtual FItemInstanceSaveData GetSaveData() override;
	
	UFUNCTION(blueprintCallable)
	 float GetAttributeValueByTag(FGameplayTag AttributeTag);//接收FGameplayTag属性标签作为参数
	

};


