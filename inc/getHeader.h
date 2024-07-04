#ifndef __GETHEADER_H__
#define __GETHEADER_H__

/**
 * @brief 头文件夹链表节点
 * 
 */
struct header_folder {
    char* folder_path;
    struct header_folder* next;
};

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
void addHeaderFolderList(char* header_folder_path);

/**
 * @brief 根据header_folder_list创建header_folders
 * 
 */
void createHeaderFolders();
#endif