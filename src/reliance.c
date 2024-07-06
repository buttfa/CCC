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
    // 处理中间依赖组
    struct reliance* reliance = reliance_list;
    while (reliance != NULL) {
        for (int i = 0; i < reliance->reliance_num; i++) {
            if (checkReliance(reliance->file_path,reliance->reliant_file[i])) {
                char* cmd = (char*)malloc(strlen(compiler)+1+strlen("-c")+1+strlen(reliance->reliant_file[0])+1+strlen("-o")+1+strlen(reliance->file_path)+1+strlen(header_folders)+1+strlen(compiler_flags)+1);
                memset(cmd,0,strlen(compiler)+1+strlen("-c")+1+strlen(reliance->reliant_file[0])+1+strlen("-o")+1+strlen(reliance->file_path)+1+strlen(header_folders)+1+strlen(compiler_flags)+1);
                strcat(cmd,compiler);
                strcat(cmd," ");
                strcat(cmd,"-c ");
                strcat(cmd,reliance->reliant_file[0]);
                strcat(cmd," -o ");
                strcat(cmd,reliance->file_path);
                strcat(cmd," ");
                strcat(cmd,header_folders);
                strcat(cmd," ");
                strcat(cmd,compiler_flags);
                system(cmd);
                printf("%s\n",cmd);
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
            char* cmd = (char*)malloc(strlen(compiler)+1+strlen(obj_files)+1+strlen(sll_files)+1+strlen(dll_files)+1+strlen("-o")+1+strlen(target->file_path)+1+strlen(linker_flags)+1);
            memset(cmd,0,strlen(compiler)+1+strlen(obj_files)+1+strlen(sll_files)+1+strlen(dll_files)+1+strlen("-o")+1+strlen(target->file_path)+1+strlen(linker_flags)+1);
            strcat(cmd,compiler);
            strcat(cmd," ");
            strcat(cmd,obj_files);
            strcat(cmd," ");
            strcat(cmd,sll_files);
            strcat(cmd," ");
            strcat(cmd,dll_files);
            strcat(cmd," -o ");
            strcat(cmd,target->file_path);
            strcat(cmd," ");
            strcat(cmd,linker_flags);
            system(cmd);
            printf("%s\n",cmd);
            free(cmd);
            break;
        }
    }
}