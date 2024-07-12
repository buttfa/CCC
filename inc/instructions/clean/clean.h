#ifndef __CLEAN_H__
#define __CLEAN_H__

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include <compile.h>

/**
 * @brief clean指令的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_clean(int argc, char* argv[]);

/**
 * @brief 清除编译产生的文件，包含中间文件和目标文件
 * 
 * @param arg 
 * @param argv 
 */
void clean_func(int arg, char* argv[]);


#endif