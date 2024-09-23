/**
 * @file reliance.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 根据依赖关系，判断是否需要重新编译
 * @version 0.1
 * @date 2024-08-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <reliance.h>

/**
 * @brief 检查依赖是否需要更新，当target_path比reliant_path新，则返回false，否则返回true
 * 
 * @param target_path 目标文件路径
 * @param reliant_path 对应的依赖文件路径
 * @return true 需要更新
 * @return false 不需要更新
 */
static bool checkReliance(char* target_path, char* reliant_path){
    struct stat target_stat,reliant_stat;
    if (stat(target_path,&target_stat) == -1) {
        return true;
    }
    stat(reliant_path,&reliant_stat);
    if (target_stat.st_mtime > reliant_stat.st_mtime) {
        return false;
    } else {
        return true;
    }
}


/**
 * @brief 处理中间依赖组和目标依赖，并实现编译
 * 
 * @param task 需要处理的编译任务
 */
void handleReliance(struct COMPILE_TASK* task) {
    // 处理中间依赖组
    struct reliance* reliance = task->reliance_list;
    while (reliance != NULL) {
        for (int i = 0; i < reliance->reliance_num; i++) {
            if (checkReliance(reliance->file_path,reliance->reliant_file[i])) {
                char* cmd = (char*)malloc(hotfix_strlen(task->compiler)+1+hotfix_strlen("-c")+1+hotfix_strlen(reliance->reliant_file[0])+1+hotfix_strlen("-o")+1+hotfix_strlen(reliance->file_path)+1+hotfix_strlen(task->header_folders)+1+hotfix_strlen(task->compile_flags)+1);
                sprintf(cmd, "%s -c %s -o %s %s %s",
                    task->compiler != NULL ? task->compiler : "",
                    reliance->reliant_file[0] != NULL ? reliance->reliant_file[0] : "",
                    reliance->file_path != NULL ? reliance->file_path : "",
                    task->header_folders != NULL ? task->header_folders : "",
                    task->compile_flags != NULL ? task->compile_flags : "");

                printf("%s\n",cmd);
                system(cmd);
                free(cmd);
                break;
            }
        }
        reliance = reliance->next;
    }

    // 处理目标依赖
    struct reliance* target = task->target_reliance;
    char* cmd = (char*)malloc(hotfix_strlen(task->linker)+1+hotfix_strlen(task->obj_files)+1+hotfix_strlen(task->sll_files)+1+hotfix_strlen(task->dll_files)+1+hotfix_strlen("-o")+1+hotfix_strlen(target->file_path)+1+hotfix_strlen(task->link_flags)+1);
    sprintf(cmd, "%s %s %s %s %s %s %s",
        task->linker != NULL ? task->linker : "",
        task->link_flags != NULL ? task->link_flags : "",
        strcmp(task->linker,"ar") != 0 ? "-o" : "",
        target->file_path != NULL ? target->file_path : "",
        task->obj_files != NULL ? task->obj_files : "",
        task->sll_files != NULL ? task->sll_files : "",
        task->dll_files != NULL ? task->dll_files : ""
    );


    printf("%s\n",cmd);
    system(cmd);

    free(cmd);
}