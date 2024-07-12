#include <ccc.h>
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
        printf("[CCC]Please enter ccc help or ccc -h for help.\n");
    }

    // 释放指令链表
    free_instructions();
}