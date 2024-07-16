#ifndef __GETSLL_H__
#define __GETSLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
#include <compileTask.h>

/**
 * @brief 将sll_folder_path文件夹及其子文件夹中的.a文件添加到sll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param sll_folder_path 
 */
void addSlllist(const char* sll_folder_path, struct COMPILE_TASK* task);

/**
 * @brief 将单个文件添加到sll_list中
 * 
 * @param file_path 
 */
void addSllfileToList(char* file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印sll_list
 * 
 */
void printfSlllist(struct COMPILE_TASK* task);

/**
 * @brief 释放sll_list
 * 
 */
void freeSlllist(struct COMPILE_TASK* task);

/**
 * @brief 根据sll_list创建sll_files
 * 
 */
void createSllFiles(struct COMPILE_TASK* task);
#endif