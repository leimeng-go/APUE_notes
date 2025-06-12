# VS Code APUE 项目使用指南

## ⚠️ 重要：不要使用默认的编译按钮！

VS Code 的默认编译按钮只会编译单个 `.c` 文件，导致链接错误。

## ✅ 正确的编译和运行方式：

### 方式 1：使用任务菜单（推荐）
1. 按 `Cmd+Shift+P` (macOS) 或 `Ctrl+Shift+P` (Windows/Linux)
2. 输入 `Tasks: Run Task`
3. 选择以下任务之一：
   - `Build APUE Main` - 编译项目
   - `Build and Run` - 编译并运行
   - `Run APUE` - 仅运行（需要先编译）

### 方式 2：使用快捷键
- `Cmd+B` - 编译项目
- `F5` - 编译并运行
- `Ctrl+F5` - 仅运行

### 方式 3：使用终端
```bash
./build.sh    # 编译
./main        # 运行
```

## 🐛 调试
使用 `F5` 或调试面板中的 "Debug APUE" 配置

## 📁 文件结构
```
codes/APUE/
├── main.c                          # 主程序
├── src/
│   ├── 1_UNIX_Introduction/
│   │   └── strerror_perror.c      # 第一章测试
│   └── macos_alternatives.c       # macOS 替代实现
├── build.sh                       # 构建脚本
└── .vscode/                       # VS Code 配置
```

## ❌ 避免的错误
- 不要点击编辑器右上角的"运行"按钮
- 不要使用 `Cmd+Shift+B` 然后选择默认的 clang 任务
- 确保使用我们配置的自定义任务 