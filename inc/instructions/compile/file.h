#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ctype.h>

/**
 * @brief 文件链表节点
 * 
 */
struct file_node {
    char* file_path;
    struct file_node* next;
};

/**
 * @brief 头文件夹链表节点
 * 
 */
struct header_folder {
    char* folder_path;
    struct header_folder* next;
};

/**
 * @brief 接受一个文件路径path和一个后缀字符串suffix作为
 *        参数，判断该路径对应的文件是否存在并且文件名以指定的后缀结束。
 * 
 * @param path 
 * @param suffix 
 * @return true 
 * @return false 
 */
bool isFileWithSuffix(const char *path, const char *suffix);

/**
 * @brief 将字符串str拆分成以delimiter为分隔符的数组，返回数组指针。
 * 
 * @param str 
 * @param delimiter 
 * @return char** 
 */
char **splitString(const char *str, char delimiter);

/**
 * @brief 释放分割字符串的数组。
 * 
 * @param splitResult 
 */
void freeSplitResult(char **splitResult);

/**
 * @brief 获取到filePath去除路径和后缀的文件名
 * 
 * @param filePath 
 * @return char* 
 */
char* getFileName(char* filePath);


/**
 * @brief 提取input_str中的子字符串，以空格为分隔符
 * 
 * @param input_str 
 * @param out_num_tokens 
 * @return char** 
 */
char** split_string_by_space(const char* input_str, int* out_num_tokens);

/**
 * @brief 使用于本项目的特殊strlen，当str指向NULL时，返回0
 * 
 * @param str 
 * @return int 
 */
int hotfix_strlen(char* str);

/**
 * @brief 使用于本项目的特殊strcat，当dest或str指向NULL时，不进行操作
 * 
 * @param dest 
 * @param src 
 */
void hotfix_strcat(char* dest, char* src);
#endif