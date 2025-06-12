#!/bin/bash

# APUE 项目构建脚本

echo "🔨 Building APUE project..."

# 源文件列表
SOURCES=(
    "main.c"
    "src/1_UNIX_Introduction/strerror_perror.c"
    "src/macos_alternatives.c"
)

# 编译器和参数
COMPILER="clang"
CFLAGS="-g -Wall -Wextra -std=c17"
OUTPUT="main"

# 检查源文件是否存在
for src in "${SOURCES[@]}"; do
    if [[ ! -f "$src" ]]; then
        echo "❌ Error: Source file $src not found!"
        exit 1
    fi
done

# 编译
echo "📝 Compiling with clang..."
$COMPILER $CFLAGS "${SOURCES[@]}" -o $OUTPUT

# 检查编译结果
if [[ $? -eq 0 ]]; then
    echo "✅ Build successful! Output: $OUTPUT"
    echo "🚀 Run with: ./$OUTPUT"
else
    echo "❌ Build failed!"
    exit 1
fi 