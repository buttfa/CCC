/**
 * @file version.h
 * @author  buttfa (1662332017@qq.com)
 * @brief version指令的头文件
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __VEERSION_H__
#define __VEERSION_H__

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * @brief CCC版本
 * 
 */
#define CCC_VERSION "0.1.1"

/**
 * @brief version的条件函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 * @return true 传入的参数符合version的格式
 * @return false 传入的参数不符合version的格式
 */
bool cdt_version(int argc, char** argv);

/**
 * @brief 打印版本信息
 * 
 */
void printfVersion(int argc, char** argv);

#endif 