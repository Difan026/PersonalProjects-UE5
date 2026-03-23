// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(logItemSystem,Log,All);//(日志名称，程度（log，warning，error..),所有级别对这个日志类别可用)

/**
*Log
这是该类别的默认日志级别。当你在代码中不指定级别时，或者用于某些筛选时，这个级别会被用作默认值。常见的级别有：

Fatal（致命错误，通常导致程序退出）

Error（错误）

Warning（警告）

Display（常规信息）

Log（同 Display，但更常用于非用户界面日志）

Verbose（详细）

VeryVerbose（非常详细）
 */


