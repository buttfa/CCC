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
void handleReliance() {
    int flag = 1;
    // 处理中间依赖组
    struct reliance* reliance = reliance_list;
    while (reliance != NULL) {
        for (int i = 0; i < reliance->reliance_num; i++) {
            if (checkReliance(reliance->file_path,reliance->reliant_file[i])) {
                flag = 0;
                char* cmd = (char*)malloc(hotfix_strlen(compiler)+1+hotfix_strlen("-c")+1+hotfix_strlen(reliance->reliant_file[0])+1+hotfix_strlen("-o")+1+hotfix_strlen(reliance->file_path)+1+hotfix_strlen(header_folders)+1+hotfix_strlen(compiler_flags)+1);
                memset(cmd,0,hotfix_strlen(compiler)+1+hotfix_strlen("-c")+1+hotfix_strlen(reliance->reliant_file[0])+1+hotfix_strlen("-o")+1+hotfix_strlen(reliance->file_path)+1+hotfix_strlen(header_folders)+1+hotfix_strlen(compiler_flags)+1);
                hotfix_strcat(cmd,compiler);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,"-c ");
                hotfix_strcat(cmd,reliance->reliant_file[0]);
                hotfix_strcat(cmd," -o ");
                hotfix_strcat(cmd,reliance->file_path);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,header_folders);
                hotfix_strcat(cmd," ");
                hotfix_strcat(cmd,compiler_flags);

                printf("%s\n",cmd);
                system(cmd);
                free(cmd);
                break;
            }
        }
        reliance = reliance->next;
    }

    // 处理目标依赖
    struct reliance* target = target_reliance;
    for (int i = 0; i < target->reliance_num; i++) {
        if (checkReliance(target->file_path,target->reliant_file[i])) {
            flag = 0;
            char* cmd = (char*)malloc(hotfix_strlen(linker)+1+hotfix_strlen(obj_files)+1+hotfix_strlen(sll_files)+1+hotfix_strlen(dll_files)+1+hotfix_strlen("-o")+1+hotfix_strlen(target->file_path)+1+hotfix_strlen(linker_flags)+1);
            memset(cmd,0,hotfix_strlen(linker)+1+hotfix_strlen(obj_files)+1+hotfix_strlen(sll_files)+1+hotfix_strlen(dll_files)+1+hotfix_strlen("-o")+1+hotfix_strlen(target->file_path)+1+hotfix_strlen(linker_flags)+1);
            hotfix_strcat(cmd,linker);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,linker_flags);
            if (strcmp(linker,"ar") != 0) {
                hotfix_strcat(cmd," -o ");
            } 
            hotfix_strcat(cmd,target->file_path);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,obj_files);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,sll_files);
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,dll_files);


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