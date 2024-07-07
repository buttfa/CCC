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
    // add_instruction(instruction_version);
    
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