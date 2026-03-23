#pragma once
#include "ItemGameplayInfo.generated.h"

USTRUCT(BlueprintType)
struct FItemGameplayInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GameplayInfo",meta=(ClampMin = 1))//确保最大堆叠尺寸始终为1
	int32 MaxStackSize = 1;//设置最大堆叠数量1，物品不设置大堆叠数量时可不用写，同时meta=(ClampMin=-1)
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GameplayInfo",meta=(ClampMin=0))
	float Weight = 1.0f;//设置默认重量为1；

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="GameplayInfo",meta=(ClampMin=0))
	float BaseValue = 0.0f;//默认基础价值为0；
	
	//UPROPERTY(EditAnywhere,blueprintReadWrite,Category="GameplayInfo",meta=(ClampMin=0))
	//int32 MaxNeedSize = 30;//设置最大需求数量多少
	
    //根据需求可继续拓展
	
	
	
	
	
};
