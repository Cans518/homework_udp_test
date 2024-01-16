# 电创小作业 —— UDP test
> 上海大学中欧工程技术学院2023~2024学年冬季学期《电子创新技术》小作业
> 作者： Mzee
> 说明： 使用Linux下C语言标准库进行简单UDP测试，实现client和server的UDP通信

## 1. 项目简介
 本项目是一个简单的UDP通信测试程序，使用C语言标准库进行通信，使用Linux系统进行测试。

## 2. 构建说明
 - 本项目已经提供了Makefile文件，使用make命令进行编译

```shell
make 
```

## 3. 项目收获
 - 了解了C语言通信标准库的使用
 - 了解C语言命令行颜色渲染
 - 了解Linux系统UDP通信的使用

## 4. 项目笔记
在C语言中可以使用ASCII码进行颜色渲染，使用方法如下：
```c
#include <stdio.h>

// 定义颜色宏
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_YELLOW  "\033[33m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN    "\033[36m"
#define ANSI_COLOR_RESET   "\033[0m"

int main() {
    // 输出红色文本
    printf("%sThis text is red.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);

    // 输出绿色文本
    printf("%sThis text is green.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);

    return 0;
}
```

### 基本颜色表
#### 前景色
```c
#define ANSI_COLOR_RESET   "\033[0m"  // 重置所有属性到默认

// 基本16色
#define ANSI_COLOR_BLACK   "\033[30m"
#define ANSI_COLOR_RED     "\033[31m"
#define ANSI_COLOR_GREEN   "\033[32m"
#define ANSI_COLOR_YELLOW  "\033[33m"
#define ANSI_COLOR_BLUE    "\033[34m"
#define ANSI_COLOR_MAGENTA "\033[35m"
#define ANSI_COLOR_CYAN    "\033[36m"
#define ANSI_COLOR_WHITE   "\033[37m"

// 高亮或浅色版本
#define ANSI_COLOR_GRAY    "\033[90m"  // 或者用作淡黑色
#define ANSI_COLOR_BRED    "\033[91m"
#define ANSI_COLOR_BGREEN  "\033[92m"
#define ANSI_COLOR_BYELLOW "\033[93m"
#define ANSI_COLOR_BBLUE   "\033[94m"
#define ANSI_COLOR_BMAGENTA "\033[95m"
#define ANSI_COLOR_BCYAN   "\033[96m"
#define ANSI_COLOR_BWHITE  "\033[97m"

// 使用示例
printf("%sRed Text%s, %sGreen Background%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
```

#### 背景色
```c
// 背景颜色
#define ANSI_BACKGROUND_BLACK   "\033[40m"
#define ANSI_BACKGROUND_RED     "\033[41m"
#define ANSI_BACKGROUND_GREEN   "\033[42m"
#define ANSI_BACKGROUND_YELLOW  "\033[43m"
#define ANSI_BACKGROUND_BLUE    "\033[44m"
#define ANSI_BACKGROUND_MAGENTA "\033[45m"
#define ANSI_BACKGROUND_CYAN    "\033[46m"
#define ANSI_BACKGROUND_WHITE   "\033[47m"

// 高亮或浅色背景版本
// 注意：这些不是标准ANSI颜色，但有些终端支持
#define ANSI_BACKGROUND_BGRAY   "\033[100m"  // 非标准，可能无效
#define ANSI_BACKGROUND_BRED    "\033[101m"
// ... 其他高亮背景颜色类似 ...

// 使用示例
printf("%sBlack text on Red Background%s\n", ANSI_BACKGROUND_RED, ANSI_COLOR_BLACK);
```

