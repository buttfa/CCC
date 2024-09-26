#ifndef __GETOBJRELIANCE_H__
#define __GETOBJRELIANCE_H__

#include "task.h"
#include "file.h"
#include "reliance.h"
#include "compileTask.h"

/**
 * @brief Create dependencies for the .o files corresponding to the incoming .c/.cpp files
 * 
 * @param source_file_path .c/.cpp file path
 * @param task Task variables that require information to be filled in.
 */
void addRelianceList(char* source_file_path, struct COMPILE_TASK* task);

/**
 * @brief Printf the reliance list.
 * 
 */
void printfRelianceList(struct COMPILE_TASK* task);

/**
 * @brief Free reliance list.
 * 
 */
void freeRelianceList(struct COMPILE_TASK* task);

/**
 * @brief Create an obj_files based on relience list.
 * 
 */
void createObjFiles(struct COMPILE_TASK* task);

#endif