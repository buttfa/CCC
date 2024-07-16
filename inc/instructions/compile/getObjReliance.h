#ifndef __GETOBJRELIANCE_H__
#define __GETOBJRELIANCE_H__

#include <ccc.h>
#include <compile.h>
#include <file.h>
#include <reliance.h>
#include <compileTask.h>

extern char run_path[128];

// /**
//  * @brief 中间文件组
//  * 
//  */
// extern char* obj_files;

// /**
//  * @brief 中间文件依赖列表
//  * 
//  */
// extern struct reliance* reliance_list;

/**
 * @brief 为传入的.c/.cpp文件对应的.o文件创建依赖
 * 
 * @param source_file_path 
 */
void addRelianceList(char* source_file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印依赖列表
 * 
 */
void printfRelianceList(struct COMPILE_TASK* task);

/**
 * @brief 释放依赖列表内存 
 * 
 */
void freeRelianceList(struct COMPILE_TASK* task);

/**
 * @brief 根据reliance_list创建中间文件组
 * 
 */
void createObjFiles(struct COMPILE_TASK* task);

#endif