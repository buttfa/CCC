#ifndef __GETSLL_H__
#define __GETSLL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <file.h>
#include <dirent.h>
/**
 * @brief sll文件链表
 * 
 */
extern struct file_node* sll_list;

/**
 * @brief sll文件字符串
 * 
 */
extern char* sll_files;

/**
 * @brief 将sll_folder_path文件夹及其子文件夹中的.a文件添加到sll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param sll_folder_path 
 */
void addSlllist(const char* sll_folder_path);

/**
 * @brief 将单个文件添加到sll_list中
 * 
 * @param file_path 
 */
void addSllfileToList(char* file_path);

/**
 * @brief 打印sll_list
 * 
 */
void printfSlllist();

/**
 * @brief 释放sll_list
 * 
 */
void freeSlllist();

/**
 * @brief 根据sll_list创建sll_files
 * 
 */
void createSllFiles();
#endif