// Fill out your copyright notice in the Description page of Project Settings.

#include"Items/ItemSystemTags.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_Item,"Item");
//Item Type
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Type,"Item.Type");//声明该标签名为Item.Type我们可以通过定义变量名：AG_Item_Type类型来使用它
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Type_Basic,"Item.Type.Basic");
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Type_Equippable,"Item.Type.Equippable");
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Type_Consumable,"Item.Type.Consumable");

//Item Rarity
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity,"Item.Rarity");//稀有度
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity_Common,"Item.Rarity.Common");//普通
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity_Rare,"Item.Rarity.Rare");//稀有
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity_Uncommon,"Item.Rarity.Uncommon");//罕见
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity_Epic,"Item.Rarity.Epic");//史诗
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Rarity_Legendary,"Item.Rarity.Legendary");//传奇
	
//物品装备槽
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_EquipmentSlot,"Item.EquipmentSlot");//装备
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_EquipmentSlot_Head,"Item.EquipmentSlot.Head");//头部
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_EquipmentSlot_Chest,"Item.EquipmentSlot.Chest");//胸部
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_EquipmentSlot_Feet,"Item.EquipmentSlot.Feet");//脚部

//物品属性
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Attributes,"Item.Attributes");//属性
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Attributes_Health,"Item.Attributes.Health");//生命
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Attributes_Energy,"Item.Attributes.Energy");//能量
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Attributes_Special,"Item.Attributes.Special");//特殊属性
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Attributes_Stamian,"Item.Attributes.Stamina");//耐力

//物品价值
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Value,"Item.Value");//	物品价值
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Value_NoValue,"Item.Value.NoValue");//无价值
UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Value_Valuable,"Item.Value.Valuable");//有价值