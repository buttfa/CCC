#ifndef __FILE_H__
#define __FILE_H__
/**
 * @file file.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 该头文件定义了字符串操作相关的函数和数据结构。
 * @version 0.1
 * @date 2024-08-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <ctype.h>

#ifndef __USE_MISC
/* File types for `d_type'.  */
enum
  {
    DT_UNKNOWN = 0,
# define DT_UNKNOWN	DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO	DT_FIFO
    DT_CHR = 2,
# define DT_CHR		DT_CHR
    DT_DIR = 4,
# define DT_DIR		DT_DIR
    DT_BLK = 6,
# define DT_BLK		DT_BLK
    DT_REG = 8,
# define DT_REG		DT_REG
    DT_LNK = 10,
# define DT_LNK		DT_LNK
    DT_SOCK = 12,
# define DT_SOCK	DT_SOCK
    DT_WHT = 14
# define DT_WHT		DT_WHT
  };

/* Convert between stat structure types and directory types.  */
# define IFTODT(mode)	(((mode) & 0170000) >> 12)
# define DTTOIF(dirtype)	((dirtype) << 12)
#endif

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
 * @param path 文件路径
 * @param suffix 后缀字符串
 * @return true 文件存在且文件名以指定的后缀结束
 * @return false 文件不存在或不以指定的后缀结束
 */
bool isFileWithSuffix(char *path, char *suffix);

/**
 * @brief 将字符串str拆分成以delimiter为分隔符的数组，返回数组指针。
 * 
 * @param str 需要分割的字符串
 * @param delimiter 分割符
 * @return char** 分割后的字符串数组
 */
char **splitString(char *str, char delimiter);

/**
 * @brief 释放分割字符串的数组。
 * 
 * @param splitResult 需要释放的数组指针
 */
void freeSplitResult(char **splitResult);

/**
 * @brief 获取到filePath去除路径和后缀的文件名
 * 
 * @param filePath 需要提取的文件名的文件路径
 * @return char* 提取出的文件名
 */
char* getFileName(char* filePath);


/**
 * @brief 提取input_str中的子字符串，以空格为分隔符
 * 
 * @param input_str 需要分割的字符串
 * @param out_num_tokens 分割后产生的字符串个数
 * @return char** 字符串数组
 */
char** splitStringBySpace(char* input_str, int* out_num_tokens);

/**
 * @brief 使用于本项目的特殊strlen，当str指向NULL时，返回0
 * 
 * @param str 需要获取长度的字符串
 * @return int 字符串长度
 */
int hotfix_strlen(char* str);

/**
 * @brief 使用于本项目的特殊strcat，当dest或str指向NULL时，不进行操作
 * 
 * @param dest 目标字符串
 * @param src 源字符串
 */
void hotfix_strcat(char* dest, char* src);
#endif