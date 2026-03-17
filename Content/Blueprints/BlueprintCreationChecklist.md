# 📘 蓝图创建清单

> 在 Unreal Engine 编辑器中需要创建的蓝图资源清单

---

## 📍 创建位置

所有蓝图创建在 `Content/Blueprints/` 目录下

---

## 1️⃣ Input Actions（输入动作）

**路径：** `Content/Blueprints/Input/`

### 创建步骤

1. 右键 Content 浏览器 → Input → Input Action
2. 按以下列表创建

### 列表

| 名称 | Value Type | 说明 |
|------|-----------|------|
| `IA_Move` | Vector2D | 移动（WASD） |
| `IA_Look` | Vector2D | 视角（鼠标） |
| `IA_Jump` | bool | 跳跃 |
| `IA_Sprint` | bool | 冲刺 |
| `IA_Crouch` | bool | 蹲伏 |
| `IA_Fire` | bool | 射击 |
| `IA_Aim` | bool | 瞄准 |
| `IA_Reload` | bool | 装弹 |
| `IA_Melee` | bool | 近战 |
| `IA_Interact` | bool | 交互 |
| `IA_PauseMenu` | bool | 暂停菜单 |

---

## 2️⃣ Input Mapping Context（输入映射上下文）

**路径：** `Content/Blueprints/Input/`

### 创建步骤

1. 右键 → Input → Input Mapping Context
2. 命名为 `IMC_Default`
3. 打开并配置以下映射

### 配置

```
IMC_Default
├── Move
│   ├── Input Action: IA_Move
│   ├── Key: W (Scale: Y=1.0)
│   ├── Key: S (Scale: Y=-1.0)
│   ├── Key: A (Scale: X=-1.0)
│   └── Key: D (Scale: X=1.0)
├── Look
│   ├── Input Action: IA_Look
│   ├── Key: MouseX (Scale: X=1.0)
│   └── Key: MouseY (Scale: Y=-1.0)
├── Jump
│   ├── Input Action: IA_Jump
│   └── Key: SpaceBar
├── Sprint
│   ├── Input Action: IA_Sprint
│   └── Key: LeftShift
├── Crouch
│   ├── Input Action: IA_Crouch
│   └── Key: LeftControl
├── Fire
│   ├── Input Action: IA_Fire
│   └── Key: LeftMouseButton
├── Aim
│   ├── Input Action: IA_Aim
│   └── Key: RightMouseButton
├── Reload
│   ├── Input Action: IA_Reload
│   └── Key: R
├── Melee
│   ├── Input Action: IA_Melee
│   └── Key: F
├── Interact
│   ├── Input Action: IA_Interact
│   └── Key: E
└── PauseMenu
    ├── Input Action: IA_PauseMenu
    └── Key: Escape
```

---

## 3️⃣ Character Blueprint（角色蓝图）

**路径：** `Content/Blueprints/Characters/`

### 创建步骤

1. 右键 → Blueprint Class
2. 父类选择 `TPSCharacter`
3. 命名为 `BP_TPSCharacter`

### 配置 Details 面板

**Input 类别：**
```
Default Mapping Context: IMC_Default
Move Action: IA_Move
Look Action: IA_Look
Jump Action: IA_Jump
Sprint Action: IA_Sprint
Crouch Action: IA_Crouch
Fire Action: IA_Fire
Aim Action: IA_Aim
Reload Action: IA_Reload
Melee Action: IA_Melee
Interact Action: IA_Interact
```

**Character|Movement 类别：**
```
Walk Speed: 500.0
Sprint Speed: 800.0
```

**Character|Camera 类别：**
```
Base Turn Rate: 45.0
Base Look Up Rate: 45.0
Aim FOV: 55.0
```

**Mesh 设置：**
```
Mesh → Skeletal Mesh: SK_Manquin (或你的角色模型)
Animation Class: ThirdPersonAnimBP
```

---

## 4️⃣ Weapon Blueprint Class（武器蓝图类）

**路径：** `Content/Blueprints/Weapons/`

### 创建步骤

1. 右键 → Blueprint Class
2. 父类选择 `TPSWeaponBase`
3. 命名为 `BP_Weapon_AssaultRifle`（突击步枪示例）

### 配置

