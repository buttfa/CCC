#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
/**
 * @file template.h
 * @author  buttfa (1662332017@qq.com)
 * @brief template指令的头文件，模板相关。
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "defaultTemplate.h"

/**
 * @brief template指令的条件函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 * @return true 命令行参数符合template格式
 * @return false 命令行参数不符合template格式
 */
bool cdt_template(int argc, char** argv);

/**
 * @brief template指令的函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 */
void template_func(int argc, char **argv);

#endif