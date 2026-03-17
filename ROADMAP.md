# 🗺️ TPS 项目开发路线图

> 从框架到完整游戏的开发路径

---

## 📊 当前状态

**阶段：** Phase 1 - 基础框架完成 ✅  
**完成度：** 约 60%  
**日期：** 2026-03-17

---

## 📅 Phase 1：基础框架（已完成）

**时间：** Day 1  
**状态：** ✅ 100%

### 完成内容

- [x] C++ 核心类实现
  - [x] TPSCharacter（角色控制器）
  - [x] TPSWeaponBase（武器基类）
  - [x] TPSWeaponComponent（武器组件）
  - [x] TPSGameMode（游戏模式）
  - [x] TPSGameState（游戏状态）
  - [x] TPSPlayerController（玩家控制器）
  - [x] TPSGameInstance（游戏实例）
  - [x] TPSHUD（HUD 系统）
  - [x] TPSFunctionLibrary（工具函数库）
  - [x] TPSAnimNotify（动画通知）

- [x] 配置文件
  - [x] DefaultEngine.ini
  - [x] DefaultGame.ini
  - [x] DefaultInput.ini
  - [x] Build.cs + Target 文件

- [x] 文档
  - [x] README.md
  - [x] QUICKSTART.md
  - [x] PROGRESS.md
  - [x] DELIVERY_REPORT.md
  - [x] BlueprintCreationChecklist.md

---

## 📅 Phase 2：蓝图配置（进行中）

**时间：** Day 1-2  
**状态：** 🔄 50%

### 待完成

- [ ] Input 系统配置
  - [ ] 创建 11 个 Input Actions
  - [ ] 创建 Input Mapping Context
  - [ ] 配置按键绑定

- [ ] 角色蓝图
  - [ ] BP_TPSCharacter
  - [ ] 配置输入映射
  - [ ] 配置移动参数
  - [ ] 配置相机参数

- [ ] 武器蓝图
  - [ ] BP_Weapon_AssaultRifle
  - [ ] BP_Weapon_Shotgun
  - [ ] BP_Weapon_SniperRifle
  - [ ] BP_Weapon_Pistol
  - [ ] 配置武器数据

- [ ] 游戏模式蓝图
  - [ ] BP_TPSGameMode
  - [ ] BP_TPSPlayerController（可选）

- [ ] 数据表
  - [ ] DT_Weapons（武器数据表）

**预计耗时：** 2-3 小时

---

## 📅 Phase 3：基础 UI（未开始）

**时间：** Day 2-3  
**状态：** ⏳ 0%

### Widget 蓝图

- [ ] WBP_Crosshair（准星）
  - [ ] 简单十字准星
  - [ ] 动态散布圆圈
  - [ ] 命中标记

- [ ] WBP_AmmoCounter（弹药显示）
  - [ ] 当前弹药
  - [ ] 备用弹药
  - [ ] 装弹指示器

- [ ] WBP_HealthBar（生命值）
  - [ ] 生命值条
  - [ ] 护甲值条
  - [ ] 受伤效果

- [ ] WBP_PauseMenu（暂停菜单）
  - [ ] 继续游戏
  - [ ] 设置
  - [ ] 主菜单
  - [ ] 退出游戏

- [ ] WBP_MainMenu（主菜单）
  - [ ] 开始游戏
  - [ ] 设置
  - [ ] 制作人员
  - [ ] 退出

- [ ] WBP_HUDLayout（HUD 布局）
  - [ ] 整合所有 Widget
  - [ ] 锚点设置
  - [ ] 响应式布局

### C++ 集成

- [ ] HUD 与 Widget 绑定
- [ ] 数据更新接口
- [ ] 事件分发

**预计耗时：** 4-6 小时

---

## 📅 Phase 4：动画系统（未开始）

**时间：** Day 3-4  
**状态：** ⏳ 0%

### 动画蓝图

