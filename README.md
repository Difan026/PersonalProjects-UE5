# Difan026-PersonalProjects-UE
Personal repository
# UE5 核心物品系统与背包系统


 📖 项目简介

个人练习项目，一个基于 **Unreal Engine 5 C++** 开发的可扩展、数据驱动的物品系统与背包框架。系统实现了物品定义、实例化、装备、消耗、世界掉落及背包管理核心功能，采用“数据与表现分离”的设计模式，深度利用 UE 反射系统、GameplayTag 和资产管理器，提供高复用、易扩展的游戏内物品解决方案。



 ✨ 功能特性

数据驱动的物品定义  
  使用 `UItemDefinition` 数据资产存储物品静态属性（名称、图标、最大堆叠、类型标签等），支持派生定义类（装备、消耗品）。

动态物品实例 
  `UItemInstance` 运行时对象，持有当前数量、属性值（`TMap<FGameplayTag, float>`）及对定义资产的引用。

组合式消耗品效果  
  `UConsumableItemEffect` 基类，支持 `EditInlineNew` 在编辑器中组合多个效果（治疗、Buff、音效等），通过 `BlueprintNativeEvent` 实现 C++ 默认逻辑与蓝图扩展。

- 装备属性系统
  `FEquipmentSlotAttributeRange` 支持固定值或随机区间，配合 `EditCondition` 实现编辑器友好。装备定义可配置多属性，工厂在实例化时计算最终数值。

- 物品工厂（Factory）
  提供静态函数：  
  - `CreateItemFromItemDefinition`：根据定义和数量创建物品实例。  
  - `SpawnItemInWorld`：在世界中生成物品表现 Actor，支持自定义掉落类。

- 世界掉落表现
  `ASpawnedItemActor` 作为物品实体，绑定物品实例，支持拾取交互。

- GameplayTag 集成 
  原生标签管理（`DECLARE_NATIVE_GAMEPLAYTAG`），并在 `UPROPERTY` 中使用 `GameplayTagFilter` 限制标签选择，确保数据正确性。

- 编辑器体验优化  
  使用 `EditConditionHides`、`ClampMin` 等元数据，属性动态显示，减少配置错误。

- 资产管理器集成  
  重写 `GetPrimaryAssetId`，支持按类型异步加载和资源打包优化。

---
 🧱 系统架构

```
数据层（定义）                    逻辑层（实例）                    表现层（世界）
UItemDefinition                  UItemInstance                    ASpawnedItemActor
       ↑                                ↑
       | (继承)                          | (继承)
       |                                |
UEquippableItemDefinition         UEquippableItemInstance
UConsumableItemDefinition         UConsumableItemInstance

       ↓                                ↓
       └────────────── 工厂类 UItemFactory ──────────────┘
                         |
                         | (创建/生成)
                         ↓
                   背包系统（管理 TArray<UItemInstance*>）
```

- 工厂类 `UItemFactory`：作为创建入口，封装所有实例化和生成逻辑。
- 效果系统：独立子对象，通过 `Instanced` 数组组合，实现行为复用。

---
🔧 技术栈与依赖

- 引擎版本：Unreal Engine 5.7（向后兼容 5.0+）
- 语言：C++17，Unreal Header Tool
- 核心模块：
  - `Core`, `CoreUObject`, `Engine`
  - `GameplayTags`（必须启用）
  - `UMG`（可选，用于 UI 显示）

---

🚀 快速开始

 1. 环境要求
- Windows 11 或 macOS
- Visual Studio 2022（Windows）或 JetBrains Rider 2025（首选）
- Unreal Engine 5.3 或更高版本
- .Net 8.0
- 


 2. 生成项目文件
- 双击 `ItemSystem.uproject` 文件，选择“Generate Visual Studio project files”


 3. 编译与运行(JetBrains Rider 2025为例）
- 打开生成的 ItemSystem.sln` 解决方案，构建启动项目，按 `shift+F10` 启动编辑器。
- 在编辑器中创建物品定义数据资产（继承自 `UItemDefinition`），配置属性。
- 使用蓝图或 C++ 调用工厂函数创建实例。




---

 📁 目录结构（主要）

```
ItemSystem/                              # 项目根目录
├── Config/                              # 项目配置文件
├── Source/                              # 源代码根目录
│   ├── ItemSystem/                      # 主游戏模块
│   │   ├── Private/                     # 私有实现（.cpp 及部分头文件）
│   │   │   ├── Effects/                 # 消耗品效果实现
│   │   │   ├── Items/
│   │   │   │   ├── Assets/              # 物品定义类实现（ItemDefinition.cpp 等）
│   │   │   │   ├── Factory/             # 物品工厂实现（ItemFactory.cpp）
│   │   │   │   ├── Instances/           # 物品实例类实现（ItemInstance.cpp 等）
│   │   │   │   └── Interfaces/          # 物品相关接口实现（如有）
│   │   │   ├── ItemSystemLogging.cpp    # 日志类别定义
│   │   │   ├── ItemSystemSettings.cpp   # 项目设置实现
│   │   │   ├── ItemSystemTags.cpp       # 原生 GameplayTag 定义
│   │   │   └── SpawnedItemActor.cpp     # 世界掉落 Actor 实现
│   │   ├── Public/                      # 公开接口（.h 文件）
│   │   │   ├── Items/
│   │   │   │   ├── Assets/              # 物品定义类声明
│   │   │   │   │   ├── ItemDefinition.h
│   │   │   │   │   ├── EquippableItemDefinition.h
│   │   │   │   │   └── ConsumableItemDefinition.h
│   │   │   │   ├── Factory/             # 物品工厂类声明（ItemFactory.h）
│   │   │   │   ├── Instances/           # 物品实例类声明
│   │   │   │   │   ├── ItemInstance.h
│   │   │   │   │   ├── EquippableItemInstance.h
│   │   │   │   │   └── ConsumableItemInstance.h
│   │   │   │   ├── Interfaces/          # 物品相关接口声明
│   │   │   │   └── Structures/          # 物品相关结构体（如 FEquipmentSlotAttributeRange）
│   │   │   ├── ItemSystemLogging.h      # 日志类别声明
│   │   │   ├── ItemSystemSettings.h     # 项目设置声明
│   │   │   ├── ItemSystemTags.h         # 原生 GameplayTag 声明
│   │   │   └── SpawnedItemActor.h       # 世界掉落 Actor 声明
│   │   └── ItemSystem.Build.cs          # 模块构建脚本
│   └── ItemSystem.Target.cs             # 游戏目标构建配置
└                      

---

 📜 许可证

本项目基于 MIT License 开源，详情见 [LICENSE](LICENSE) 文件。你可以自由使用、修改和分发，但需保留版权声明。

---

 🙏 致谢

- Epic Games 提供强大的 Unreal Engine
- GameplayTags 系统开发者
- 所有贡献者和开源社区

---

 📬 联系方式

如有问题或建议，欢迎提交 [Issue](https://github.com/Difan026/Difan026-PersonalProjects-UE/issues) 或通过邮件联系：`3585331143@qq.com`
