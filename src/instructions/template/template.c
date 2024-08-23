/**
 * @file template.c
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC模板的实现文件
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "template.h"

/**
 * @brief template指令的条件函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 * @return true 命令行参数符合template格式
 * @return false 命令行参数不符合template格式
 */
bool cdt_template(int argc, char** argv) {
    if (argc == 3 && (strcmp(argv[1], "newc")==0||strcmp(argv[1], "newcpp")==0))
        return true;
    else 
        return false;
}

/**
 * @brief template指令的函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 */
void template_func(int argc, char **argv) {
    // 如果格式为ccc new project_name，则在运行目录下创建一个名为project_name的默认模板项目
    if (argc == 3 && (strcmp(argv[1], "newc")==0||strcmp(argv[1], "newcpp")==0)) {
        createDefaultTemplateProject(argv[2], argv[1]+3);
    }
}