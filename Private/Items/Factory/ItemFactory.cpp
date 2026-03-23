// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Factory/ItemFactory.h"


#include "ItemSystem.h"
#include "Items/ItemSystemLogging.h"
#include "Items/ItemSystemSettings.h"
#include "Items/SpawnedItemActor.h"
#include "Items/Assets/ConsumableItemDefinition.h"
#include "Items/Assets/EquippableItemDefinition.h"
#include "Items/Assets/ItemDefinition.h"
#include "Items/Instances/ConsumableItemInstance.h"
#include "Items/Instances/EquippableItemInstance.h"
#include "Logging/StructuredLog.h"
//数据区顶的物品工厂 
UItemInstance* UItemFactory::CreateItemFromItemDefinition(UObject* WorldContextObject,UItemDefinition* Definition,
                                                          int32 Quantity)
{
	
	if(!WorldContextObject)
	{
		UE_LOGFMT(logItemSystem,Error,"World Context is not valid,can not create item");
		return nullptr;
	}//检查世界上下文
	
	if(!Definition)
	{
		UE_LOGFMT(logItemSystem,Error,"Definition is not valid,can not create item");
		return nullptr;
	}//检查物品定义
	
	const int32 FinalQuantity = FMath::Clamp(Quantity,1,Definition->GameplayInfo.MaxStackSize);
	
	UItemInstance* NewItem = nullptr;

	if (Definition->ItemTypeTag.MatchesTagExact(TAG_Item_Type_Equippable))
	{
		if (UEquippableItemDefinition*EquippableItemDefinition = Cast<UEquippableItemDefinition>(Definition))//定义变量：最终数量，初始化项目创建的物品的指针NewItem
		{
			NewItem= CreateEquippableItem(WorldContextObject,EquippableItemDefinition,FinalQuantity);
		}
	} else if(Definition->ItemTypeTag.MatchesTagExact(TAG_Item_Type_Consumable))
	{
		
		NewItem=NewObject<UConsumableItemInstance>(WorldContextObject);
		if (!NewItem->InitializeItem(Definition,FinalQuantity))
		{
			return nullptr;  
		}//若成功创建新项目.继续初始化项目指针（传入定义和最终数量） 
	}
	
	
	//通过检查标签，选择创建不同游戏实例
	else
	{
		NewItem=NewObject<UItemInstance>(WorldContextObject);
		if (!NewItem->InitializeItem(Definition,FinalQuantity))
		{
			return nullptr;
		}//若成功创建新项目.继续初始化项目指针（传入定义和最终数量） 
		
	}
	
	//UItemInstance* NewItem = NewObject<UItemInstance>(WorldContextObject);//统一写法；
	//NewObject为ue内置功能，创建一个UItemInstance类型的uObject对象同时传入世界上下文WorldContextObject，这样就会在这个游戏世界里创建对象
	
	if(!NewItem)
	{
		UE_LOGFMT(logItemSystem,Error,"New Item Instance failed to create.");
		return nullptr;
	}//未成功则返回null
	  
	return NewItem;
}

ASpawnedItemActor* UItemFactory::SpawnItemInWorld(UObject* WorldContextObject, UItemInstance*InItemInstance, FVector SpawnLocation,
	FRotator SpawnRotation)
{
	if(!WorldContextObject)
	{
		UE_LOGFMT(logItemSystem,Error,"World Context is not valid,can not spawn item");
		return nullptr;
	}//检查世界上下文
	
	if(!InItemInstance)
	{
		UE_LOGFMT(logItemSystem,Error,"InItemInstance is not valid,can not create equippable item");
		return nullptr;
	}//检查物品定义
	UWorld* World=WorldContextObject->GetWorld();
	if(!World)
	{
		UE_LOGFMT(logItemSystem,Error,"World is not valid,can not create equippable item");
		return nullptr;
	}	
	
	const UItemSystemSettings* Settings=GetDefault<UItemSystemSettings>();
	if(!Settings)
	{
		UE_LOGFMT(logItemSystem,Error,"Item System settings is not valid.");
		return nullptr;
	}//检查物品系统设置
	
	
	//使用在ItemFactory系统默认设置，无需在每一个物品上单独设置
	TSubclassOf<ASpawnedItemActor>SpawnClass=//创建生成类
		(InItemInstance->ItemDefinition && InItemInstance->ItemDefinition->DisplayInfo.OverrideWorldDropClass)
	//检查物品实例的物品定义是否有效，若有效并且存在有效的覆盖掉落类（OverrideDropClass），那么把生成类（DefaultSpawnItemActorClass）设置为该掉落类 
	?InItemInstance->ItemDefinition->DisplayInfo.OverrideWorldDropClass: Settings->DefaultSpawnItemActorClass;
	
	
	if (!SpawnClass)
	{ 
		UE_LOGFMT(logItemSystem,Error,"SpawnClass is not valid.");
		return nullptr;
	}//判断生成的物品角色是否有效	 
	
	
	FActorSpawnParameters SpawnParameters;//调用spawn Actor函数必须传入的参数
	ASpawnedItemActor* SpawnedItemActor = World->SpawnActor<ASpawnedItemActor>(SpawnClass,SpawnLocation,SpawnRotation,SpawnParameters);   
	//函数接收一个生成类，一个生成位置，一个生成角色角度，一个生成角色参数
	if (!SpawnedItemActor)  
	{		 
		UE_LOGFMT(logItemSystem,Error,"SpawnedItemActor is not valid.");
		return nullptr;
	}//判断生成的物品角色是否有效
	
	SpawnedItemActor->InitializedSpawn(InItemInstance);
	return SpawnedItemActor;//返回生成角色;
	//繁琐详细的日志有助于在项目后期的调试
	
	
}