**Weapon 类别：**
```
Weapon Type: AssaultRifle
Weapon Data:
  - Damage: 25.0
  - Fire Rate: 10.0
  - Range: 10000.0
  - Magazine Size: 30
  - Reload Time: 2.0
  - Spread: 1.0
```

**Mesh 设置：**
```
WeaponMesh → Skeletal Mesh: [选择武器模型]
```

---

## 5️⃣ GameMode Blueprint（游戏模式蓝图）

**路径：** `Content/Blueprints/Game/`

### 创建步骤

1. 右键 → Blueprint Class
2. 父类选择 `TPSGameMode`
3. 命名为 `BP_TPSGameMode`

### 配置

**TPSGameMode 类别：**
```
Max Players: 16
Match Duration: 600.0
```

---

## 6️⃣ PlayerController Blueprint（可选）

**路径：** `Content/Blueprints/Game/`

### 创建步骤

1. 右键 → Blueprint Class
2. 父类选择 `TPSPlayerController`
3. 命名为 `BP_TPSPlayerController`

### 配置

**UI 类别：**
```
Pause Menu Class: [暂停菜单 Widget 蓝图]
```

---

## 7️⃣ Widget Blueprints（UI 界面）

**路径：** `Content/Blueprints/UI/`

### 需要创建的 Widget

| 名称 | 父类 | 说明 |
|------|------|------|
| `WBP_Crosshair` | User Widget | 准星 |
| `WBP_AmmoCounter` | User Widget | 弹药显示 |
| `WBP_HealthBar` | User Widget | 生命值条 |
| `WBP_PauseMenu` | User Widget | 暂停菜单 |
| `WBP_MainMenu` | User Widget | 主菜单 |
| `WBP_HUDLayout` | User Widget | HUD 布局容器 |

---

## 8️⃣ Animation Blueprint（动画蓝图）

**路径：** `Content/Blueprints/Animation/`

### 创建步骤

1. 右键 → Animation → Animation Blueprint
2. 父类选择 `ThirdPersonAnimInstance`（或默认 AnimInstance）
3. 命名为 `ABP_TPSCharacter`

### Event Graph 逻辑

```
Event Blueprint Update Animation
└── [设置移动状态变量]
    ├── Speed = Calculate Speed
    ├── IsInAir = Is Not On Ground
    └── IsAiming = Get Owner → Is Aiming

Event Graph → AnimGraph
└── State Machine
    ├── Locomotion
    │   ├── Idle
    │   ├── Walk
    │   ├── Run
    │   └── Sprint
    ├── Aiming
    │   ├── Aim Idle
    │   └── Aim Walk
    ├── Actions
    │   ├── Reload
    │   ├── Melee
    │   └── Interact
    └── Death
```

---

## 9️⃣ DataTable（数据表）

**路径：** `Content/Data/`

### 创建武器数据表

1. 右键 → Miscellaneous → Data Table
2. Row Type 选择 `TPSWeaponData`
3. 命名为 `DT_Weapons`

### 示例数据行

| Row Name | WeaponID | WeaponName | Damage | FireRate | MagazineSize |
|----------|----------|------------|--------|----------|--------------|
| AssaultRifle | AR_01 | Assault Rifle | 25.0 | 10.0 | 30 |
| Shotgun | SG_01 | Shotgun | 80.0 | 1.0 | 8 |
| SniperRifle | SR_01 | Sniper Rifle | 100.0 | 0.5 | 5 |
| Pistol | PS_01 | Pistol | 20.0 | 5.0 | 12 |
| SMG | SMG_01 | SMG | 18.0 | 15.0 | 40 |

---

## ✅ 验证清单

创建完成后检查：

- [ ] 所有 Input Actions 已创建
- [ ] IMC_Default 配置正确
- [ ] BP_TPSCharacter 已创建并配置
- [ ] 至少一个武器蓝图已创建
- [ ] BP_TPSGameMode 已创建
- [ ] 测试地图可以运行
- [ ] 角色可以移动、跳跃、瞄准

---

## 🐛 常见问题

### Q: Input Mapping Context 找不到

**解决：** 确保 Enhanced Input 插件已启用

### Q: 蓝图编译错误

**解决：** 检查 C++ 类是否已成功编译

### Q: 角色无法移动

**解决：** 检查 Input Mapping Context 是否正确分配给角色蓝图

---

**最后更新：** 2026-03-17
