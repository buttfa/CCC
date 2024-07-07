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
    // 添加build指令
    struct instruction* compile = (struct instruction*)malloc(sizeof(struct instruction));
    memset(compile, 0, sizeof(struct instruction));
    compile->name = (char*)malloc(strlen("compile") + 1);
    memset(compile->name, 0, strlen("compile") + 1);
    strcat(compile->name, "compile");
    compile->cdt_func = cdt_compile;
    compile->func = compile_func;
    add_instruction(compile);
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