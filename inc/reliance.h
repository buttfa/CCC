#ifndef __RELIANCE_H__
#define __RELIANCE_H__

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
extern struct reliance* tartget_reliance;

#endif