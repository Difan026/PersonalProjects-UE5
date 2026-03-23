
// Fill out your copyright notice in the Description page of Project Settings.
//生成世界Actor
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnedItemActor.generated.h"

class UItemInstance;

UCLASS()
class ITEMSYSTEM_API ASpawnedItemActor : public AActor
{
	GENERATED_BODY()

	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
    TObjectPtr<UStaticMeshComponent>ItemMeshComponent;//物品网格组件
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UItemInstance> ItemInstance ;//物品实例
	
	
public:
	// Sets default values for this actor's properties
	ASpawnedItemActor();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
    void InitializedSpawn(UItemInstance*InItemInstance);
	
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)//期望在蓝图实现中被重写
	void OnInitialized();
	

};
