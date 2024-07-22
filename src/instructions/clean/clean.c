#include <clean.h>
/**
 * @brief clean指令的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_clean(int argc, char* argv[]) {
    if (argc == 3 && strcmp(argv[2], "clean") == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 清除编译产生的文件，包含中间文件和目标文件
 * 
 * @param arg 
 * @param argv 
 */
void clean_func(int arg, char* argv[]) {
    // 判断ccc文件是否存在，且以.ccc为后缀
    if (access(argv[1], F_OK)==0 && isFileWithSuffix(argv[1],".ccc")) {
        // 获取ccc文件路径
        hotfix_strcat(ccc_file_path,argv[1]);
/****************************************************************************/            
        // 解析.ccc文件
        // compileTask task = parseCCCtask(argv[1]); 
        ini* ccc_ini = iniParseFile(ccc_file_path);
        cleanTask task;
        for (int i = 0; i < ccc_ini->section_num; i++) {
            section* ccc_section = ccc_ini->sections[i];
            // 跳过非编译任务
            if (strlen(ccc_section->name)<=6 || strncmp(ccc_section->name, "<task>", 6) != 0)
                continue;

            // 修改section的名称
            char* task_name = strdup(ccc_section->name+6);
            free(ccc_section->name);
            ccc_section->name = task_name;

            // 生成清理任务
            printf("[CCC]Clean task: %s\n", task_name);
            task = parseCCCIni(ccc_section);
/****************************************************************************/
            // 判断是否缺少必要ccc文件信息
            // 必要信息包括，target_type、compiler、linker、
            // source_folder_path(或source_sig_files)、obj_path、output_path。
            checkCCC(task);
/****************************************************************************/
            // 根据obj_path和output_path删除指定文件
            char* cmd = (char*)malloc(hotfix_strlen("rm -rf ")+hotfix_strlen(task.obj_path)+hotfix_strlen("/*.o")+1+hotfix_strlen(task.output_path)+1+hotfix_strlen(task.target_name)+1);
            memset(cmd,0,hotfix_strlen("rm -rf ")+hotfix_strlen(task.obj_path)+hotfix_strlen("/*.o")+1+hotfix_strlen(task.output_path)+1+hotfix_strlen(task.target_name)+1);
            hotfix_strcat(cmd,"rm -rf ");
            hotfix_strcat(cmd,task.obj_path);
            hotfix_strcat(cmd,"/*.o");
            hotfix_strcat(cmd," ");
            hotfix_strcat(cmd,task.output_path);
            hotfix_strcat(cmd,"/");
            hotfix_strcat(cmd,task.target_name);

            printf("%s\n",cmd);
            system(cmd);

            free(cmd);
            // 释放内存
            printf("[CCC]Clean task: %s done\n", task_name);
            freeTask(&task);
        }
    }  else {
        printf("[CCC]The target file does not exist or does not have a. ccc suffix\n");
    }
}

