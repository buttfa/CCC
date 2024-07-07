/**
 * @file ccc.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __CCC_H__
#define __CCC_H__

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

#define CCC_VERSION "0.0.1"

// .ccc文件信息
extern char* target_type;
extern char* compiler;
extern char* compiler_flags;
extern char* linker;
extern char* linker_flags;
extern char* source_folder_path;
extern char* header_folder_path;
extern char* sll_folder_path;
extern char* dll_folder_path;
extern char* obj_path;
extern char* output_path;
extern char* library_path;

extern char ccc_file_path[128];
extern char ccc_file_name[128];
// /**
//  * @brief 打印版本信息
//  * 
//  */
// void printfVersion();

// /**
//  * @brief 打印帮助信息
//  * 
//  */
// void printfHelp();

#endif