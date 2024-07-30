#ifndef __GETDLL_H__
#define __GETDLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
#include <compileTask.h>

/**
 * @brief 将dll_folder_path文件夹及其子文件夹中的.a文件添加到dll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param dll_folder_path 
 */
void addDlllist(const char* dll_folder_path, struct COMPILE_TASK* task);

/**
 * @brief 将单个文件添加到dll_list中
 * 
 * @param file_path 
 */
void addDllfileToList(char* file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印dll_list
 * 
 */
void printfDlllist(struct COMPILE_TASK* task);

/**
 * @brief 释放dll_list
 * 
 */
void freeDlllist(struct COMPILE_TASK* task);

/**
 * @brief 根据dll_list创建dll_files
 * 
 */
void createDllFiles(struct COMPILE_TASK* task);
#endif