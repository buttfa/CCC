#ifndef __HELP_H__
#define __HELP_H__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief help的条件函数
 * 
 * @return true 
 * @return false 
 */
bool cdt_help(int argc, char** argv);

/**
 * @brief 打印帮助信息
 * 
 */
void printfHelp();
#endif