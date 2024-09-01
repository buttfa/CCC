#ifndef __PARSECCC_H__
#define __PARSECCC_H__
/**
 * @file parseCCC.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 解析并获取CCC编译任务所需的变量
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string.h>

#include "compileTask.h"
#include "ini.h"

struct ARG{
    int* argc;
    char** argv;
};


// /**
//  * @brief 解析ccc文件中的内容填入ccc文件信息
//  * 
//  * @param ccc_path 
//  * @return compileTask 
//  */
// struct COMPILE_TASK parseCCCtask(char* ccc_path);

/**
 * @brief 解析section中的变量填入compileTask
 * 
 * @param task_section_ptr 编译任务的section的指针 
 * @return struct COMPILE_TASK 解析所得的compileTask编译任务变量
 */
struct COMPILE_TASK parseCCCIni(section* task_section_ptr);

#endif