# 🎮 TPS Project - 第三人称射击游戏框架

> 基于 Unreal Engine 5 的第三人称射击游戏最小应用框架

---

## 📁 项目结构

```
UE_TPS_Project/
├── Config/                          # 配置文件
│   ├── DefaultEngine.ini           # 引擎配置
│   ├── DefaultGame.ini             # 游戏配置
│   └── DefaultInput.ini            # 输入配置
├── Content/                         # 游戏资源
│   ├── Maps/                       # 地图文件
│   ├── Blueprints/                 # 蓝图文件
│   ├── Characters/                 # 角色资源
│   ├── Weapons/                    # 武器资源
│   └── UI/                         # UI 资源
├── Source/TPSProject/              # C++ 源代码
│   ├── TPSProject.h/.cpp           # 主模块
│   ├── TPSProject.Build.cs         # 构建配置
│   ├── TPSCharacter.h/.cpp         # 角色类
│   ├── TPSWeaponBase.h/.cpp        # 武器基类
│   ├── TPSWeaponComponent.h/.cpp   # 武器组件
│   ├── TPSGameMode.h/.cpp          # 游戏模式
│   ├── TPSGameState.h/.cpp         # 游戏状态
│   ├── TPSPlayerController.h/.cpp  # 玩家控制器
│   ├── TPSGameInstance.h/.cpp      # 游戏实例
│   └── TPSHUD.h/.cpp               # HUD 类
└── README.md                        # 本文件
```

---

## 🚀 快速开始

### 1. 前提条件

- **Unreal Engine 5.3+** (推荐 5.4)
- **Visual Studio 2022** (Windows) 或 **Xcode** (Mac)
- **Git** (版本控制)

### 2. 创建项目

```bash
# 1. 打开 Unreal Engine
# 2. 选择 "Games" 模板
# 3. 选择 "Third Person" 模板
# 4. 选择 "C++" 项目类型
# 5. 项目名称：TPSProject
# 6. 将本框架的 Source 和 Config 文件夹复制到项目中
```

### 3. 编译项目

```bash
# 方法一：通过 Unreal Engine
# 打开项目后，Engine 会自动提示编译

# 方法二：命令行编译
cd UE_TPS_Project
dotnet build Source/TPSProject/TPSProject.csproj

# 方法三：Visual Studio
# 右键 .uproject 文件 → "Generate Visual Studio project files"
# 打开 .sln 文件 → 编译
```

### 4. 运行项目

```bash
# 通过 Unreal Engine 编辑器运行
# 或打包后运行可执行文件
```

---

## 🎯 核心功能

### ✅ 已实现

- [x] **第三人称角色控制器**
  - WASD 移动
  - 鼠标视角控制
  - 冲刺（Shift）
  - 蹲伏（Ctrl）
  - 跳跃（空格）

- [x] **武器系统**
  - 武器基类（可扩展）
  - 武器组件（多武器管理）
  - 射击机制（射线检测）
  - 装弹系统
  - 瞄准（右键）

- [x] **游戏框架**
  - GameMode（游戏规则）
  - GameState（游戏状态）
  - PlayerController（玩家控制）
  - GameInstance（持久化数据）
  - HUD（界面显示）

- [x] **输入系统**
  - Enhanced Input（UE5 推荐）
  - 可配置的输入映射
  - 动作绑定和轴绑定

### 📋 待实现

- [ ] **敌人 AI**
  - 基础 AI 行为树
  - 巡逻、追击、攻击
  - 伤害系统

- [ ] **多人游戏**
  - 在线会话管理
  - 复制同步
  - 服务器权威

- [ ] **UI 系统**
  - 主菜单
  - 暂停菜单
  - 游戏内 HUD
  - 准星、弹药、生命值显示

- [ ] **音效系统**
  - 武器音效
  - 脚步音效
  - 环境音效
  - 语音

- [ ] **特效系统**
  - 枪口火焰
  - 命中效果
  - 弹壳弹出
  - 血液效果

- [ ] **关卡设计**
  - 测试地图
  - 出生点
  - 掩体系统

---

## 🎮 默认控制

| 操作 | 按键 | 说明 |
|------|------|------|
| 移动 | W/A/S/D | 前后左右移动 |
| 视角 | 鼠标 | 控制视角方向 |
| 跳跃 | 空格 | 跳跃 |
| 冲刺 | Left Shift | 加速跑 |
| 蹲伏 | Left Ctrl | 蹲下/站起 |
| 射击 | 左键 | 开火 |
| 瞄准 | 右键 | 瞄准模式（降低 FOV） |
| 装弹 | R | 重新装填 |
| 近战 | F | 近战攻击 |
| 交互 | E | 与环境交互 |
| 暂停 | ESC | 暂停菜单 |

---

## 🛠️ 扩展指南

### 添加新武器

1. **创建武器蓝图或 C++ 类**
   ```cpp
   // 继承自 ATPSWeaponBase
   UCLASS()
   class ATPSWeaponShotgun : public ATPSWeaponBase
   {
       // 实现霰弹枪特有逻辑
   };
   ```

2. **配置武器数据**
   - 伤害、射速、弹匣大小等
   - 在 Blueprint 中设置或 C++ 构造函数中初始化

3. **添加到角色**
   ```cpp
   WeaponComponent->EquipWeapon(NewWeapon);
   ```

### 添加新角色能力

1. **扩展 TPSCharacter 类**
   ```cpp
   UCLASS()
   class ATPSCharacterAdvanced : public ATPSCharacter
   {
       // 添加新能力
       void SpecialAbility();
   };
   ```

2. **添加新的输入动作**
   - 在 DefaultInput.ini 中配置
   - 在 SetupPlayerInputComponent 中绑定

### 创建新地图

1. **在 Content/Maps 中创建新关卡**
2. **设置 GameMode 和出生点**
3. **添加光照和后处理**

---

## 📚 学习资源

### 官方文档

- [Unreal Engine 5 文档](https://docs.unrealengine.com/)
- [Enhanced Input 系统](https://docs.unrealengine.com/5.0/en-US/enhanced-input-system-in-unreal-engine/)
- [Gameplay Ability System](https://docs.unrealengine.com/5.0/en-US/gameplay-ability-system-in-unreal-engine/)

### 推荐教程

- [Unreal Engine TPS 教程系列](https://www.youtube.com/results?search_query=unreal+engine+tps+tutorial)
- [多人游戏开发指南](https://dev.epicgames.com/community/learning/collections/4z38/unreal-engine-multiplayer)

---

## 🐛 常见问题

### Q: 编译错误 "Module not found"

**解决：** 确保所有依赖模块已正确添加到 Build.cs 文件中

### Q: 输入无响应

**解决：** 检查 Input Mapping Context 是否正确添加到 PlayerController

### Q: 武器不发射子弹

**解决：** 检查 WeaponComponent 是否正确附加到角色，CurrentWeapon 是否已设置

---

## 📝 开发日志

### 2026-03-17 - 初始框架创建

- ✅ 创建项目目录结构
- ✅ 配置基础配置文件
- ✅ 实现角色控制器（移动、视角、冲刺、蹲伏）
- ✅ 实现武器系统（基类、组件、射击、装弹）
- ✅ 实现游戏框架（GameMode、GameState、PlayerController、GameInstance、HUD）
- ✅ 配置 Enhanced Input 系统

---

## 📄 许可证

Copyright 2026 YourCompany. All rights reserved.

---

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

---

**祝开发愉快！🎮**
