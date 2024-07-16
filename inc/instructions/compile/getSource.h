#ifndef __GETSOURCE_H__
#define __GETSOURCE_H__

#include <ccc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
#include <compile.h>
#include <compileTask.h>
// /**
//  * @brief source文件链表
//  * 
//  */
// extern struct file_node* source_list;

/**
 * @brief 将source_folder_path文件夹及其子文件夹中的.a文件添加到source_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param source_folder_path 
 */
void addSourcelist(const char* source_folder_path, struct file_node* source_list;);

/**
 * @brief 将单个源文件添加到source_list
 * 
 */
void addSourcefileToList(char* file_path, struct COMPILE_TASK* task);

/**
 * @brief 打印source_list
 * 
 */
void printfSourcelist(struct file_node* source_list;);

/**
 * @brief 释放source_list
 * 
 */
void freeSourcelist(struct COMPILE_TASK* task);
#endif