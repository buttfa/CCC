#ifndef __GETHEADER_H__
#define __GETHEADER_H__
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <file.h>
/**
 * @brief 头文件夹链表节点
 * 
 */
struct header_folder {
    char* folder_path;
    struct header_folder* next;
};

/**
 * @brief 哈希集合用于去重，这里简化处理，实际应用中可能需要更复杂的数据结构
 * 
 */
typedef struct {
    char** paths;
    size_t size;
} PathHashSet;

/**
 * @brief 头文件夹链表
 * 
 */
extern struct header_folder* header_folder_list;
/**
 * @brief 头文件夹字符串
 * 
 */
extern char* header_folders;

/**
 * @brief 将header_folder_path中包含.h文件的文件夹及子文件夹
 *        添加到header_folder_list中。（每次添加前会检查，避免重复添加）
 * 
 * @param header_folder_path 
 */
void addHeaderFolderList(const char* header_folder_path);

/**
 * @brief 释放header_folder_list
 * 
 */
void freeHeaderFolderList();

/**
 * @brief 根据header_folder_list创建header_folders
 * 
 */
void createHeaderFolders();

/**
 * @brief 打印头文件夹链表
 * 
 */
void printfHeaderFolderList();
#endif