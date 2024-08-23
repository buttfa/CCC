#ifndef __CLEAN_H__
#define __CLEAN_H__
/**
 * @file clean.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 定义clean指令的头文件
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "task.h"
#include "compileTask.h"

/**
 * @brief cleanTask结构体
 * 
 */
typedef struct COMPILE_TASK cleanTask;

/**
 * @brief clean指令的条件函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 * @return true CCC命令行参数符合clean指令的条件
 * @return false CCC命令行参数不符合clean指令的条件
 */
bool cdt_clean(int argc, char* argv[]);

/**
 * @brief 清除编译产生的文件，包含中间文件和目标文件
 * 
 * @param arg CCC命令行参数个数
 * @param argv CCC命令行参数
 */
void clean_func(int arg, char* argv[]);


#endif