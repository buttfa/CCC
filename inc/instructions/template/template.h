#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief template指令的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_template(int argc, char** argv);

/**
 * @brief template指令的函数
 * 
 * @param argc 
 * @param argv 
 */
void template_func(int argc, char **argv);

#endif