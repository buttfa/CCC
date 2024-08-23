/**
 * @file version.c
 * @author  buttfa (1662332017@qq.com)
 * @brief version指令的实现文件
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <version.h>

/**
 * @brief version的条件函数
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数
 * @return true 传入的参数符合version的格式
 * @return false 传入的参数不符合version的格式
 */
bool cdt_version(int argc, char** argv) {
    if (argc == 2 &&(strcmp(argv[1], "version") == 0 || strcmp(argv[1], "-v") == 0)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 打印版本信息
 * 
 */
void printfVersion() {
    printf("CCC version:");
    printf(CCC_VERSION);
    printf("\n");
}