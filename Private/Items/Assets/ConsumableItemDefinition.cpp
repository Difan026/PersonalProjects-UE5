// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Assets/ConsumableItemDefinition.h"

UConsumableItemDefinition::UConsumableItemDefinition()
{
	ItemTypeTag = TAG_Item_Type_Consumable;
	GameplayInfo.MaxStackSize = 1;//每次创建可消耗物品时，最大堆叠数量设为一
}
