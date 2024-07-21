#ifndef __PARSECCC_H__
#define __PARSECCC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ccc.h>
#include <compile.h>
#include "ini.h"

struct ARG{
    int* argc;
    char** argv;
};


/**
 * @brief 解析ccc文件中的内容填入ccc文件信息
 * 
 * @param ccc_path 
 * @return compileTask 
 */
struct COMPILE_TASK parseCCCtask(char* ccc_path);

/**
 * @brief 解析section中的内容填入compileTask
 * 
 * @param ini_ptr 
 * @return struct COMPILE_TASK 
 */
struct COMPILE_TASK parseCCCIni(section* task_section_ptr);

#endif