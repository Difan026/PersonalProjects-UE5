// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/SpawnedItemActor.h"

#include "Items/ItemSystemLogging.h"

// Sets default values
ASpawnedItemActor::ASpawnedItemActor()
{
	PrimaryActorTick.bCanEverTick = true;
	ItemMeshComponent =  CreateDefaultSubobject<UStaticMeshComponent>("ItemMeshComponent");
}

// Called when the game starts or when spawned
void ASpawnedItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnedItemActor::InitializedSpawn(UItemInstance* InItemInstance)
{
	
	if (!InItemInstance)//检查不是则将其移除
	{
		UE_LOGFMT(logItemSystem,Error,"Item Instance is not valid.Cannot spawn item into the world");
		SetLifeSpan(.2f);//将actor生命周期设为0.2s,过后被垃圾回收
		return;
	}
	
	ItemInstance = InItemInstance;
	OnInitialized();
	
		
		
}



