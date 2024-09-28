/**
 * @file instruction.c
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC指令框架的实现。如果需要添加新的指令，请在init_instructions函数中添加。
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <instruction.h>

/**
 * @brief 指令链表
 * 
 */
struct instruction* instructions = NULL;

/**
 * @brief 初始化指令链表
 * 
 */
void init_instructions() {
/****************************************************************************/    
    // 添加help指令
    append_instruction(cdt_help, printfHelp);
/****************************************************************************/
    // 添加version指令
    append_instruction(cdt_version, printfVersion);
/****************************************************************************/
    // 添加template指令
    append_instruction(cdt_template, template_func);
/****************************************************************************/
    // 添加task指令
    append_instruction(cdt_task, task_func);
}

/**
 * @brief 在指令链表末尾添加指令
 * 
 * @param cdt_func 指令执行的条件函数
 * @param func 指令运行的函数
 * @return true 追加成功
 * @return false 追加失败，一般是因为传入的参数中包含空指针。
 */
bool append_instruction(bool (*cdt_func)(int argc, char** argv), void (*func)(int argc, char** argv)) {
    // 检查参数是否合法
    if (cdt_func == NULL || func == NULL)
        return false;

    // 创建新的指令结构体
    struct instruction *new_instruction = (struct instruction*)malloc(sizeof(struct instruction));
    new_instruction->cdt_func = cdt_func;
    new_instruction->func = func;
    new_instruction->next = NULL;

    // 将新指令添加到指令链表末尾
    if (instructions == NULL) {
        instructions = new_instruction;
    }
    else {
        struct instruction *tmp = instructions;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_instruction;
    }
    return true;
}

/**
 * @brief 释放指令链表
 * 
 */
void free_instructions(void)
{
    struct instruction *current = instructions;
    struct instruction *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);       // 释放当前指令结构体
        current = next;
    }

    instructions = NULL; // 清空指令链表头指针
}