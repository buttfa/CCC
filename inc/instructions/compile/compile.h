#ifndef __COMPILE_H__
#define __COMPILE_H__

#include <instruction.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <unistd.h>
#include <compileTask.h>
#include "ini.h"

// .ccc文件信息
extern char ccc_file_path[128];


/**
 * @brief compile的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_compile(int argc, char** argv);

/**
 * @brief 编译函数
 * 
 * @param argc 
 * @param argv 
 */
void compile_func(int argc, char **argv);

/**
 * @brief 判断是否是shell任务，如果是则执行shell任务
 * 
 * @param ccc_section 
 */
void isShellTask(section *ccc_section);

/**
 * @brief 判断是否是编译任务，如果是则执行编译任务
 * 
 * @param ccc_section 
 */
void isCompileTask(section *ccc_section);

#endif