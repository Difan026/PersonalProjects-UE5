#pragma once
#include "StructUtils/InstancedStruct.h"


#include "ItemInstanceSaveData.generated.h"

USTRUCT(BlueprintType,Blueprintable)//蓝图类型，可蓝图化
struct FItemInstanceSaveData
{
	GENERATED_BODY()
	
	//需要保存的物品信息：
	UPROPERTY(EditAnywhere,BlueprintReadWrite,SaveGame,Category="Definition")
	FPrimaryAssetId ItemDefinitionId;//物品定义
	//得到物品数据资产文件
	UPROPERTY(EditAnywhere, BlueprintReadWrite,SaveGame,Category="Gameplay")//物品的游戏属性
	int32 StackCount;//	设置堆叠数量，表示物品实际存在数量
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,SaveGame,Category="Item Data")
	FInstancedStruct CustomItemData;//设置每一个物品都保有以上两个物品属性
};
