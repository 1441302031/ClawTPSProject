# 🚀 快速启动指南

> 5 分钟快速开始你的 TPS 项目开发

---

## ⏱️ 预计时间：15-30 分钟

---

## 步骤 1：创建 Unreal Engine 项目 (5 分钟)

1. **打开 Unreal Engine 启动器**

2. **点击「创建」→「Games」**

3. **选择模板：**
   - 类型：**Third Person**
   - 目标平台：**Desktop / Console**
   - 项目类型：**C++**
   - 质量级别：**Maximum**
   - 带有初学者内容：**是**（推荐新手）

4. **项目设置：**
   - 项目名称：`TPSProject`
   - 位置：选择你的工作目录
   - 勾选「创建 Git 仓库」

5. **点击「创建」**

---

## 步骤 2：复制框架文件 (2 分钟)

```bash
# 将下载的框架文件复制到项目中

# 复制 Source 文件夹
cp -r UE_TPS_Project/Source/* YourProject/Source/

# 复制 Config 文件夹（覆盖）
cp -r UE_TPS_Project/Config/* YourProject/Config/

# 复制 Content 文件夹（合并）
cp -r UE_TPS_Project/Content/* YourProject/Content/
```

**或者手动操作：**
1. 打开项目文件夹
2. 将 `Source/TPSProject` 文件夹复制到项目的 Source 目录
3. 将 Config 文件夹中的 3 个 .ini 文件复制到项目的 Config 目录
4. 将 Content 文件夹内容复制到项目的 Content 目录

---

## 步骤 3：生成项目文件 (3 分钟)

### Windows (Visual Studio)

1. **右键点击 `.uproject` 文件**
2. **选择「Generate Visual Studio project files」**
3. **等待生成完成**

### Mac (Xcode)

1. **右键点击 `.uproject` 文件**
2. **选择「Generate Xcode project files」**
3. **等待生成完成**

### Linux

```bash
cd YourProject
dotnet build Source/TPSProject/TPSProject.csproj
```

---

## 步骤 4：编译项目 (5-10 分钟)

### 方法一：通过 Unreal Engine

1. **双击 `.uproject` 文件打开项目**
2. **等待 Engine 自动编译**
3. **如果提示重新编译，点击「Yes」**

### 方法二：通过 Visual Studio

1. **打开 `.sln` 文件**
2. **解决方案配置选择「Development Editor」**
3. **按 Ctrl+Shift+B 编译**
4. **等待编译完成**

---

## 步骤 5：配置输入系统 (5 分钟)

### 创建 Input Actions

1. **在 Content 浏览器中右键 → Input → Input Action**
2. **创建以下动作：**
   - `IA_Move` (Vector2D)
   - `IA_Look` (Vector2D)
   - `IA_Jump` (bool)
   - `IA_Sprint` (bool)
   - `IA_Crouch` (bool)
   - `IA_Fire` (bool)
   - `IA_Aim` (bool)
   - `IA_Reload` (bool)
   - `IA_Melee` (bool)
   - `IA_Interact` (bool)

### 创建 Input Mapping Context

1. **右键 → Input → Input Mapping Context**
2. **命名为 `IMC_Default`**
3. **打开并添加映射**（参考 `Content/Input/README_InputConfig.md`）

### 创建角色蓝图

1. **右键 Content/Characters → Blueprint Class**
2. **父类选择 `TPSCharacter`**
3. **命名为 `BP_TPSCharacter`**
4. **在 Details 面板中分配 Input Actions 和 Mapping Context**

---

## 步骤 6：创建测试地图 (3 分钟)

1. **File → New Level → Default**
2. **删除默认立方体**
3. **添加地面：**
   - Place Actors → Cube
   - 缩放为 (10, 10, 0.1)
   - 位置 (0, 0, -50)

4. **添加玩家出生点：**
   - Place Actors → Player Start
   - 放在地面上方

5. **添加光照：**
   - Place Actors → Directional Light
   - Place Actors → Sky Atmosphere
   - Place Actors → Sky Light

6. **保存为 `Content/Maps/TestMap`**

---

## 步骤 7：配置 GameMode (2 分钟)

### 创建 GameMode 蓝图

1. **右键 Content/Blueprints → Blueprint Class**
2. **父类选择 `TPSGameMode`**
3. **命名为 `BP_TPSGameMode`**

### 设置默认配置

1. **打开 World Settings**（Settings → World Settings）
2. **GameMode Override → 选择 `BP_TPSGameMode`**
3. **设置 Default Pawn Class → `BP_TPSCharacter`**

---

## 步骤 8：运行测试！(1 分钟)

1. **点击工具栏的「Play」按钮**
2. **测试以下功能：**
   - ✅ WASD 移动
   - ✅ 鼠标视角
   - ✅ 空格跳跃
   - ✅ Shift 冲刺
   - ✅ Ctrl 蹲伏
   - ✅ 左键射击（查看日志输出）
   - ✅ 右键瞄准（FOV 变化）
   - ✅ R 装弹（查看日志输出）

---

## ✅ 验证清单

运行后检查：

- [ ] 角色可以移动
- [ ] 视角跟随鼠标
- [ ] 跳跃正常
- [ ] 冲刺时速度加快
- [ ] 蹲伏时高度降低
- [ ] 瞄准时 FOV 缩小
- [ ] 射击时在 Output Log 看到 "Fire" 日志
- [ ] 装弹时在 Output Log 看到 "Reload" 日志

---

## 🐛 遇到问题？

### 编译错误

**错误：Module not found**
```
解决：检查 Source/TPSProject/TPSProject.Build.cs
确保所有依赖模块名称正确
```

**错误：无法找到类**
```
解决：确保已正确生成项目文件
重新运行「Generate Visual Studio project files」
```

### 输入无响应

**检查：**
- [ ] Enhanced Input 插件已启用
- [ ] Input Mapping Context 已创建
- [ ] 角色蓝图中分配了 Mapping Context
- [ ] Input Actions 变量已设置

### 角色不移动

**检查：**
- [ ] Input Mapping Context 中的移动映射正确
- [ ] CharacterMovement 组件存在
- [ ] Max Walk Speed > 0

---

## 📚 下一步

完成快速启动后，继续：

1. **阅读 `README.md`** - 了解完整项目结构
2. **阅读 `PROGRESS.md`** - 查看开发进度和待办事项
3. **创建武器蓝图** - 添加实际武器模型
4. **创建 UI** - 添加准星和弹药显示
5. **添加敌人 AI** - 让游戏更有趣

---

## 🆘 获取帮助

- **官方文档：** https://docs.unrealengine.com/
- **社区论坛：** https://forums.unrealengine.com/
- **Discord：** https://discord.gg/unrealengine

---

**祝你开发顺利！🎮**

---

*最后更新：2026-03-17*
