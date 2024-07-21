#ifndef __COMPILE_TASK_H__
#define __COMPILE_TASK_H__

#include <stdlib.h>
#include <parseCCC.h>
#include <checkCCC.h>
#include <getHeader.h>
#include <getSll.h>
#include <getDll.h>
#include <getSource.h>
#include <getObjReliance.h>
#include <getTargetReliance.h>
 
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
    char* obj_files;

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
    char* output_path;

    char* library_path;

    struct reliance* reliance_list;
    struct reliance* target_reliance;
} compileTask;

/**
 * @brief 处理任务
 * 
 * @param task 
 */
void handTask(struct COMPILE_TASK task);

/**
 * @brief 释放任务
 * 
 * @param task 
 */
void freeTask(struct COMPILE_TASK* task);

#endif
