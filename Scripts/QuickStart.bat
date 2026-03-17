@echo off
REM UE_TPS_Project - Windows 快速启动脚本

echo ======================================
echo   UE TPS Project - 快速启动向导
echo ======================================
echo.

echo 正在检查 Unreal Engine 项目文件...
if exist "TPSProject.uproject" (
    echo [OK] 找到项目文件
) else (
    echo [ERROR] 未找到 TPSProject.uproject
    echo 请先在 Unreal Engine 中创建项目
    pause
    exit /b 1
)

echo.
echo 请选择操作：
echo.
echo 1. 生成 Visual Studio 项目文件
echo 2. 打开项目（UE 编辑器）
echo 3. 打开项目文件夹
echo 4. 查看文档
echo 5. 退出
echo.
set /p choice="请输入选项 (1-5): "

if "%choice%"=="1" (
    echo.
    echo 正在生成 Visual Studio 项目文件...
    echo 右键点击 TPSProject.uproject → Generate Visual Studio project files
    echo 或者运行以下命令：
    echo   dotnet build Source/TPSProject/TPSProject.csproj
    echo.
    pause
) else if "%choice%"=="2" (
    echo.
    echo 正在打开 Unreal Engine...
    start TPSProject.uproject
) else if "%choice%"=="3" (
    echo.
    echo 正在打开项目文件夹...
    explorer .
) else if "%choice%"=="4" (
    echo.
    echo 正在打开文档...
    start README.md
) else if "%choice%"=="5" (
    exit /b 0
) else (
    echo 无效选项
    pause
)

echo.
echo 完成！
pause
