# TPS Input 系统配置文档

> 记录 Input Actions 和 Input Mapping Context 配置

---

## Input Actions（11 个）

### 移动相关

| 名称 | 类型 | 按键绑定 | 说明 |
|------|------|----------|------|
| `IA_MoveForward` | Axis | W/S | 前后移动 |
| `IA_MoveRight` | Axis | A/D | 左右移动 |
| `IA_LookUp` | Axis | Mouse Y | 视角上下 |
| `IA_LookRight` | Axis | Mouse X | 视角左右 |

### 动作相关

| 名称 | 类型 | 按键绑定 | 说明 |
|------|------|----------|------|
| `IA_Jump` | Action | Space | 跳跃 |
| `IA_Sprint` | Action | Left Shift | 冲刺（按住） |
| `IA_Crouch` | Action | Left Ctrl | 蹲伏（切换） |

### 武器相关

| 名称 | 类型 | 按键绑定 | 说明 |
|------|------|----------|------|
| `IA_Fire` | Action | Left Mouse | 射击（按住连发） |
| `IA_Aim` | Action | Right Mouse | 瞄准（按住） |
| `IA_Reload` | Action | R | 装弹 |
| `IA_Melee` | Action | F | 近战攻击 |
| `IA_Interact` | Action | E | 交互 |

---

## Input Mapping Context 配置

### IMC_TPSCharacter

```json
{
  "mappingContextName": "IMC_TPSCharacter",
  "priority": 0,
  "mappings": [
    {
      "inputAction": "IA_MoveForward",
      "keyCombination": "W",
      "triggerSource": "Gamepad"
    },
    {
      "inputAction": "IA_MoveRight",
      "keyCombination": "A/D",
      "triggerSource": "Gamepad"
    },
    {
      "inputAction": "IA_LookUp",
      "keyCombination": "MouseY",
      "triggerSource": "Mouse"
    },
    {
      "inputAction": "IA_LookRight",
      "keyCombination": "MouseX",
      "triggerSource": "Mouse"
    },
    {
      "inputAction": "IA_Jump",
      "keyCombination": "SpaceBar",
      "triggerType": "Started"
    },
    {
      "inputAction": "IA_Sprint",
      "keyCombination": "LeftShift",
      "triggerType": "WhileActive"
    },
    {
      "inputAction": "IA_Crouch",
      "keyCombination": "LeftControl",
      "triggerType": "Triggered"
    },
    {
      "inputAction": "IA_Fire",
      "keyCombination": "LeftMouseButton",
      "triggerType": "WhileActive"
    },
    {
      "inputAction": "IA_Aim",
      "keyCombination": "RightMouseButton",
      "triggerType": "WhileActive"
    },
    {
      "inputAction": "IA_Reload",
      "keyCombination": "R",
      "triggerType": "Started"
    },
    {
      "inputAction": "IA_Melee",
      "keyCombination": "F",
      "triggerType": "Started"
    },
    {
      "inputAction": "IA_Interact",
      "keyCombination": "E",
      "triggerType": "Started"
    }
  ]
}
```

---

## BP_TPSCharacter 蓝图配置

### 变量定义

| 变量名 | 类型 | 默认值 | 说明 |
|--------|------|--------|------|
| `BaseWalkSpeed` | float | 600.0 | 基础行走速度 |
| `SprintSpeed` | float | 900.0 | 冲刺速度 |
| `CrouchSpeed` | float | 300.0 | 蹲伏速度 |
| `JumpForce` | float | 450.0 | 跳跃力度 |
| `BaseFOV` | float | 90.0 | 基础视野 |
| `AimFOV` | float | 55.0 | 瞄准时视野 |
| `MouseSensitivity` | float | 1.0 | 鼠标灵敏度 |

### 组件层次结构

```
BP_TPSCharacter
├── CapsuleComponent (碰撞体)
├── CharacterMovement (移动组件)
├── Mesh (角色网格体)
│   └── CameraBoom (相机臂)
│       └── FollowCamera (跟随相机)
└── WeaponSocket (武器挂载点)
```

---

## 配置检查清单

### Input Actions
- [ ] 创建 11 个 Input Actions
- [ ] 配置正确的 Value Type（Axis/Action）
- [ ] 设置合理的 Dead Zone（手柄）

### Input Mapping Context
- [ ] 创建 IMC_TPSCharacter
- [ ] 绑定所有 Input Actions
- [ ] 设置正确的 Trigger Type
- [ ] 配置优先级

### BP_TPSCharacter
- [ ] 创建蓝图类
- [ ] 配置移动参数
- [ ] 配置相机参数
- [ ] 绑定 Input Mapping Context
- [ ] 测试移动、视角、动作

---

**创建日期:** 2026-03-18  
**最后更新:** 2026-03-18  
**状态:** 待配置
