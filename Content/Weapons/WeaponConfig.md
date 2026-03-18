# TPS 武器蓝图配置文档

> 记录 4 种武器的蓝图配置和数据结构

---

## 武器数据表 (DT_Weapons)

### 数据结构定义

```cpp
USTRUCT(BlueprintType)
struct FWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FName WeaponID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    FText WeaponName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    EWeaponType WeaponType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float FireRate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Range;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 MagazineSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float ReloadTime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Spread;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundBase* FireSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
    USoundBase* ReloadSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
    UNiagaraSystem* MuzzleFlash;
};
```

---

## 武器配置表

### 1. 突击步枪 (Assault Rifle)

| 属性 | 值 | 说明 |
|------|-----|------|
| WeaponID | `AR_001` | 唯一标识 |
| WeaponName | `M4A1` | 显示名称 |
| WeaponType | `AssaultRifle` | 武器类型 |
| Damage | `25.0` | 单发伤害 |
| FireRate | `600.0` | 射速（RPM） |
| Range | `5000.0` | 有效射程（cm） |
| MagazineSize | `30` | 弹匣容量 |
| ReloadTime | `2.5` | 装弹时间（秒） |
| Spread | `2.0` | 散布角度 |
| FireMode | `Auto` | 射击模式 |

### 2. 霰弹枪 (Shotgun)

| 属性 | 值 | 说明 |
|------|-----|------|
| WeaponID | `SG_001` | 唯一标识 |
| WeaponName | `Pump Shotgun` | 显示名称 |
| WeaponType | `Shotgun` | 武器类型 |
| Damage | `80.0` | 单发伤害 |
| FireRate | `60.0` | 射速（RPM） |
| Range | `1000.0` | 有效射程（cm） |
| MagazineSize | `6` | 弹匣容量 |
| ReloadTime | `4.0` | 装弹时间（秒） |
| Spread | `15.0` | 散布角度 |
| PelletsPerShot | `8` | 每发弹丸数 |
| FireMode | `Semi` | 射击模式 |

### 3. 狙击枪 (Sniper Rifle)

| 属性 | 值 | 说明 |
|------|-----|------|
| WeaponID | `SR_001` | 唯一标识 |
| WeaponName | `Bolt Sniper` | 显示名称 |
| WeaponType | `SniperRifle` | 武器类型 |
| Damage | `120.0` | 单发伤害 |
| FireRate | `30.0` | 射速（RPM） |
| Range | `10000.0` | 有效射程（cm） |
| MagazineSize | `5` | 弹匣容量 |
| ReloadTime | `3.5` | 装弹时间（秒） |
| Spread | `0.5` | 散布角度 |
| ZoomMultiplier | `8.0` | 瞄准倍率 |
| FireMode | `Semi` | 射击模式 |

### 4. 手枪 (Pistol)

| 属性 | 值 | 说明 |
|------|-----|------|
| WeaponID | `PI_001` | 唯一标识 |
| WeaponName | `9mm Pistol` | 显示名称 |
| WeaponType | `Pistol` | 武器类型 |
| Damage | `30.0` | 单发伤害 |
| FireRate | `300.0` | 射速（RPM） |
| Range | `2000.0` | 有效射程（cm） |
| MagazineSize | `12` | 弹匣容量 |
| ReloadTime | `1.5` | 装弹时间（秒） |
| Spread | `3.0` | 散布角度 |
| FireMode | `Semi` | 射击模式 |

---

## BP_Weapon 蓝图结构

### 组件层次结构

```
BP_Weapon_Base
├── Mesh (Skeletal Mesh)
├── MuzzleSocket (枪口挂载点)
├── EjectPortSocket (弹壳抛出点)
├── AudioComponent (音频组件)
└── CollisionBox (碰撞检测)
```

### 变量定义

| 变量名 | 类型 | 说明 |
|--------|------|------|
| `WeaponData` | FWeaponData | 武器数据引用 |
| `CurrentAmmo` | int32 | 当前弹药 |
| `ReserveAmmo` | int32 | 备用弹药 |
| `bIsFiring` | bool | 是否正在射击 |
| `bIsReloading` | bool | 是否正在装弹 |
| `bIsAiming` | bool | 是否正在瞄准 |
| `LastFireTime` | float | 上次射击时间 |

### 函数接口

| 函数名 | 参数 | 返回值 | 说明 |
|--------|------|--------|------|
| `Fire` | - | - | 执行射击 |
| `StartReload` | - | - | 开始装弹 |
| `StartAiming` | - | - | 开始瞄准 |
| `StopAiming` | - | - | 停止瞄准 |
| `GetWeaponData` | - | FWeaponData | 获取武器数据 |

---

## 配置检查清单

### 数据表
- [ ] 创建 FWeaponData 结构体
- [ ] 创建 DT_Weapons 数据表
- [ ] 填充 4 种武器数据

### 武器蓝图
- [ ] 创建 BP_Weapon_Base 基类
- [ ] 创建 4 种武器蓝图子类
- [ ] 配置 Skeletal Mesh
- [ ] 配置音频和特效
- [ ] 测试射击、装弹、切换

---

**创建日期:** 2026-03-18  
**最后更新:** 2026-03-18  
**状态:** 待配置
