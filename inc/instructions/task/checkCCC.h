#ifndef __CHECKCCC_H__
#define __CHECKCCC_H__
/**
 * @file checkCCC.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 定义检查ccc文件信息的函数
 * @version 0.1
 * @date 2024-08-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "task.h"

struct COMPILE_TASK;

/**
 * @brief 检查是否缺少必要ccc文件信息
 * 
 * @param task 
 */
void checkCCC(struct COMPILE_TASK task);

#endif