- [ ] ABP_TPSCharacter（角色动画蓝图）
  - [ ] Locomotion State Machine
    - [ ] Idle
    - [ ] Walk
    - [ ] Run
    - [ ] Sprint
  - [ ] Aiming State Machine
    - [ ] Aim Idle
    - [ ] Aim Walk
    - [ ] Aim Run
  - [ ] Actions
    - [ ] Reload
    - [ ] Melee
    - [ ] Interact
    - [ ] Jump/Fall
  - [ ] Death
    - [ ] Death Forward
    - [ ] Death Backward
    - [ ] Death Left
    - [ ] Death Right

### 动画状态机

- [ ] 创建 Blend Spaces
  - [ ] BS_Locomotion（移动混合）
  - [ ] BS_AimLocomotion（瞄准移动混合）

- [ ] 创建 Blend Poses
  - [ ] 根据速度混合
  - [ ] 根据方向混合
  - [ ] 根据状态混合

### 动画通知

- [ ] Reload_Start（开始装弹）
- [ ] Reload_End（结束装弹）
- [ ] Fire（射击）
- [ ] Footstep_L/R（脚步音效）

**预计耗时：** 6-8 小时

---

## 📅 Phase 5：音效系统（未开始）

**时间：** Day 4-5  
**状态：** ⏳ 0%

### 音效 Cue

- [ ] S_Fire_AR（突击步枪射击）
- [ ] S_Fire_Shotgun（霰弹枪射击）
- [ ] S_Fire_Sniper（狙击枪射击）
- [ ] S_Fire_Pistol（手枪射击）
- [ ] S_Reload（装弹）
- [ ] S_Empty（空仓）
- [ ] S_Equip（装备武器）

### 环境音效

- [ ] S_Footstep_Concrete（水泥地脚步）
- [ ] S_Footstep_Grass（草地脚步）
- [ ] S_Footstep_Metal（金属脚步）
- [ ] S_Footstep_Wood（木板脚步）

### 语音

- [ ] V_Player_Hurt（玩家受伤）
- [ ] V_Player_Death（玩家死亡）
- [ ] V_Player_Jump（玩家跳跃）
- [ ] V_Player_Land（玩家落地）

### 音频组件

- [ ] 集成到武器系统
- [ ] 集成到角色系统
- [ ] 音量控制
- [ ] 3D 音效设置

**预计耗时：** 3-5 小时

---

## 📅 Phase 6：特效系统（未开始）

**时间：** Day 5-6  
**状态：** ⏳ 0%

### Niagara 特效

- [ ] NS_MuzzleFlash（枪口火焰）
  - [ ] 突击步枪版本
  - [ ] 霰弹枪版本
  - [ ] 狙击枪版本
  - [ ] 手枪版本

- [ ] NS_HitEffect（命中效果）
  - [ ] 肉体命中
  - [ ] 墙壁命中
  - [ ] 金属命中

- [ ] NS_ShellEject（弹壳弹出）
  - [ ] 突击步枪
  - [ ] 霰弹枪
  - [ ] 手枪

- [ ] NS_Blood（血液效果）
  - [ ] 命中喷溅
  - [ ] 死亡倒地

### 材质效果

- [ ] MuzzleFlash Material
- [ ] HitScan Material
- [ ] Blood Decal

**预计耗时：** 4-6 小时

---

## 📅 Phase 7：AI 系统（未开始）

**时间：** Day 6-8  
**状态：** ⏳ 0%

### AI 控制器

- [ ] AI_TPSCharacter（AI 控制器）
- [ ] BT_TPS（行为树）
  - [ ] Selector_Root
    - [ ] Sequence_Attack
      - [ ] CanAttack
      - [ ] Attack
    - [ ] Sequence_Chase
      - [ ] CanSeePlayer
      - [ ] MoveToPlayer
    - [ ] Sequence_Patrol
      - [ ] PatrolPoints
      - [ ] MoveToPatrolPoint
    - [ ] Sequence_Idle
      - [ ] Wait

### AI 感知

- [ ] AIPerception 组件
  - [ ] Sight（视觉）
  - [ ] Hearing（听觉）
  - [ ] Damage（伤害感知）

### AI 角色

- [ ] BP_EnemyCharacter（敌人角色）
  - [ ] 继承 TPSCharacter
  - [ ] AI 专属逻辑
  - [ ] 生命值管理
  - [ ] 死亡处理

### 生成系统

