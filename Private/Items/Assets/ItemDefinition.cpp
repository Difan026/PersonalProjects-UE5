// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Assets/ItemDefinition.h"

#include "Items/ItemSystemTags.h"
UItemDefinition::UItemDefinition()//设置物品默认标签
{
	ItemTypeTag = TAG_Item_Type_Basic;
	ItemRarityTag  = TAG_Item_Rarity_Common;
	ItemValueTag = TAG_Item_Value_Valuable;
}//将gameplay物品默认标签标签设置为基础，普通



FPrimaryAssetId UItemDefinition::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemTypeTag.GetTagName(),GetFName());//获取物品标签名，Fname返回数据资产ID
	//所得到主资产ID名称类似:Item.Type.basic：DA_TestItem,Item.Type.Equippable:DA_CopperSword
}
