#ifndef __COMPILE_TASK_H__
#define __COMPILE_TASK_H__
/**
 * @file compileTask.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 该头文件定义了编译任务结构体，以及编译任务相关的函数
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>

#include "parseCCC.h"
#include "checkCCC.h"
#include "getHeader.h"
#include "getSll.h"
#include "getDll.h"
#include "getSource.h"
#include "getObjReliance.h"
#include "getTargetReliance.h"
 
/**
 * @brief 编译任务结构体
 * 
 */
typedef struct COMPILE_TASK{
    char* target_name;
    char* target_type;

    char* compiler;
    char* compile_flags;
    
    char* linker;
    char* link_flags;

    char* source_sig_files;
    char* source_folder_path;
    struct file_node* source_list;

    char* header_sig_files;
    char* header_folder_path;
    struct header_folder* header_folder_list;
    char* header_folders;

    char* sll_sig_files;
    char* sll_folder_path;
    struct file_node* sll_list;
    char* sll_files;

    char* dll_sig_files;
    char* dll_folder_path;
    struct file_node* dll_list;
    char* dll_files;

    char* obj_path;
    char* obj_files;
    char* output_path;

    char* library_path;

    struct reliance* reliance_list;
    struct reliance* target_reliance;
} compileTask;

/**
 * @brief 处理任务
 * 
 * @param task 需要处理的编译任务
 */
void handTask(struct COMPILE_TASK task);

/**
 * @brief 释放任务
 * 
 * @param task 需要释放的编译任务
 */
void freeTask(struct COMPILE_TASK* task);

#endif
