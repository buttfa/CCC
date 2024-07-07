#ifndef __VEERSION_H__
#define __VEERSION_H__

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * @brief CCC版本
 * 
 */
#define CCC_VERSION "0.0.1"

/**
 * @brief version的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_version(int argc, char** argv);

/**
 * @brief 打印版本信息
 * 
 */
void printfVersion();

#endif 