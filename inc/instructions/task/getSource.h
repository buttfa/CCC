#ifndef __GETSOURCE_H__
#define __GETSOURCE_H__

#include <ccc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
#include <task.h>
#include <compileTask.h>
#include <file.h>

/**
 * @brief 将source_folder_path文件夹及其子文件夹中的.a文件添加到source_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param source_folder_path 
 */
void addSourcelist(const char* source_folder_path, struct COMPILE_TASK* task);

/**
 * @brief 将单个源文件添加到source_list
 * 
 */
void addSourcefileToList(char* file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印source_list
 * 
 */
void printfSourcelist(struct COMPILE_TASK* task);

/**
 * @brief 释放source_list
 * 
 */
void freeSourcelist(struct COMPILE_TASK* task);
#endif