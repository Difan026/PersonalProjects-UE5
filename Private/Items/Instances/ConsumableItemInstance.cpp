// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Instances/ConsumableItemInstance.h"

#include "Items/ItemSystemLogging.h"
#include "Items/Assets/ConsumableItemDefinition.h"
#include "Items/Assets/Effects/ConsumableItemEffect.h"
#include "Kismet/GameplayStatics.h"
//定义消耗物品实现
bool UConsumableItemInstance::ConsumeItem_Implementation(AActor* TargetActor)
{
       if (StackCount<=0)//堆叠数量小于或等于0
       {
       	UE_LOGFMT(logItemSystem,Error,"堆叠数量小于或等于0");
       	   return false;
       }
	   if (!TargetActor)//制造消耗对象是否有效
	   {
	   	UE_LOGFMT(logItemSystem,Error,"制造消耗对象无效");
		   return false;
	   }
	UConsumableItemDefinition*ConsumableItemDefinition = Cast<UConsumableItemDefinition>(ItemDefinition);
	//获取物品定义并尝试投射
	if (!ConsumableItemDefinition)
	   {
		UE_LOGFMT(logItemSystem,Error,"消耗品定义无效");	
		return false;
	   }
       for (auto ConsumableItemEffect : ConsumableItemDefinition->OnConsumeEffects)
       	//遍历数组中存储的每一个消耗效果 
       {
	       if (!ConsumableItemEffect)
	       {
		       continue;
	       }
       	   
       	   ConsumableItemEffect->ApplyConsumeEffect(TargetActor,this);
          	   //将实例传给消耗品效果应用函数
	       if (ConsumableItemEffect->OnConsumeSoundEffect)//消耗品消耗触发的音效有效时
	       {
		       UGameplayStatics::PlaySound2D(TargetActor,ConsumableItemEffect->OnConsumeSoundEffect);
	       	//调用 UGameplayStatics的PlaySound2D函数，传入目标演员和目标消耗音效
	       }
       }
	
	return true;
}


	