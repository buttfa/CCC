#ifndef __COMPILE_H__
#define __COMPILE_H__

#include <instruction.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <parseCCC.h>
#include <checkCCC.h>
#include <getHeader.h>
#include <getSll.h>
#include <getDll.h>
#include <getSource.h>
#include <getObjReliance.h>
#include <getTargetReliance.h>
#include <unistd.h>

// .ccc文件信息
extern char* target_type;

extern char* compiler;
extern char* compile_flags;

extern char* linker;
extern char* link_flags;

extern char* source_sig_files;
extern char* source_folder_path;
extern char* header_sig_files;
extern char* header_folder_path;

extern char* sll_sig_files;
extern char* sll_folder_path;
extern char* dll_sig_files;
extern char* dll_folder_path;

extern char* obj_path;
extern char* output_path;

extern char* library_path;

extern char ccc_file_path[128];
extern char ccc_file_name[128];

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

    char* sll_sig_files;
    char* sll_folder_path;
    char* dll_sig_files;
    char* dll_folder_path;

    char* obj_path;
    char* output_path;

    char* library_path;

    char ccc_file_path[512];
    char run_path[512];
    char ccc_file_name[512];
} compileTask;

/**
 * @brief compile的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_compile(int argc, char** argv);

/**
 * @brief 编译函数
 * 
 * @param argc 
 * @param argv 
 */
void compile_func(int argc, char** argv);

#endif