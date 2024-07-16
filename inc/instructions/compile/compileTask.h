#ifndef __COMPILE_TASK_H__
#define __COMPILE_TASK_H__

/**
 * @brief 头文件夹链表节点
 * 
 */
struct header_folder {
    char* folder_path;
    struct header_folder* next;
};

typedef struct COMPILE_TASK{
    char* target_type;

    char* compiler;
    char* compile_flags;
    
    char* linker;
    char* link_flags;

    char* source_sig_files;
    char* source_folder_path;

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

    char* obj_path;
    char* output_path;

    char* library_path;

    char ccc_file_path[512];
    char run_path[512];
    char ccc_file_name[512];
} compileTask;

#endif
