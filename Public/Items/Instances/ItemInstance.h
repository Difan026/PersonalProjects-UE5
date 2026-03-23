// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/Structures/ItemGameplayInfo.h"
#include "Items/Structures/ItemInstanceSaveData.h"
#include "UObject/Object.h"
#include "ItemInstance.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnItemStackCountChangedDelegate,UItemInstance*,Item,int32,OldStackSize,int32,CurrentStackSize);
//ue自带宏，创建动态多播委托事件，响应广播的函数需附加三个要求的参数信息
//委托名为FOnStackCountChangedDelegate
//存储函数列表，每个函数都应该具有一个物品实例（item），两个int32型参数（OldStackSize，CurrentStackSize）;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemStackDepleted,UItemInstance*,Item);//需一个参数，Item,其堆叠数量为0时，播放广播



struct FItemDisplayinfo;
class UItemDefinition;
/**
 * 这是游戏中所有物品的基础实例 
 */
UCLASS(BlueprintType,Blueprintable)
class ITEMSYSTEM_API UItemInstance : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(editAnywhere, BlueprintReadWrite,Category="Item")
	TObjectPtr<UItemDefinition> ItemDefinition;
	//引用T对象指针，一种ue式的U物品定义星号写法（同Definition*)
	//使得ue反射系统和UPROPERTY宏能够在使用时追踪该指针，并确保其中的数据不会丢失或在未来被垃圾回收
	//将物品定义存储到物品实例中
	
	UPROPERTY(editAnywhere, BlueprintReadOnly,Category="Item|Gameplay")//标识这是一个属于物品的游戏属性
	int32 StackCount;//	设置堆叠数量，表示物品实际存在数量
	
	
	//Events事件
	UPROPERTY(BlueprintAssignable,Category="Item|Events")//定义为蓝图可分配，在蓝图内部，可以将函数等内容分配给这个委托
	FOnItemStackCountChangedDelegate OnItemStackCountChanged;//设置物品堆叠数量变化委托，物品堆叠数量变化时触发
	
	UPROPERTY(BlueprintAssignable,Category="Item|Events")
    FOnItemStackDepleted OnItemStackDepleted;
	

public:
	UFUNCTION(BlueprintCallable)//接收一个UItemDefinition指针作为参数，在ItemDefinition中调用它
	virtual bool InitializeItem(UItemDefinition* InItemDefinition,int32 InStackCount = 1);
	
	
	UFUNCTION(BlueprintCallable)
	virtual bool InitializeItemFromSave(UItemDefinition* InItemDefinition,FItemInstanceSaveData InItemSaveData);	
	
	
	
	//stack count helper function
	UFUNCTION(BlueprintCallable,Category="Item|Gameplay")
	virtual bool AddToStackCount(int32 AmountToAdd);//实现堆叠增加

	UFUNCTION(BlueprintCallable,Category="Item|Gameplay")
	virtual bool RemoveFromStackCount(int32 AmountToRemove);//实现堆叠减少
	
	UFUNCTION(BlueprintCallable,Category="Item|Save")
	virtual  FItemInstanceSaveData GetSaveData();//获取保存数据
	
	
	
	//helpers构造辅助函数
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="Item|Diaplay")
	//声明函数有蓝图特性的同时，设置为纯蓝图，意在告诉ue此函数执行速度快，不涉及大量计算
	FItemDisplayinfo GetItemDisplayInfo() const;//显示信息

	UFUNCTION(BlueprintCallable,BlueprintPure,Category="Item|Classification")
	FGameplayTag GetItemType() const;//类型
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="Item|Classification")
	FGameplayTag GetItemRarity() const;//稀有度
	
	UFUNCTION(BlueprintCallable,BlueprintPure,Category="Item|Gameplay")
	FItemGameplayInfo GetGameplayInfo() const;//玩法信息
	
	UFUNCTION(blueprintCallable,BlueprintPure,Category="Item|Classification")//声明获取物品价值函数
	FGameplayTag GetItemValue()  const;
	
	
	
	
};
