// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Instances/ItemInstance.h"

#include "Items/ItemSystemLogging.h"
#include "Items/Assets/ItemDefinition.h"
#include "String/FormatStringSan.h"
#include "String/FormatStringSan.h"


bool UItemInstance::InitializeItem(UItemDefinition* InItemDefinition, int32 InStackCount)
{
	
	if (!InItemDefinition)//检查传入对象是否有效或是被加载
	{
		UE_LOGFMT(logItemSystem,Error,"ItemDefinition is not valid.Can not initialize item.");
		return false;
	}//输出创建的日志logItemSystem，内容：定义无效且项目未初始化
	
	ItemDefinition = InItemDefinition;//物品定义设为等于我们输入的物品定义
	StackCount = FMath::Clamp(InStackCount,1,InItemDefinition->GameplayInfo.MaxStackSize);	
		//堆叠数量等于我们输入的堆叠数量（入栈数量）
	    UE_LOGFMT(logItemSystem,Log,"Item Successfully initialized{0}",ItemDefinition->DisplayInfo.Name.ToString());
	//输出创建成功信息，并给出物品定义的名称(从ItemDefinition的DisplayInfo结构体中获得，最后将FName 文本转换为字符串类型）
	return true;
}


bool UItemInstance::InitializeItemFromSave(UItemDefinition* InItemDefinition, FItemInstanceSaveData InItemSaveData)
{
	if (!InItemDefinition)//检查传入对象是否有效或是被加载
	{
		UE_LOGFMT(logItemSystem,Error,"ItemDefinition is not valid.Can not initialize item.");
		return false;
		
	}
	ItemDefinition = InItemDefinition;
	StackCount = InItemSaveData.StackCount;
	
	 
	return true;
}



bool UItemInstance::AddToStackCount(int32 AmountToAdd)//堆叠数增加函数定义
{
	if (!ItemDefinition)
	{
		UE_LOGFMT(logItemSystem,Error,"ItemDefinition is not valid.Can not add to stack count.");
		return false;
	}
	if (AmountToAdd <=0)
	{
		UE_LOGFMT(logItemSystem,Error,"AmountToAdd can not less or equal to 0.");
		return false;
	}
	if (AmountToAdd > ItemDefinition->GameplayInfo.MaxStackSize)
	{
		UE_LOGFMT(logItemSystem,Error,"AmountToAdd Can not more than the MaxStackSize of item .");
		return false;
	}
	
	const int32 OldStackCount = StackCount;//获取旧的堆栈数量：OldStackCount；
	StackCount += AmountToAdd;
	
	//Add event to show item stack count has changed:
	OnItemStackCountChanged.Broadcast(this,OldStackCount,StackCount );//获取.h文件中的广播事件，并创建广播.Broadcast;
	
	return true;
}

//第二种判断方式；
bool UItemInstance::RemoveFromStackCount(int32 AmountToRemove)//堆叠数减少函数定义
{
	if (!ItemDefinition)
	{
		UE_LOGFMT(logItemSystem,Error,"ItemDefinition is not valid.Can not remove from stack count.");
		return false;
	}
	if (AmountToRemove <=0 || 
		AmountToRemove > ItemDefinition->GameplayInfo.MaxStackSize || 
		AmountToRemove > StackCount)
		{
		UE_LOGFMT(logItemSystem,Error,"AmountToRemove error.");
		return false;
		}
	//无异常时
	const int32 OldStackCount = StackCount;//获取旧的堆栈数量：OldStackCount；
	StackCount -= AmountToRemove;//StackCount = StackCount - AmountToRemove;
	
	//Add Broadcast
	OnItemStackCountChanged.Broadcast(this,OldStackCount,StackCount );//物品减少时调用OnItemStackCountChanged广播事件
	if (StackCount <=0)
	{	
		OnItemStackDepleted.Broadcast(this );//物品耗尽时调用OnItemStackDepleted广播事件
	}
	
	return true;
}


FItemInstanceSaveData UItemInstance::GetSaveData()
{
	FItemInstanceSaveData SaveData;
	SaveData.ItemDefinitionId = ItemDefinition->GetPrimaryAssetId();//将SaveData设为主数据，获取物品数据资产
	SaveData.StackCount = StackCount;
	return SaveData;
}//实现获取必要物品保存的资产信息函数


FItemDisplayinfo UItemInstance::GetItemDisplayInfo() const
{
	if (ItemDefinition)
	{
		return ItemDefinition->DisplayInfo;//有效则返回ItemDefinition的DisplayInfo结构体信息
	}
	return FItemDisplayinfo();//定义无效则得到一个默认版本
}

FGameplayTag UItemInstance::GetItemType() const
{
	if (ItemDefinition)
	{
		return ItemDefinition->ItemTypeTag;
	}
	return FGameplayTag();//定义无效则得到一个默认版本
	
}

FGameplayTag UItemInstance::GetItemRarity() const
{
	if (ItemDefinition)
	{
		return  ItemDefinition->ItemRarityTag;
	}
	return FGameplayTag();
}

FItemGameplayInfo UItemInstance::GetGameplayInfo() const
{
	if (ItemDefinition)
	{
		return ItemDefinition->GameplayInfo;
	}
	return FItemGameplayInfo();
}

FGameplayTag UItemInstance::GetItemValue() const
{
	
	if (!ItemDefinition)
	{
		return ItemDefinition->ItemValueTag; 
	}
	return FGameplayTag();
}
	
	

