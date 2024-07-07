#ifndef __PARSECCC_H__
#define __PARSECCC_H__

#include <stdio.h>
#include <stdlib.h>
#include <ccc.h>
#include <compile.h>

struct ARG{
    int* argc;
    char** argv;
};

/**
 * @brief 解析ccc文件中的内容填入ccc文件信息
 * 
 * @param ccc_path 
 */
void parseCCC(char* ccc_path);



#endif