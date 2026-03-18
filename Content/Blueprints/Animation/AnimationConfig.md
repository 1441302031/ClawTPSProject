# TPS 动画系统配置文档

> 记录角色动画蓝图、状态机和 Blend Space 配置

---

## ABP_TPSCharacter（角色动画蓝图）

### 变量定义

| 变量名 | 类型 | 默认值 | 说明 |
|--------|------|--------|------|
| `LocomotionSpeed` | float | 0.0 | 移动速度（从角色获取） |
| `Direction` | float | 0.0 | 移动方向（-1 到 1） |
| `bIsInAir` | bool | false | 是否在空中 |
| `bIsCrouching` | bool | false | 是否蹲伏 |
| `bIsAiming` | bool | false | 是否瞄准 |
| `bIsFiring` | bool | false | 是否射击 |
| `bIsReloading` | bool | false | 是否装弹 |
| `ReloadMontage` | AnimMontage | - | 装弹动画 |
| `FireMontage` | AnimMontage | - | 射击动画 |
| `MeleeMontage` | AnimMontage | - | 近战动画 |

---

## Blend Space 配置

### BS_Locomotion（移动混合）

**输入参数：**
- `Speed` (float): 移动速度 0-1000
- `Direction` (float): 移动方向 -180 到 180 度

**动画资源：**

| 速度 | 方向 0° | 方向 45° | 方向 90° | 方向 135° | 方向 180° |
|------|--------|---------|---------|----------|----------|
| 0 | A_Idle | A_Idle_45 | A_Idle_90 | A_Idle_135 | A_Idle_180 |
| 300 | A_Walk | A_Walk_45 | A_Walk_90 | A_Walk_135 | A_Walk_180 |
| 600 | A_Run | A_Run_45 | A_Run_90 | A_Run_135 | A_Run_180 |

### BS_AimLocomotion（瞄准移动混合）

**输入参数：**
- `Speed` (float): 移动速度 0-600
- `Direction` (float): 移动方向 -180 到 180 度

**特殊配置：**
- 瞄准时移动速度上限降低至 600
- 使用更谨慎的动画姿态

---

## 动画状态机

### Locomotion State Machine

```
State Machine: Locomotion
├── State: Idle
│   └── 条件：Speed < 10
├── State: Walk
│   └── 条件：10 <= Speed < 400
├── State: Run
│   └── 条件：Speed >= 400
└── State: Sprint
    └── 条件：bIsSprinting == true
```

### Aiming State Machine

```
State Machine: Aiming
├── State: NotAiming
│   └── 条件：bIsAiming == false
├── State: AimIdle
│   └── 条件：bIsAiming && Speed < 10
├── State: AimWalk
│   └── 条件：bIsAiming && 10 <= Speed < 400
└── State: AimRun
    └── 条件：bIsAiming && Speed >= 400
```

### Actions State Machine

```
State Machine: Actions
├── State: None (默认)
├── State: Reload
│   ├── 进入条件：bIsReloading
│   ├── 播放：ReloadMontage
│   └── 退出条件：Montage 完成
├── State: Fire
│   ├── 进入条件：bIsFiring
│   ├── 播放：FireMontage
│   └── 退出条件：bIsFiring == false
└── State: Melee
    ├── 进入条件：bIsMeleeing
    ├── 播放：MeleeMontage
    └── 退出条件：Montage 完成
```

---

## 动画通知（Anim Notify）

### 列表

| 通知名称 | 类型 | 触发时机 | 效果 |
|----------|------|----------|------|
| `AN_ReloadStart` | AnimNotify | 装弹开始 | 触发装弹逻辑 |
| `AN_ReloadEnd` | AnimNotify | 装弹结束 | 完成装弹，更新弹药 |
| `AN_Fire` | AnimNotify | 射击帧 | 生成子弹，播放特效 |
| `AN_Footstep_L` | AnimNotifyState | 左脚落地 | 播放脚步音效 |
| `AN_Footstep_R` | AnimNotifyState | 右脚落地 | 播放脚步音效 |
| `AN_MeleeHit` | AnimNotify | 近战命中帧 | 检测命中，造成伤害 |
| `AN_EjectShell` | AnimNotify | 抛壳帧 | 生成弹壳粒子 |

---

## 动画蒙太奇（Anim Montage）

### Reload_Montage（装弹）

| 参数 | 值 | 说明 |
|------|-----|------|
| 时长 | 2.5 秒 | 完整装弹时间 |
| 分支点 | 0.5 秒 | 可取消点 |
| 混合时间 | 0.2 秒 | 进出混合 |

**轨道：**
- Track 0: 上半身装弹动画
- Track 1: 武器检查动画

### Fire_Montage（射击）

| 参数 | 值 | 说明 |
|------|-----|------|
| 时长 | 0.15 秒 | 单发射击 |
| 循环 | 是 | 按住连发 |
| 混合时间 | 0.1 秒 | 快速混合 |

### Melee_Montage（近战）

| 参数 | 值 | 说明 |
|------|-----|------|
| 时长 | 0.8 秒 | 完整近战动作 |
| 命中帧 | 0.4 秒 | 伤害判定帧 |
| 混合时间 | 0.15 秒 | 进出混合 |

---

## 蓝图逻辑

### Event Graph 核心节点

```
Event BlueprintUpdateAnimation
  → TryGetPawnOwner()
  → Cast to TPSCharacter
  → 获取速度和状态变量

Event Tick
  → 更新 LocomotionSpeed
  → 更新 Direction
  → 更新 bIsInAir

Event OnJump
  → 设置 bIsInAir = true

Event OnLanded
  → 设置 bIsInAir = false

Event OnReloadStarted
  → 设置 bIsReloading = true
  → Play Montage(ReloadMontage)

Event OnReloadCompleted
  → 设置 bIsReloading = false

Event OnWeaponFired
  → 设置 bIsFiring = true
  → Play Montage(FireMontage)
```

---

## 配置检查清单

### 动画蓝图
- [ ] 创建 ABP_TPSCharacter
- [ ] 配置所有变量
- [ ] 创建状态机
- [ ] 配置混合逻辑

### Blend Space
- [ ] 创建 BS_Locomotion
- [ ] 创建 BS_AimLocomotion
- [ ] 导入所有方向动画
- [ ] 测试混合效果

### 动画通知
- [ ] 创建所有 AnimNotify
- [ ] 绑定到蒙太奇
- [ ] 测试触发效果

### 蒙太奇
- [ ] 创建 Reload_Montage
- [ ] 创建 Fire_Montage
- [ ] 创建 Melee_Montage
- [ ] 配置分支点和轨道

---

**创建日期:** 2026-03-18  
**最后更新:** 2026-03-18  
**状态:** 待配置
