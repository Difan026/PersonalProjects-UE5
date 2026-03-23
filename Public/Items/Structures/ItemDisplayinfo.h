#pragma once

#include "ItemDisplayinfo.generated.h"//必要的

class ASpawnedItemActor;

USTRUCT(BlueprintType)//USTRUCT 宏，ue特有机制，告诉ue生成一个可在引擎内部使用的结构体，让ue能够识别创建的不同的类和结构体等等
                      //设置blueprintType，使这个结构体在ue中暴露出来，作为蓝图的可用变量
struct FItemDisplayinfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display")//用于ue的宏 (随处可编辑，蓝图读写，分类为“显示”）
	FText Name;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display",meta=(Multiline))//为F文本描述创建一个多行字段
	FText Description;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display")
	TSoftObjectPtr<UTexture2D> IconSoftPtr = nullptr;//图标软指针
	//TSoftObjectPtr，T对象软指针指向图标在编辑器文件夹结构的路径位置，避免加载时同时加载所有图标，造成资源浪费
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display")
	TSoftObjectPtr<UStaticMesh> WorldMeshSoftPtr = nullptr;//加载静态网格体
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Display")
	TSubclassOf<ASpawnedItemActor> OverrideWorldDropClass = nullptr;//命名为重写世界掉落类
	//重写世界掉落类,例如用具体的角色类重写覆盖默认生成的物品类
	
	
};

