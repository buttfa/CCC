#ifndef __COMPILE_H__
#define __COMPILE_H__
/**
 * @file task.h
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC编译器任务模块
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "file.h"
#include "compileTask.h"
#include "ini.h"

// .ccc文件信息
extern char ccc_file_path[128];


/**
 * @brief compile的条件函数
 * 
 * @param argc CCC的参数个数
 * @param argv CCC的参数
 * @return true 参数符合task格式
 * @return false 参数不符合task格式
 */
bool cdt_task(int argc, char** argv);

/**
 * @brief 编译函数
 * 
 * @param argc CCC的参数个数
 * @param argv CCC的参数
 */
void task_func(int argc, char **argv);
#endif