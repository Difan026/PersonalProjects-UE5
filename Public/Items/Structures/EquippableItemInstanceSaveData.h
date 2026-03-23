#pragma once
#include "GameplayTagContainer.h"
#include "EquippableItemInstanceSaveData.generated.h"


USTRUCT(Blueprintable,Blueprintable)
struct FEquippableItemInstanceSaveData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Equippable Item")
	TMap<FGameplayTag,float>Attributes;
};
