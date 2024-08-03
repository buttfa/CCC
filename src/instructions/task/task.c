#include <task.h>
// .ccc文件信息
char ccc_file_path[128];

/**
 * @brief compile的条件函数
 * 
 * @param argc 
 * @param argv
 * @return true 
 * @return false 
 */
bool cdt_task(int argc, char** argv) {
    if (argc == 2 || (argc == 3 && strcmp(argv[2], "clean")!=0)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 编译函数
 * 
 * @param argc 
 * @param argv 
 */
void task_func(int argc, char** argv) {
    // 获取ccc文件路径
    hotfix_strcat(ccc_file_path,argv[1]);
    
    // 判断文件是否存在以及是否为.ccc文件
    if (access(ccc_file_path, F_OK)==0 && isFileWithSuffix(ccc_file_path,".ccc")) {
/****************************************************************************/            
        // 解析.ccc文件
        compileTask task; 
        ini* ccc_ini = iniParseFile(ccc_file_path);

        // 如果argc==3，则说明是指定任务
        if (argc == 3) {
            // 获取任务名称
            char* target_task_name = argv[2];
            
            // 遍历ccc_ini中的section
            for (int i = 0; i < ccc_ini->section_num; i++) {
                section* ccc_section = ccc_ini->sections[i];
                
                // 获取任务名称
                char* task_name = strstr(ccc_section->name, ">")+1;
                if (strstr(ccc_section->name, ">") != NULL && strcmp(target_task_name, task_name)==0) {
                    // 判断是否是编译任务
                    isCompileTask(ccc_section);

                    // 判断是否是Shell任务
                    isShellTask(ccc_section);

                    iniFree(ccc_ini);
                    exit(0);
                }
            }

            printf("[CCC]The target task does not exist\n");
            iniFree(ccc_ini);
            exit(0);
        }

        // 如果argc==2，则说明只执行第一个任务
        if (argc == 2 && ccc_ini->section_num > 0) {
            section* ccc_section = ccc_ini->sections[0];
            if (strstr(ccc_section->name, ">")==NULL || strlen(strstr(ccc_section->name, ">")+1)==0) {
                printf("[CCC]The target task does not exist\n");
                iniFree(ccc_ini);
                exit(0);
            }

            // 判断是否是编译任务
            isCompileTask(ccc_section);

            // 判断是否是Shell任务
            isShellTask(ccc_section);
            iniFree(ccc_ini);
            exit(0);
        }
    } else {
        printf("[CCC]The target file does not exist or does not have a. ccc suffix\n");
    }
}

/**
 * @brief 判断是否是shell任务，如果是则执行shell任务
 * 
 * @param ccc_section 
 */
void isShellTask(section *ccc_section) {
    if (strlen(ccc_section->name) > 7 && strncmp(ccc_section->name, "<shell>", 7) == 0) {
        // 修改section的名称
        char* task_name = strdup(ccc_section->name+7);
        free(ccc_section->name);
        ccc_section->name = task_name;

        // 执行Shell任务
        // printf("[CCC]Shell task: %s\n", task_name);
        for (int i = 0; i < ccc_section->kvp_num; i++) {
            // 如果key为NULL或null开头，则不输出key
            if (strlen(ccc_section->kvps[i]->key)>=6 && (strncmp(ccc_section->kvps[i]->key, "(NULL)",6)==0||strncmp(ccc_section->kvps[i]->key, "(null)",6)==0)){

            } else {
                printf("%s\n", ccc_section->kvps[i]->key);
            }
            system(ccc_section->kvps[i]->value);
        }

        // printf("[CCC]Shell task: %s done\n", task_name);
    }
}

/**
 * @brief 判断是否是编译任务，如果是则执行编译任务
 * 
 * @param ccc_section 
 */
void isCompileTask(section *ccc_section) {
    struct COMPILE_TASK task;
    if (strlen(ccc_section->name)>6 && strncmp(ccc_section->name, "<task>", 6) == 0) {
        // 修改section的名称
        char* task_name = strdup(ccc_section->name+6);
        free(ccc_section->name);
        ccc_section->name = task_name;

        // 执行编译任务
        // printf("[CCC]Compile task: %s\n", task_name);
        task = parseCCCIni(ccc_section);
        handTask(task);

        // 释放任务
        freeTask(&task);
        // printf("[CCC]Compile task: %s done\n", task_name);
    }
}