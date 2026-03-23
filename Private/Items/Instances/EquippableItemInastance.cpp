// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/ItemSystemLogging.h"
#include "Items/Assets/ItemDefinition.h"
#include "Items/Instances/EquippableItemInstance.h"
#include "Items/Structures/EquippableItemInstanceSaveData.h"


bool UEquippableItemInstance::InitializeItemFromSave(UItemDefinition* InItemDefinition,
	FItemInstanceSaveData InItemSaveData)
{
	if (!Super::InitializeItemFromSave(ItemDefinition, InItemSaveData))
	{
		return false;
	}
	const FEquippableItemInstanceSaveData*DataPtr = InItemSaveData.CustomItemData.GetPtr<FEquippableItemInstanceSaveData>();
	if (!DataPtr)
	{
		UE_LOGFMT(logItemSystem,Error,"Failed to get FEquippableItemInstanceSaveData from SaveData,cannot initialize item");
		return false;
	}
	//例：耐久=DataPtr->耐久；
	Attributes.Append(DataPtr->Attributes);//获取物品属性
	
	return true;
}

FItemInstanceSaveData UEquippableItemInstance::GetSaveData()
{
	FItemInstanceSaveData SaveData;
	SaveData.ItemDefinitionId = ItemDefinition->GetPrimaryAssetId();
	SaveData.StackCount = StackCount;
	
	FEquippableItemInstanceSaveData EquipSaveData;
	EquipSaveData.Attributes.Append(Attributes);//附加上物品属性
	SaveData.CustomItemData.InitializeAs<FEquippableItemInstanceSaveData>(EquipSaveData);
	
	return SaveData;
}

 float UEquippableItemInstance::GetAttributeValueByTag(FGameplayTag AttributeTag)
{
	
		if (Attributes.Contains(AttributeTag))//检查属性映射是否包含属性标签
		{
			return Attributes[AttributeTag];//返回对应属性标签的值
		}
		UE_LOGFMT(logItemSystem,Warning,"the attribute that you just find is not exist on this item.");
		return 0.0f;
	

}





