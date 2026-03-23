// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Structures/ItemInstanceSaveData.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CreateItemFromSaveAsync.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCreatedSuccess, UItemInstance*,Item);//单参数委托广播
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemCreatedFailure);//失败则直接广播 

/** 
 * 
 */
UCLASS()
class ITEMSYSTEM_API UCreateItemFromSaveAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintAssignable)
	FOnItemCreatedSuccess OnItemCreatedSuccess;//调用成功广播委托
	
	UPROPERTY(BlueprintAssignable)
	FOnItemCreatedFailure OnItemCreatedFailure;//调用失败广播委托，OnItemCreatedFailure为参数名称
	
public:
	UFUNCTION(BlueprintCallable,meta=(WorldContext = "WorldContextObject",BlueprintInternalUseOnly="true"),//仅蓝图内部可用
	DisplayName="Create Item From Save",Category="Item Factory")//宏后不需要“;”
	static UCreateItemFromSaveAsync*CreateItemFromSaveAsync(UObject*WorldContextObject,const FItemInstanceSaveData& SaveData);//常量引用保存数据

   virtual void Activate() override;//AsyncActionBase内置函数
	
private:
	
	UPROPERTY()
	UObject* WorldContextObject;
	FItemInstanceSaveData SaveData;
	
private:
	
	UFUNCTION()
	void HandleAssetLoaded();//处理资源加载
	

};
