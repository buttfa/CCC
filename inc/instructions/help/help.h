#ifndef __HELP_H__
#define __HELP_H__
/**
 * @file help.h
 * @author  buttfa (1662332017@qq.com)
 * @brief help指令的头文件
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief help的条件函数
 * 
 * @return true CCC命令行参数满足help指令格式
 * @return false CCC命令行参数不满足help指令格式
 */
bool cdt_help(int argc, char** argv);

/**
 * @brief 打印帮助信息
 * 
 */
void printfHelp();
#endif