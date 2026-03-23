// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "NativeGameplayTags.h"//使用宏：UE_DECLARE_GAMEPLAY_TAG_EXTERN前提

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item)
//物品类型
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Type);//作用：声明物品标签名称(可更改)：TAG_Item_Type
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Type_Basic);//基础型
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Type_Equippable);//可装备型
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Type_Consumable);//可消耗型

//物品稀有度
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity); //稀有度
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity_Common);//普通
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity_Rare);//稀有
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity_Uncommon);//罕见
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity_Epic);//史诗
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Rarity_Legendary)//传奇

//物品装备槽
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_EquipmentSlot);//装备
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_EquipmentSlot_Head);//头部
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_EquipmentSlot_Chest);//胸部
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_EquipmentSlot_Feet);//脚部

//物品属性
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Attributes);//属性
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Attributes_Health);//生命
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Attributes_Energy);//能量
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Attributes_Special);//特殊属性
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Attributes_Stamina);//耐力

//物品价值
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Value);//物品价值
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Value_NoVlaue);//无价值
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Value_Valuable);//有价值