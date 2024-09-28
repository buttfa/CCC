/**
 * @file help.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <help.h>

/**
 * @brief help的条件函数
 * 
 * @return true CCC命令行参数满足help指令格式
 * @return false CCC命令行参数不满足help指令格式
 */
bool cdt_help(int argc, char** argv) {
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 打印帮助信息
 * 
 */
void printfHelp(int argc, char** argv) {
    printf("Usage: ccc [OPTION]\n");
    printf("Options:-\n");
    printf("  --help        display this help and exit\n");
    printf("  --version     display version information and exit\n");
    printf("  ccc_file      compile based on ccc_file\n");
    printf("Report bugs to <https://github.com/buttfa/CCC/issues>\n");
}