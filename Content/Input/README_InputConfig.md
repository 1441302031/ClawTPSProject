# 🎮 输入映射上下文配置指南

> UE5 Enhanced Input 系统配置说明

---

## 📋 需要创建的蓝图资源

在 Unreal Engine 编辑器中创建以下资源：

### 1. 输入动作（Input Actions）

在 `Content/Input/` 文件夹下创建：

| 动作名称 | 变量类型 | 说明 |
|---------|---------|------|
| `IA_Move` | Vector2D | 角色移动（WASD） |
| `IA_Look` | Vector2D | 视角控制（鼠标） |
| `IA_Jump` | bool | 跳跃 |
| `IA_Sprint` | bool | 冲刺 |
| `IA_Crouch` | bool | 蹲伏 |
| `IA_Fire` | bool | 射击 |
| `IA_Aim` | bool | 瞄准 |
| `IA_Reload` | bool | 装弹 |
| `IA_Melee` | bool | 近战 |
| `IA_Interact` | bool | 交互 |

**创建步骤：**
1. 右键 Content 浏览器 → Input → Input Action
2. 命名为 `IA_Move` 等
3. 设置 Value Type（Vector2D 或 bool）

---

### 2. 输入映射上下文（Input Mapping Context）

创建 `IMC_Default` （Input Mapping Context）

**配置步骤：**

1. 右键 Content 浏览器 → Input → Input Mapping Context
2. 命名为 `IMC_Default`
3. 打开后添加以下映射：

```
Mapping 1: Move
  - Input Action: IA_Move
  - Key: W (Scale Y=1.0)
  - Key: S (Scale Y=-1.0)
  - Key: A (Scale X=-1.0)
  - Key: D (Scale X=1.0)

Mapping 2: Look
  - Input Action: IA_Look
  - Key: Mouse X (Scale X=1.0)
  - Key: Mouse Y (Scale Y=-1.0)

Mapping 3: Jump
  - Input Action: IA_Jump
  - Key: Space Bar

Mapping 4: Sprint
  - Input Action: IA_Sprint
  - Key: Left Shift

Mapping 5: Crouch
  - Input Action: IA_Crouch
  - Key: Left Control

Mapping 6: Fire
  - Input Action: IA_Fire
  - Key: Left Mouse Button

Mapping 7: Aim
  - Input Action: IA_Aim
  - Key: Right Mouse Button

Mapping 8: Reload
  - Input Action: IA_Reload
  - Key: R

Mapping 9: Melee
  - Input Action: IA_Melee
  - Key: F

Mapping 10: Interact
  - Input Action: IA_Interact
  - Key: E

Mapping 11: Pause Menu
  - Input Action: IA_PauseMenu
  - Key: Escape
```

---

### 3. 在角色蓝图中配置

**创建角色蓝图：**

1. 右键 Content/Characters → Blueprint Class
2. 父类选择 `TPSCharacter`
3. 命名为 `BP_TPSCharacter`

**配置默认值：**

在 Blueprint 的 Details 面板中设置：

```
Input 类别:
  - Default Mapping Context: IMC_Default
  - Move Action: IA_Move
  - Look Action: IA_Look
  - Jump Action: IA_Jump
  - Sprint Action: IA_Sprint
  - Crouch Action: IA_Crouch
  - Fire Action: IA_Fire
  - Aim Action: IA_Aim
  - Reload Action: IA_Reload
  - Melee Action: IA_Melee
  - Interact Action: IA_Interact

Character|Movement 类别:
  - Walk Speed: 500.0
  - Sprint Speed: 800.0

Character|Camera 类别:
  - Base Turn Rate: 45.0
  - Base Look Up Rate: 45.0
  - Aim FOV: 55.0
```

---

## 🔧 在 GameMode 中配置

**创建 GameMode 蓝图：**

1. 右键 Content/Blueprints → Blueprint Class
2. 父类选择 `TPSGameMode`
3. 命名为 `BP_TPSGameMode`

**配置默认 Pawn 类：**

在 World Settings 或 GameMode 设置中：
```
Default Pawn Class: BP_TPSCharacter
Player Controller Class: TPSPlayerController (或创建蓝图版本)
```

---

## ✅ 验证配置

### 测试步骤

1. **创建测试地图**
   - File → New Level → Default
   - 保存为 `Content/Maps/TestMap`

2. **设置 GameMode**
   - World Settings → GameMode Override
   - 选择 `BP_TPSGameMode`

3. **添加玩家出生点**
   - Place Actors → Player Start
   - 放在地图中

4. **运行测试**
   - 点击 Play
   - 测试移动（WASD）
   - 测试视角（鼠标）
   - 测试跳跃（空格）
   - 测试冲刺（Shift）
   - 测试蹲伏（Ctrl）

---

## 🐛 常见问题

### Q: 输入无响应

**检查清单：**
- [ ] Input Mapping Context 是否已创建
- [ ] 是否在角色蓝图中分配了 Mapping Context
- [ ] Input Actions 是否正确配置
- [ ] Enhanced Input 插件是否启用

### Q: 移动方向错误

**解决：**
- 检查 CharacterMovement 组件的 `bOrientRotationToMovement` 设置
- 确认输入缩放的正负值正确

### Q: 视角反转

**解决：**
- 在 IA_Look 的 Mouse Y 输入上调整 Scale 为正值
- 或在角色蓝图中调整 Base Look Up Rate 的符号

---

## 📚 参考资源

- [Enhanced Input 官方文档](https://docs.unrealengine.com/5.0/en-US/enhanced-input-system-in-unreal-engine/)
- [Input Action 使用指南](https://dev.epicgames.com/documentation/en-us/unreal-engine/enhanced-input-in-unreal-engine)

---

**最后更新：** 2026-03-17
