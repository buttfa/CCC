#include <reliance.h>

/**
 * @brief 检查依赖是否需要更新，当target_path比reliant_path新，则返回false，否则返回true
 * 
 * @param target_path 
 * @param reliant_path 
 * @return true 
 * @return false 
 */
bool checkReliance(char* target_path, char* reliant_path){
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
 */
void handleReliance(struct COMPILE_TASK* task) {
    int flag = 1;
    // 处理中间依赖组
    struct reliance* reliance = task->reliance_list;
    while (reliance != NULL) {
        for (int i = 0; i < reliance->reliance_num; i++) {
            if (checkReliance(reliance->file_path,reliance->reliant_file[i])) {
                flag = 0;
                char* cmd = (char*)malloc(hotfix_strlen(task->compiler)+1+hotfix_strlen("-c")+1+hotfix_strlen(reliance->reliant_file[0])+1+hotfix_strlen("-o")+1+hotfix_strlen(reliance->file_path)+1+hotfix_strlen(task->header_folders)+1+hotfix_strlen(task->compile_flags)+1);
                memset(cmd,0,hotfix_strlen(task->compiler)+1+hotfix_strlen("-c")+1+hotfix_strlen(reliance->reliant_file[0])+1+hotfix_strlen("-o")+1+hotfix_strlen(reliance->file_path)+1+hotfix_strlen(task->header_folders)+1+hotfix_strlen(task->compile_flags)+1);
                hotfix_strcat(cmd,task->compiler);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,"-c ");
                hotfix_strcat(cmd,reliance->reliant_file[0]);
                hotfix_strcat(cmd," -o ");
                hotfix_strcat(cmd,reliance->file_path);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,task->header_folders);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,task->compile_flags);

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
    for (int i = 0; i < target->reliance_num; i++) {
        if (checkReliance(target->file_path,target->reliant_file[i])) {
            flag = 0;
            char* cmd = (char*)malloc(hotfix_strlen(task->linker)+1+hotfix_strlen(task->obj_files)+1+hotfix_strlen(task->sll_files)+1+hotfix_strlen(task->dll_files)+1+hotfix_strlen("-o")+1+hotfix_strlen(target->file_path)+1+hotfix_strlen(task->link_flags)+1);
            memset(cmd,0,hotfix_strlen(task->linker)+1+hotfix_strlen(task->obj_files)+1+hotfix_strlen(task->sll_files)+1+hotfix_strlen(task->dll_files)+1+hotfix_strlen("-o")+1+hotfix_strlen(target->file_path)+1+hotfix_strlen(task->link_flags)+1);
            hotfix_strcat(cmd,task->linker);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,task->link_flags);
            if (strcmp(task->linker,"ar") != 0) {
                hotfix_strcat(cmd," -o");
            } 
            hotfix_strcat(cmd, " ");
            hotfix_strcat(cmd,target->file_path);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,task->obj_files);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,task->sll_files);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,task->dll_files);


            printf("%s\n",cmd);
            system(cmd);

            free(cmd);
            break;
        }
    }

    if(flag == 1) {
        printf("[%s]All files have been compiled.\n",ccc_file_path);
    }
}