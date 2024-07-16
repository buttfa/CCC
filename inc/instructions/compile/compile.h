#ifndef __COMPILE_H__
#define __COMPILE_H__

#include <instruction.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <parseCCC.h>
#include <checkCCC.h>
#include <getHeader.h>
#include <getSll.h>
#include <getDll.h>
#include <getSource.h>
#include <getObjReliance.h>
#include <getTargetReliance.h>
#include <unistd.h>

// .ccc文件信息
extern char ccc_file_path[128];
extern char ccc_file_name[128];


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
void compile_func(int argc, char** argv);

#endif