- [ ] EnemySpawner（敌人生成器）
  - [ ] 波次管理
  - [ ] 难度曲线
  - [ ] 生成点管理

**预计耗时：** 8-12 小时

---

## 📅 Phase 8：关卡设计（未开始）

**时间：** Day 8-10  
**状态：** ⏳ 0%

### 测试地图

- [ ] TestMap（基础测试）
  - [ ] 平坦地面
  - [ ] 简单掩体
  - [ ] 出生点
  - [ ] 光照设置

### 战斗场景

- [ ] CombatArena（战斗竞技场）
  - [ ] 多种掩体
  - [ ] 高低差
  - [ ] 多个交战区域
  - [ ] 环境互动

### 任务关卡

- [ ] Mission_01（第一关）
  - [ ] 开场剧情
  - [ ] 教学目标
  - [ ] 战斗遭遇
  - [ ] Boss 战
  - [ ] 结局过场

### 环境美术

- [ ] 材质和纹理
- [ ] 植被
- [ ]  Props（道具）
- [ ] 光照和氛围
- [ ] 后处理体积

**预计耗时：** 10-15 小时

---

## 📅 Phase 9：多人游戏（未开始）

**时间：** Day 10-15  
**状态：** ⏳ 0%

### 网络复制

- [ ] 角色移动复制
- [ ] 武器系统复制
- [ ] 伤害计算复制
- [ ] UI 状态复制

### 会话管理

- [ ] 创建会话
- [ ] 加入会话
- [ ] 查找服务器
- [ ] 匹配系统

### 游戏模式

- [ ] TeamDeathmatch（团队死斗）
- [ ] FreeForAll（自由混战）
- [ ] CaptureTheFlag（夺旗）

### 服务器架构

- [ ] 专用服务器
- [ ] 监听服务器
- [ ] 反作弊（基础）

**预计耗时：** 15-25 小时

---

## 📅 Phase 10：优化和发布（未开始）

**时间：** Day 15-20  
**状态：** ⏳ 0%

### 性能优化

- [ ] Profile 分析
- [ ] LOD 设置
- [ ] 遮挡剔除
- [ ] 资源流式加载

### 质量保障

- [ ] Bug 修复
- [ ] 平衡性调整
- [ ] 用户测试
- [ ] 反馈迭代

### 打包发布

- [ ] Windows 打包
- [ ] 图标和启动画面
- [ ] 安装程序
- [ ] 发布说明

**预计耗时：** 10-15 小时

---

## 📈 总体时间估算

| 阶段 | 内容 | 预计时间 |
|------|------|---------|
| Phase 1 | 基础框架 | ✅ 完成（6 小时） |
| Phase 2 | 蓝图配置 | 2-3 小时 |
| Phase 3 | 基础 UI | 4-6 小时 |
| Phase 4 | 动画系统 | 6-8 小时 |
| Phase 5 | 音效系统 | 3-5 小时 |
| Phase 6 | 特效系统 | 4-6 小时 |
| Phase 7 | AI 系统 | 8-12 小时 |
| Phase 8 | 关卡设计 | 10-15 小时 |
| Phase 9 | 多人游戏 | 15-25 小时 |
| Phase 10 | 优化发布 | 10-15 小时 |

**总计：** 约 70-100 小时（从零到可发布版本）

---

## 🎯 里程碑

### M1：可玩原型（Phase 1-3 完成）
- 角色可以移动、射击
- 基础 UI 显示
- 可以测试核心玩法
- **预计：** Day 3

### M2：完整单人体验（Phase 1-8 完成）
- 完整动画和音效
- AI 敌人
- 测试关卡
- **预计：** Day 10

### M3：多人测试版（Phase 1-9 完成）
- 在线多人游戏
- 多种游戏模式
- **预计：** Day 15

### M4：发布版本（Phase 1-10 完成）
- 性能优化
- Bug 修复
- 正式打包
- **预计：** Day 20

---

## 📝 备注

- 时间估算基于单人开发
- 团队开发可大幅缩短时间
- 可使用市场资源加速开发
- 优先级可根据需求调整

---

**最后更新：** 2026-03-17  
**下次更新：** Phase 2 完成后
