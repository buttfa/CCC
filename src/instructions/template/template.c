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
    if (argc == 3 && strcmp(argv[1], "new") == 0)
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
    printf("template\n");
}