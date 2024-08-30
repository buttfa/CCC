#ifndef __GETDLL_H__
#define __GETDLL_H__
/**
 * @file getDll.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 定义了获取dll_sig_files、dll_folder_path和library_path中dll文件的相关操作
 * @version 0.1
 * @date 2024-08-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <dirent.h>
#include <compileTask.h>

/**
 * @brief 将dll_folder_path文件夹及其子文件夹中的.a文件添加到dll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param dll_folder_path 需要遍历的文件夹路径
 * @param task 遍历到的.a文件会添加到task->dll_list中
 */
void addDlllist(const char* dll_folder_path, struct COMPILE_TASK* task);

/**
 * @brief 将单个文件添加到dll_list中
 * 
 * @param file_path 需要添加的文件路径
 * @param task 文件会添加到task->dll_list中
 */
void addDllfileToList(char* file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印dll_list
 * 
 * @param task 包含dll_list的task
 */
void printfDlllist(struct COMPILE_TASK* task);

/**
 * @brief 释放dll_list
 * 
 * @param task 包含需要释放的dll_list的task
 */
void freeDlllist(struct COMPILE_TASK* task);

/**
 * @brief 根据dll_list创建dll_files
 * 
 * @param task 包含dll_list的task
 */
void createDllFiles(struct COMPILE_TASK* task);
#endif