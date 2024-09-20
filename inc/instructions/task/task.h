#ifndef __COMPILE_H__
#define __COMPILE_H__
/**
 * @file task.h
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC compiler task module
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "compileTask.h"
#include "ini.h"

// ccc file path
extern char ccc_file_path[128];


/**
 * @brief The conditional function of the task
 * 
 * @param argc Number of parameters passed to CCC
 * @param argv Parameters passed to CCC
 * @return true The parameters conform to the task format
 * @return false The parameters do not conform to the task format
 */
bool cdt_task(int argc, char** argv);

/**
 * @brief task function
 * 
 * @param argc Number of parameters passed to CCC
 * @param argv Parameters passed to CCC
 */
void task_func(int argc, char **argv);
#endif