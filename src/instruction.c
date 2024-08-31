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
    // struct instruction
    // add_instruction(instruction_help_version);
/****************************************************************************/    
    // 添加help指令
    struct instruction* help = (struct instruction*)malloc(sizeof(struct instruction));
    memset(help, 0, sizeof(struct instruction));
    help->name = (char*)malloc(strlen("help") + 1);
    memset(help->name, 0, strlen("help") + 1);
    strcat(help->name, "help");
    help->cdt_func = cdt_help;
    help->func = printfHelp;
    add_instruction(help);
/****************************************************************************/
    // 添加version指令
    struct instruction* version = (struct instruction*)malloc(sizeof(struct instruction));
    memset(version, 0, sizeof(struct instruction));
    version->name = (char*)malloc(strlen("version") + 1);
    memset(version->name, 0, strlen("version") + 1);
    strcat(version->name, "version");
    version->cdt_func = cdt_version;
    version->func = printfVersion;
    add_instruction(version);
/****************************************************************************/
    // // 添加clean指令
    // struct instruction* clean = (struct instruction*)malloc(sizeof(struct instruction));
    // memset(clean, 0, sizeof(struct instruction));
    // clean->name = (char*)malloc(strlen("clean") + 1);
    // memset(clean->name, 0, strlen("clean") + 1);
    // strcat(clean->name, "clean");
    // clean->cdt_func = cdt_clean;
    // clean->func = clean_func;
    // add_instruction(clean);
/****************************************************************************/
    // 添加template指令
    struct instruction* template = (struct instruction*)malloc(sizeof(struct instruction));
    memset(template, 0, sizeof(struct instruction));
    template->name = (char*)malloc(strlen("template") + 1);
    memset(template->name, 0, strlen("template") + 1);
    strcat(template->name, "template");
    template->cdt_func = cdt_template;
    template->func = template_func;
    add_instruction(template);
/****************************************************************************/
    // 添加task指令
    struct instruction* task = (struct instruction*)malloc(sizeof(struct instruction));
    memset(task, 0, sizeof(struct instruction));
    task->name = (char*)malloc(strlen("task") + 1);
    memset(task->name, 0, strlen("task") + 1);
    strcat(task->name, "task");
    task->cdt_func = cdt_task;
    task->func = task_func;
    add_instruction(task);
}

/**
 * @brief 添加指令到指令链表
 * 
 * @param instruction 
 */
void add_instruction(struct instruction *instruction) {
    if (instructions == NULL) {
        instructions = instruction;
    } else {
        struct instruction *tmp = instructions;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = instruction;
    }
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
        free(current->name); // 释放 name 字段
        free(current);       // 释放当前指令结构体
        current = next;
    }

    instructions = NULL; // 清空指令链表头指针
}