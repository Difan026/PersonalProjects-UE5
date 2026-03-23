// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConsumableItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UConsumableItemInterface : public UInterface//接口类，U接口，不需要操作
{
	GENERATED_BODY()
};

/**
 * 
 */
class ITEMSYSTEM_API IConsumableItemInterface//I接口
{
	GENERATED_BODY() 

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	//蓝图可调用，BlueprintImplementableEvent蓝图可实施事件（告诉ue该默认行为应该使用蓝图而非c++），
	//这里应该是蓝图原生事件BlueprintNativeEvent（告诉ue该默认行为应该使用c++实现）
	bool ConsumeItem(AActor*TargetActor);//判断制造消耗的角色
	
	
};
