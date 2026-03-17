#!/bin/bash

# UE_TPS_Project 蓝图生成辅助脚本
# 此脚本帮助生成蓝图配置的文本模板

echo "======================================"
echo "  UE TPS Project - 蓝图配置生成器"
echo "======================================"
echo ""

# 生成 Input Action 配置文本
generate_input_actions() {
    echo "📋 Input Actions 配置文本："
    echo ""
    echo "复制以下内容到每个 Input Action 的 Notes 字段："
    echo ""
    echo "--- IA_Move ---"
    echo "Value Type: Vector2D"
    echo "Usage: Character movement (WASD)"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Look ---"
    echo "Value Type: Vector2D"
    echo "Usage: Camera control (Mouse)"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Jump ---"
    echo "Value Type: bool"
    echo "Usage: Jump action"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Sprint ---"
    echo "Value Type: bool"
    echo "Usage: Sprint toggle"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Crouch ---"
    echo "Value Type: bool"
    echo "Usage: Crouch toggle"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Fire ---"
    echo "Value Type: bool"
    echo "Usage: Fire weapon"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Aim ---"
    echo "Value Type: bool"
    echo "Usage: Aim down sights"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Reload ---"
    echo "Value Type: bool"
    echo "Usage: Reload weapon"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Melee ---"
    echo "Value Type: bool"
    echo "Usage: Melee attack"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
    echo "--- IA_Interact ---"
    echo "Value Type: bool"
    echo "Usage: Interact with objects"
    echo "Bound in: TPSCharacter::SetupPlayerInputComponent"
    echo ""
}

# 生成角色蓝图配置检查清单
generate_character_checklist() {
    echo ""
    echo "======================================"
    echo "  BP_TPSCharacter 配置检查清单"
    echo "======================================"
    echo ""
    echo "在 Details 面板中检查以下配置："
    echo ""
    echo "【Input 类别】"
    echo "☐ Default Mapping Context → IMC_Default"
    echo "☐ Move Action → IA_Move"
    echo "☐ Look Action → IA_Look"
    echo "☐ Jump Action → IA_Jump"
    echo "☐ Sprint Action → IA_Sprint"
    echo "☐ Crouch Action → IA_Crouch"
    echo "☐ Fire Action → IA_Fire"
    echo "☐ Aim Action → IA_Aim"
    echo "☐ Reload Action → IA_Reload"
    echo "☐ Melee Action → IA_Melee"
    echo "☐ Interact Action → IA_Interact"
    echo ""
    echo "【Character|Movement 类别】"
    echo "☐ Walk Speed → 500.0"
    echo "☐ Sprint Speed → 800.0"
    echo ""
    echo "【Character|Camera 类别】"
    echo "☐ Base Turn Rate → 45.0"
    echo "☐ Base Look Up Rate → 45.0"
    echo "☐ Aim FOV → 55.0"
    echo ""
    echo "【Mesh 类别】"
    echo "☐ Mesh → Skeletal Mesh → [选择角色模型]"
    echo "☐ Mesh → Animation Class → [选择动画蓝图]"
    echo ""
}

# 生成测试步骤
generate_test_steps() {
    echo ""
    echo "======================================"
    echo "  测试步骤"
    echo "======================================"
    echo ""
    echo "1. 创建测试地图"
    echo "   - File → New Level → Default"
    echo "   - 保存为 Content/Maps/TestMap"
    echo ""
    echo "2. 配置 World Settings"
    echo "   - GameMode Override → BP_TPSGameMode"
    echo "   - Default Pawn Class → BP_TPSCharacter"
    echo ""
    echo "3. 添加 Player Start"
    echo "   - Place Actors → Player Start"
    echo ""
    echo "4. 运行测试 (Play)"
    echo ""
    echo "5. 测试以下功能："
    echo "   ☐ W/A/S/D - 移动"
    echo "   ☐ Mouse - 视角"
    echo "   ☐ Space - 跳跃"
    echo "   ☐ Left Shift - 冲刺"
    echo "   ☐ Left Control - 蹲伏"
    echo "   ☐ Left Mouse - 射击（检查 Output Log）"
    echo "   ☐ Right Mouse - 瞄准（FOV 变化）"
    echo "   ☐ R - 装弹（检查 Output Log）"
    echo ""
}

# 主菜单
echo "选择要生成的内容："
echo "1. Input Actions 配置文本"
echo "2. 角色蓝图配置检查清单"
echo "3. 测试步骤"
echo "4. 全部生成"
echo "5. 退出"
echo ""
read -p "请输入选项 (1-5): " choice

case $choice in
    1)
        generate_input_actions
        ;;
    2)
        generate_character_checklist
        ;;
    3)
        generate_test_steps
        ;;
    4)
        generate_input_actions
        generate_character_checklist
        generate_test_steps
        ;;
    5)
        echo "退出"
        exit 0
        ;;
    *)
        echo "无效选项"
        ;;
esac

echo ""
echo "完成！"
