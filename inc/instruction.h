#ifndef __STRUCTION_H__
#define __STRUCTION_H__
/**
 * @file instruction.h
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC指令框架的头文件，定义了指令结构体，并使用指令链表统一管理指令。
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string.h>

#include "help.h"
#include "version.h"
#include "task.h"
#include "clean.h"
#include "template.h"

/**
 * @brief 定义了指令结构体
 * 
 */
struct instruction {
    char *name;
    bool (*cdt_func)(int argc, char** argv);
    void (*func)(int argc, char** argv);
    struct instruction *next;
};

/**
 * @brief 指令链表
 * 
 */
extern struct instruction* instructions;

/**
 * @brief 初始化指令链表
 * 
 */
void init_instructions();

/**
 * @brief 添加指令到指令链表
 * 
 * @param instruction 需要添加到指令链表的指令结构体
 */
void add_instruction(struct instruction *instruction);

/**
 * @brief 释放指令链表
 * 
 */
void free_instructions();
#endif