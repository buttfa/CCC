#ifndef __GETDLL_H__
#define __GETDLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
/**
 * @brief dll文件链表
 * 
 */
extern struct file_node* dll_list;

/**
 * @brief dll文件字符串
 * 
 */
extern char* dll_files;

/**
 * @brief 将dll_folder_path文件夹及其子文件夹中的.a文件添加到dll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param dll_folder_path 
 */
void addDlllist(const char* dll_folder_path);

/**
 * @brief 打印dll_list
 * 
 */
void printfDlllist();

/**
 * @brief 释放dll_list
 * 
 */
void freeDlllist();

/**
 * @brief 根据dll_list创建dll_files
 * 
 */
void createDllFiles();
#endif