//基础的工厂函数，CreateItemfromItemDefinition                           
UEquippableItemInstance* UItemFactory::CreateEquippableItem(UObject* WorldContextObject,
	UEquippableItemDefinition* EquippableItemDefinition, int32 Quantity)//创建可装备物品实例
{
	if(!WorldContextObject)
	{
		UE_LOGFMT(logItemSystem,Error,"World Context is not valid,can not create equippable item");
		return nullptr;
	}//检查世界上下文
	
	if(!EquippableItemDefinition)
	{
		UE_LOGFMT(logItemSystem,Error,"EquippableItemDefinition is not valid,can not create equippable item");
		return nullptr;
	}//检查物品定义
	
	UEquippableItemInstance* NewItem = nullptr;
	NewItem=NewObject<UEquippableItemInstance>(WorldContextObject);
	
	
	if(!NewItem)
	{
		UE_LOGFMT(logItemSystem,Error,"equippable item failed to create.");
		return nullptr;
	}
	if (!NewItem->InitializeItem(EquippableItemDefinition,Quantity))
	{
		UE_LOGFMT(logItemSystem,Error,"equippable item failed to initalize.");
		return nullptr;
	}//若成功创建新项目.继续初始化项目指针（传入定义和最终数量） 
	

    //初始化成功后执行for循环，返回新建物品
	for (auto BaseAttributePair : EquippableItemDefinition->BaseAttributes)//foreach循环
	{
		float FinalAttributeValue=0.0f;
		if (BaseAttributePair.Value.UseValueRange)
		{
			FinalAttributeValue = FMath::RandRange(BaseAttributePair.Value.MinValue,BaseAttributePair.Value.MaxValue);
			FinalAttributeValue =FMath::RoundToInt(FinalAttributeValue);//将最终属性值强制转换为整数（可选）
		}//若生成则属性值在最大值和最小值之间生成一个随机数
		else
		{
			FinalAttributeValue=BaseAttributePair.Value.MaxValue;
		}//若错误，则将最终属性值设为基本属性值，可用于默认情况下
		
		//完成后将其加入到映射表中，利用Ateributes.Add()//于EquippableItemInstance.h中定义
		 NewItem->Attributes.Add(BaseAttributePair.Key,FinalAttributeValue);
	}	
	
	return NewItem;
}




//创建可消耗物品的工厂函数
UConsumableItemInstance* UItemFactory::CreateConsumableItem(UObject* WorldContextObject,
	UConsumableItemDefinition* ConsumableItemDefinition, int32 Quantity)//创建可消耗物品实例
{
	if(!WorldContextObject)
	{
		UE_LOGFMT(logItemSystem,Error,"World Context is not valid,can not create equippable item");
		return nullptr;
	}//检查世界上下文
	
	if(!ConsumableItemDefinition)
	{
		UE_LOGFMT(logItemSystem,Error,"EquippableItemDefinition is not valid,can not create equippable item");
		return nullptr;
	}//检查物品定义
	
	UConsumableItemInstance* NewItem = nullptr;
	NewItem=NewObject<UConsumableItemInstance>(WorldContextObject);
	
	
	if(!NewItem)
	{
		UE_LOGFMT(logItemSystem,Error,"Consumable item failed to create.");
		return nullptr;
	}
	if (!NewItem->InitializeItem(ConsumableItemDefinition,Quantity))
	{
		UE_LOGFMT(logItemSystem,Error,"Consumable item failed to initalize.");
		return nullptr;
	}//若成功创建新项目.继续初始化项目指针（传入定义和最终数量） 
	

	return NewItem;
}
