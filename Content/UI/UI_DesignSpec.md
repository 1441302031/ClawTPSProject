# TPS UI 设计规范文档

> 记录 HUD Widget 蓝图的设计规范和配置

---

## Widget 列表

| Widget 名称 | 用途 | 优先级 |
|-------------|------|--------|
| `WBP_Crosshair` | 准星显示 | P0 |
| `WBP_AmmoCounter` | 弹药计数 | P0 |
| `WBP_HealthBar` | 生命值显示 | P0 |
| `WBP_HUDLayout` | HUD 总布局 | P0 |
| `WBP_PauseMenu` | 暂停菜单 | P1 |
| `WBP_MainMenu` | 主菜单 | P1 |

---

## WBP_Crosshair（准星）

### 设计规格

```
尺寸：64x64 px
锚点：Center Center
位置：屏幕正中央
```

### 元素构成

| 元素 | 类型 | 尺寸 | 颜色 | 说明 |
|------|------|------|------|------|
| `CenterDot` | Image | 4x4 | #FFFFFF | 中心点 |
| `HorizontalLine` | Image | 20x2 | #FFFFFF | 水平线 |
| `VerticalLine` | Image | 2x20 | #FFFFFF | 垂直线 |
| `CircleOuter` | Image | 40x40 | #00FF00 | 动态散布圈 |

### 动态效果

| 参数 | 类型 | 范围 | 说明 |
|------|------|------|------|
| `SpreadAlpha` | float | 0.0-1.0 | 散布透明度 |
| `SpreadScale` | float | 1.0-2.0 | 散布圈缩放 |
| `RecoilOffset` | Vector2D | - | 后坐力偏移 |

### 蓝图逻辑

```
Event Tick
  → UpdateCrosshairSpread()
    → 根据当前武器散布调整 CircleOuter 大小
    → 根据移动状态调整透明度

Event OnWeaponFired
  → PlayRecoilAnimation()
    → 准星向上偏移
    → 渐变恢复

Event OnAimStateChanged
  → 瞄准时隐藏准星
  → 停止瞄准时显示准星
```

---

## WBP_AmmoCounter（弹药显示）

### 设计规格

```
尺寸：200x60 px
锚点：Bottom Right
位置：右下角，距边缘 40px
```

### 元素构成

| 元素 | 类型 | 内容 | 字体 | 说明 |
|------|------|------|------|------|
| `CurrentAmmoText` | Text | "30" | 48px Bold | 当前弹药 |
| `SeparatorText` | Text | "/" | 36px Regular | 分隔符 |
| `ReserveAmmoText` | Text | "90" | 36px Regular | 备用弹药 |
| `ReloadIcon` | Image | 🔄 | - | 装弹图标（隐藏） |
| `LowAmmoWarning` | Image | ! | - | 低弹药警告（隐藏） |

### 状态规则

| 状态 | 条件 | 效果 |
|------|------|------|
| 正常 | CurrentAmmo > 10 | 白色显示 |
| 低弹药 | CurrentAmmo <= 10 | 红色闪烁 |
| 空仓 | CurrentAmmo == 0 | 红色常亮 + 显示装弹图标 |
| 装弹中 | bIsReloading | 显示装弹进度条 |

### 蓝图逻辑

```
Event OnAmmoChanged
  → UpdateAmmoDisplay(NewCurrent, NewReserve)
    → 更新 Text 内容
    → 检查是否需要低弹药警告

Event OnReloadStarted
  → ShowReloadIcon()
  → PlayReloadProgress()

Event OnReloadCompleted
  → HideReloadIcon()
```

---

## WBP_HealthBar（生命值）

### 设计规格

```
尺寸：300x20 px
锚点：Bottom Left
位置：左下角，距边缘 40px
```

### 元素构成

| 元素 | 类型 | 说明 |
|------|------|------|
| `HealthBarFill` | ProgressBar | 当前生命值填充 |
| `HealthBarBackground` | Image | 背景框 |
| `HealthText` | Text | "100/100" |
| `ArmorBarFill` | ProgressBar | 护甲值填充 |
| `DamageOverlay` | Image | 受伤红色遮罩 |

### 颜色配置

| 状态 | 颜色 | 说明 |
|------|------|------|
| 健康 (>50%) | #00FF00 | 绿色 |
| 中等 (25-50%) | #FFFF00 | 黄色 |
| 危险 (<25%) | #FF0000 | 红色 |
| 护甲 | #0080FF | 蓝色 |

### 动画效果

| 动画名 | 触发条件 | 效果 |
|--------|----------|------|
| `Anim_HealthChange` | 生命值变化 | 平滑过渡填充 |
| `Anim_DamageFlash` | 受到伤害 | 红色遮罩闪烁 |
| `Anim_LowHealthPulse` | 生命值<25% | 红色边框脉冲 |

---

## WBP_HUDLayout（HUD 总布局）

### 布局结构

```
WBP_HUDLayout (Canvas Panel)
├── WBP_Crosshair (Center)
├── TopPanel (Top Left)
│   ├── ObjectiveText
│   └── WaveInfo
├── BottomLeftPanel (Bottom Left)
│   └── WBP_HealthBar
├── BottomRightPanel (Bottom Right)
│   └── WBP_AmmoCounter
└── CenterBottomPanel (Center Bottom)
    ├── HitMarker
    └── KillFeed
```

### 响应式配置

| 分辨率 | 缩放比例 | 说明 |
|--------|----------|------|
| 1920x1080 | 1.0 | 标准 |
| 2560x1440 | 1.33 | 2K |
| 3840x2160 | 2.0 | 4K |
| 1280x720 | 0.67 | 720p |

---

## 配置检查清单

### Widget 蓝图
- [ ] 创建 WBP_Crosshair
- [ ] 创建 WBP_AmmoCounter
- [ ] 创建 WBP_HealthBar
- [ ] 创建 WBP_HUDLayout
- [ ] 配置锚点和布局
- [ ] 配置动画和时间轴
- [ ] 绑定数据更新事件

### C++ 集成
- [ ] ATPSHUD 类创建 Widget 实例
- [ ] 绑定数据更新接口
- [ ] 测试 Widget 显示和更新
- [ ] 性能优化（Tick 间隔）

---

**创建日期:** 2026-03-18  
**最后更新:** 2026-03-18  
**状态:** 待配置
