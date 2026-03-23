// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ItemSystemSettings.generated.h"

class ASpawnedItemActor;
/**
 * 
 */
UCLASS(Config="game",DefaultConfig,meta=(DisplayName="物品系统设置"))
//在游戏菜单下创建一个名为物品系统设置的新菜单页
class ITEMSYSTEM_API UItemSystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(Config,EditAnywhere,BlueprintReadOnly,Category="Item Drop")
	TSubclassOf<ASpawnedItemActor> DefaultSpawnItemActorClass;

};

