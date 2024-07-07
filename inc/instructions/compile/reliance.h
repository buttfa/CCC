#ifndef __RELIANCE_H__
#define __RELIANCE_H__

#include <sys/stat.h>
#include <getObjReliance.h>
#include <getTargetReliance.h>

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
 * @brief 目标依赖
 * 
 */
extern struct reliance* target_reliance;

/**
 * @brief 处理中间依赖组和目标依赖，并实现编译
 * 
 */
void handleReliance();

#endif