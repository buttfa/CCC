#ifndef __FILE_H__
#define __FILE_H__

#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>


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

#endif