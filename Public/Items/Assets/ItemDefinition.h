// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../ItemSystemTags.h"
#include "../../../../../../../../epic/Epic Games/UE_5.7/Engine/Source/Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "../Structures/ItemDisplayinfo.h"
#include "../Structures/ItemGameplayInfo.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "ItemDefinition.generated.h"

/**
 * 定义基础物品数据资产，defines base item data assets
 */

USTRUCT(BlueprintType)//设置物品价值范围
struct FItemValue//物品价值
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(ClampMin=0))
	float MaxValue =1.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(EditCondition="UseValueRange",EditConditionHides,ClampMin = 0))
	float MinValue =0.0f;                 
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool UseValueRange = false;
	//默认物品无价值
	
};


UCLASS(BlueprintType,Blueprintable)//蓝图类型，蓝图特性	 
class ITEMSYSTEM_API UItemDefinition : public UPrimaryDataAsset//继承UPrimaryDataAssets，利用ue自带主资产数据资源
{

	GENERATED_BODY()
	
public: 
	UItemDefinition();
	
	// items 名字，描述Description）
	//显示结构
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display")
	FItemDisplayinfo DisplayInfo;//创建U属性宏，告诉ue希望可以编辑整个结构体
	
	//Item.Type.Consumable.Food.Meet....，物品类型
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Classification",meta=(GameplayTagFilter="Item.Type"))
	FGameplayTag ItemTypeTag;
	
	//物品稀有度
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Classification",meta=(GameplayTagFilter="Item.Rarity"))
	FGameplayTag ItemRarityTag;//选择物品标签时，只能选择实际编码中可用的物品稀有度标签
	                           //meta=("Tag")编辑作为物品一部分的物品类型标签变量时，根据定义只能选择具有层次结构的玩法标签
	
	//物品价值,标记物品是否有价值
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Classification",meta=(GameplayTagFilter="Item.Value"))//过滤标签
	FGameplayTag ItemValueTag;//需要在Item.Definional.cpp中修改默认值
	
	//堆叠数量，物品相关权重，基础价值（结构体）
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gameplay Info")
	FItemGameplayInfo GameplayInfo;
	
	//物品元标签
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Meta")
	FGameplayTagContainer  MetaTags;//作用：通过元标签搜索物品栏
	
	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;//GetPrimaryAssetId继承自UPrimaryDataAssets类
	
	
	
	
	//可继续根据需求拓展
	
}; 

