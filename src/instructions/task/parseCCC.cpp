/**
 * @file parseCCC.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 解析并获取CCC编译任务所需的变量
 * @version 0.1
 * @date 2024-09-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parseCCC.h"


/**
 * @brief 解析section中的变量填入compileTask
 * 
 * @param task_section_ptr 编译任务的section的指针 
 * @return struct COMPILE_TASK 解析所得的compileTask编译任务变量
 */
struct COMPILE_TASK parseCCCIni(section* task_section_ptr) {
    // 创建compile_task
    struct COMPILE_TASK task;
    memset(&task, 0, sizeof(struct COMPILE_TASK));

    task.target_name = strdup(task_section_ptr->name);

    char* point = NULL;

    // 获取target_type
    task.target_type = (point = iniGetValue(task_section_ptr, (char*)"target_type")) != NULL ? strdup(point) : NULL;

    // 获取compiler
    task.compiler = (point = iniGetValue(task_section_ptr, (char*)"compiler")) != NULL ? strdup(point) : NULL;

    // 获取compile_flags
    task.compile_flags = (point = iniGetValue(task_section_ptr, (char*)"compile_flags")) != NULL ? strdup(point) : NULL;

    // 获取linker
    task.linker = (point = iniGetValue(task_section_ptr, (char*)"linker")) != NULL ? strdup(point) : NULL;

    // 获取link_flags
    task.link_flags = (point = iniGetValue(task_section_ptr, (char*)"link_flags")) != NULL ? strdup(point) : NULL;

    // 获取source_sig_files
    task.source_sig_files = (point = iniGetValue(task_section_ptr, (char*)"source_sig_files")) != NULL ? strdup(point) : NULL;

    // 获取source_folder_path
    task.source_folder_path = (point = iniGetValue(task_section_ptr, (char*)"source_folder_path")) != NULL ? strdup(point) : NULL;

    // 获取header_sig_files
    task.header_sig_files = (point = iniGetValue(task_section_ptr, (char*)"header_sig_files")) != NULL ? strdup(point) : NULL;

    // 获取header_folder_path
    task.header_folder_path = (point = iniGetValue(task_section_ptr, (char*)"header_folder_path")) != NULL ? strdup(point) : NULL;

    // 获取sll_sig_files
    task.sll_sig_files = (point = iniGetValue(task_section_ptr, (char*)"sll_sig_files")) != NULL ? strdup(point) : NULL;

    // 获取sll_folder_path
    task.sll_folder_path = (point = iniGetValue(task_section_ptr, (char*)"sll_folder_path")) != NULL ? strdup(point) : NULL;

    // 获取dll_sig_files
    task.dll_sig_files = (point = iniGetValue(task_section_ptr, (char*)"dll_sig_files")) != NULL ? strdup(point) : NULL;

    // 获取dll_folder_path
    task.dll_folder_path = (point = iniGetValue(task_section_ptr, (char*)"dll_folder_path")) != NULL ? strdup(point) : NULL;

    // 获取obj_path
    task.obj_path = (point = iniGetValue(task_section_ptr, (char*)"obj_path")) != NULL ? strdup(point) : NULL;

    // 获取output_path
    task.output_path = (point = iniGetValue(task_section_ptr, (char*)"output_path")) != NULL ? strdup(point) : NULL;

    // 获取library_path
    task.library_path = (point = iniGetValue(task_section_ptr, (char*)"library_path")) != NULL ? strdup(point) : NULL;
    
    return task;
}