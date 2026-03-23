// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDefinition.h"
#include "EquippableItemDefinition.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentSlotAttributeRange 
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(ClampMin=0))
	float MaxValue = 1.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(EditCondition="UseValueRange",EditConditionHides,ClampMin=0))
	float MinValue = 0.0f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool UseValueRange=false;
	//如果UseValueRange被设置为false，则元元素被隐藏EditConditionHides，若为true，则需设置最大最小值
	
};



/**
 * 游戏内所有可装备物品的基础定义 
 */
UCLASS()
class ITEMSYSTEM_API UEquippableItemDefinition : public UItemDefinition//继承类
{
	GENERATED_BODY()
	
public:
	UEquippableItemDefinition();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item|Slot",meta=(GameplayTagFilter="Item.equipmentSlot"))
	//分类为物品槽,创建标签
	//在编辑器中选择标签时，该过滤器会限制显示的标签列表，只显示以 "Item.equipmentSlot" 开头或属于该命名空间下的标签。
	FGameplayTag EquipmentSlotTag;

	//为装备设置额外属性，like:Health,energy,Stamina（耐力）...
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item|Attributes",meta=(GameplayTagFilter="Item.Attributes"))//分类为物品属性
	TMap<FGameplayTag,FEquipmentSlotAttributeRange> BaseAttributes;//建立映射，包含一个键和一个值，且键必须唯一
	//目的是为了每一个放入这个映射的标签都能访问EquipmentSlotAttributeRange这个结构体
	
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item|Value",meta=(GameplayTagFilter="Item.Value"))//分类为物品属性
	TMap<FGameplayTag,FItemValue> ItemValue;
	
	
	//Category 帮助整理大量属性，提升编辑器界面的可读性。
    //meta 提供了更细粒度的编辑控制，避免人为错误，同时让自定义数据类型的编辑器行为更加智能。
	
};
