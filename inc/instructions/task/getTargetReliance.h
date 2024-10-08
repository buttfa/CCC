#ifndef __GETTARGETRELIANCE_H__
#define __GETTARGETRELIANCE_H__

#include <ccc.h>
#include <reliance.h>
#include <task.h>

/**
 * @brief 根据reliance_list、sll_list和dll_list创建目标依赖
 * 
 */
void createTargetReliance(struct COMPILE_TASK* task);

/**
 * @brief 打印目标依赖信息
 * 
 */
void printfTargetReliance(struct COMPILE_TASK* task);

/**
 * @brief 释放目标依赖所使用的内存
 * 
 */
void freeTargetReliance(struct COMPILE_TASK* task);

#endif