// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ConsumableItemEffect.generated.h"

class UConsumableItemInstance;
/** 
 * 
 */
UCLASS(Abstract,Blueprintable,BlueprintType,EditInlineNew)
//EditInlineNew 说明符允许在蓝图或细节面板中直接创建该类的子对象，配合 Instanced 使用非常方便。
//标记为抽象类Abstract，意思为不能直接创建 类的实例
//EditInLine,允许我们在自定义内部能够创建具体的UConsumableItemEffect实例
class ITEMSYSTEM_API UConsumableItemEffect : public UObject
{
	GENERATED_BODY()
	
public:
	//特效的名称和描述，声效
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(MultLine))
	FText Description; 
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<USoundBase> OnConsumeSoundEffect;
	
public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)//蓝图原生事件,允许将函数暴露给蓝图系统,蓝图可调用
	bool ApplyConsumeEffect(AActor*TargetActor,UConsumableItemInstance*ConsumableItemInstance);//添加可消耗物品实例于消耗品应用函数
	
	
	
	
	
};

