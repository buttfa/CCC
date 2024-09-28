#ifndef __RELIANCE_H__
#define __RELIANCE_H__
/**
 * @file reliance.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 根据依赖关系，实现编译
 * @version 0.1
 * @date 2024-08-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>
#include <compileTask.h>
#include <task.h>

/**
 * @brief 依赖节点
 * 
 */
struct reliance {
    char* file_path;

    int reliance_num;
    char** reliant_file;

    struct reliance* next;
};

/**
 * @brief 处理中间依赖组和目标依赖，并实现编译
 * 
 * @param task 需要处理的编译任务
 */
void handleReliance(struct COMPILE_TASK* task);

#endif