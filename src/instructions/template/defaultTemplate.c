/**
 * @file defaultTemplate.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 创建默认模板项目的具体实现
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "defaultTemplate.h"

/**
 * @brief 创建文件夹
 * 
 * @param folder_path 需要创建的文件夹路径
 */
static void createFolder(char* folder_path) {
    // 创建文件夹
    char* cmd = (char*)malloc(strlen("mkdir ")+strlen(folder_path)+1);
    sprintf(cmd, "mkdir %s", folder_path);
    system(cmd); 

    // 释放内存
    free(cmd);
}

/**
 * @brief 创建包含指定内容的文件
 * 
 * @param file_path 需要写入的文件路径
 * @param content 需要写入的内容
 */
static void createFileWithSpecifyContent(char* file_path, char* content) {
    // 创建文件
    FILE* fp = fopen(file_path, "w");

    // 写入内容
    fprintf(fp, "%s", content);

    // 关闭文件
    fclose(fp);
}

/**
 * @brief 在运行目录下创建一个名为project_name的默认模板项目
 * 
 * @param project_name 工程名称
 * @param project_type 工程类型
 */
void createDefaultTemplateProject(char* project_name, char* project_type) {
    // 创建工程文件夹
    createFolder(project_name);

    // 创建工程文件夹下的文件夹
    char folder_path[256];
    // 创建build文件夹
    sprintf(folder_path, "%s/build", project_name);
    createFolder(folder_path);
    // 创建obj文件夹
    sprintf(folder_path, "%s/build/obj", project_name);
    createFolder(folder_path);
    // 创建doc文件夹
    sprintf(folder_path, "%s/doc", project_name);
    createFolder(folder_path);
    // 创建src文件夹
    sprintf(folder_path, "%s/src", project_name);
    createFolder(folder_path);
    // 创建inc文件夹
    sprintf(folder_path, "%s/inc", project_name);
    createFolder(folder_path);
    // 创建lib文件夹
    sprintf(folder_path, "%s/lib", project_name);
    createFolder(folder_path);
    // 创建test文件夹
    sprintf(folder_path, "%s/test", project_name);
    createFolder(folder_path);

    // 写入ccc文件信息
    char file_path[1024];char file_content[4096]; char compiler_linker[1024]; char target_type[1024];
    sprintf(file_path, "%s/%s.ccc", project_name, project_name);
    if (strcmp(project_type, "c")==0) {
        sprintf(compiler_linker, "gcc");
        sprintf(target_type, "c");
    } else if (strcmp(project_type, "cpp")==0) {
        sprintf(compiler_linker, "g++");
        sprintf(target_type, "c++");
    }
    sprintf(file_content, "\
[<task>%s]\n\
target_type = %s\n\
compiler = %s\n\
linker = %s\n\
source_folder_path = src\n\
header_folder_path = inc\n\
obj_path = build/obj\n\
output_path = build\n\
library_path = lib\n\n\
\
[<shell>run]\n\
(null)compile=ccc %s.ccc\n\
(null)run=./build/%s", project_name, target_type, compiler_linker, compiler_linker, project_name, project_name);
    createFileWithSpecifyContent(file_path, file_content);

    // 创建初始源文件
    // C 文件
    sprintf(file_path, "%s/src/%s.%s", project_name, project_name, project_type);
    if (strcmp(project_type, "c")==0) {
    sprintf(file_content, "\
#include <stdio.h>\n\n\
int main() {\n\
    printf(\"Hello %s!\\n\");\n\
    return 0;\n\
}", project_name);
    }
    // C++ 文件
    else if (strcmp(project_type, "cpp")==0) {
    sprintf(file_content, "\
#include <iostream>\n\n\
int main() {\n\
    std::cout << \"Hello %s!\" << std::endl;\n\
    return 0;\n\
}", project_name);
    }
    createFileWithSpecifyContent(file_path, file_content);
}