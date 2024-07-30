#ifndef __STRUCTION_H__
#define __STRUCTION_H__

#include <stdio.h>
#include <ccc.h>
#include <string.h>
#include <stdbool.h>
#include <help.h>

#include <version.h>
#include <task.h>
#include <clean.h>

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
 * @param instruction 
 */
void add_instruction(struct instruction *instruction);

/**
 * @brief 释放指令链表
 * 
 */
void free_instructions();
#endif