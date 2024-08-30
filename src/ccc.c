/**
 * @file ccc.c
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC程序入口的源文件，通过指令链表匹配并执行指令
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <ccc.h>

/**
 * @brief CCC程序入口
 * 
 * @param argc CCC命令行参数个数
 * @param argv CCC命令行参数字符串组
 * @return int 主函数返回值
 */
int main(int argc, char* argv[]) {
    // 初始化指令链表
    init_instructions();

    struct instruction* ins = instructions;
    while (ins != NULL) {
        // 匹配指令
        if (ins->cdt_func(argc, argv)) {
            // 执行指令
            ins->func(argc, argv);
            break;
        } else {
            ins = ins->next;
        }
    }

    // 如果指令不存在，则输出错误信息
    if (ins == NULL) {
        printf("[CCC]Error: Invalid argument\n");
        printf("[CCC]Please enter ccc --help for help.\n");
    }

    // 释放指令链表
    free_instructions();
    return 0; 
}