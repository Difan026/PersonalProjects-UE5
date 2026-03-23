// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Factory/CreateItemFromSaveAsync.h"

#include "Engine/AssetManager.h"
#include "Items/ItemSystemLogging.h"
#include "Items/Assets/ItemDefinition.h"
#include "Items/Factory/ItemFactory.h"

UCreateItemFromSaveAsync* UCreateItemFromSaveAsync::CreateItemFromSaveAsync(UObject* WorldContextObject,
                                                                            const FItemInstanceSaveData& SaveData)
{
	UCreateItemFromSaveAsync* Node = NewObject<UCreateItemFromSaveAsync>();
	Node->WorldContextObject = WorldContextObject;
	Node->SaveData = SaveData;
	return Node;
}

void UCreateItemFromSaveAsync::Activate()
{
	UAssetManager::Get().LoadPrimaryAsset(SaveData.ItemDefinitionId,TArray<FName>(),
		FStreamableDelegate::CreateUObject(this,&UCreateItemFromSaveAsync::HandleAssetLoaded));//UE内置资源管理器
	 
	
}

void UCreateItemFromSaveAsync::HandleAssetLoaded()
{
	UObject*LoadAsset=UAssetManager::Get().GetPrimaryAssetObject(SaveData.ItemDefinitionId);
	//获取已加载的资源 ，存储在通用的UObject.Pointer(LoadAsset)
	if (!LoadAsset)
	{
		UE_LOGFMT(logItemSystem,Error,"LoadAsset is invalid，Asset is failed to load.");
		OnItemCreatedFailure.Broadcast();//调用头文件创建的失败委托广播
		return ;
	}
	
	UItemDefinition*ItemDefinition = Cast<UItemDefinition>(LoadAsset);//将类型转换为UItemDefinition
	if (!ItemDefinition)
	{
		UE_LOGFMT(logItemSystem,Error,"ItemDefinition is  invalid，Asset is failed to load.");
		OnItemCreatedFailure.Broadcast();
		return ;
	}
	
	UItemInstance* Item = UItemFactory::CreateItemFromItemDefinition(WorldContextObject,ItemDefinition,SaveData.StackCount);
	if (!Item)
	{
		UE_LOGFMT(logItemSystem,Error,"Item is  invalid，Asset is failed to load.");
		OnItemCreatedFailure.Broadcast();
		return ;
	}
	if (!Item->InitializeItemFromSave(ItemDefinition,SaveData))
	{
		UE_LOGFMT(logItemSystem,Error,"Item is  invalid，Asset is failed to load.");
		OnItemCreatedFailure.Broadcast();
		return ;
	} 
	
	
	UE_LOGFMT(logItemSystem,Log,"Item is loaded successfully.");
	OnItemCreatedSuccess.Broadcast(Item);
	
}
