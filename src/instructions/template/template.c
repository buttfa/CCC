#include "template.h"

/**
 * @brief template指令的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
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
 * @param argc 
 * @param argv 
 */
void template_func(int argc, char **argv) {
    // 如果格式为ccc new project_name，则在运行目录下创建一个名为project_name的默认模板项目
    if (argc == 3 && (strcmp(argv[1], "newc")==0||strcmp(argv[1], "newcpp")==0)) {
        createDefaultTemplateProject(argv[2], argv[1]+3);
    }
}