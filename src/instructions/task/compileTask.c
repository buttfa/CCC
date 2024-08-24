/**
 * @file compileTask.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 实现编译任务相关的函数
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <compileTask.h>

/**
 * @brief 处理任务
 * 
 * @param task 需要处理的编译任务
 */
void handTask(struct COMPILE_TASK task) {
/****************************************************************************/
        // 判断是否缺少必要ccc文件信息
        // 必要信息包括，target_type、compiler、linker、
        // source_folder_path(或source_sig_files)、obj_path、output_path。
        checkCCC(task);
/****************************************************************************/
        // 获取头文件目录（非必要）
        
        // 从header_sig_files获得头文件夹目录
        // char** header_sig_files_split = splitString(header_sig_files," ");
        int* header_sig_files_num = (int*)malloc(sizeof(int));
        char** header_sig_files_split = splitStringBySpace(task.header_sig_files,header_sig_files_num);
        for (int i = 0; i < *header_sig_files_num; i++) {
            if (access(header_sig_files_split[i], F_OK)==0&&isFileWithSuffix(header_sig_files_split[i],".h")) {
                addSigHeaderFolderList(header_sig_files_split[i], &task);
            }
        }
        free(header_sig_files_num);
        
        // 将header_folder_path、sll_folder_path、dll_folder_path和library_path合并，以便操作
        char* header_folder_path_temp = (char*)malloc(hotfix_strlen(task.header_folder_path)+1+hotfix_strlen(task.sll_folder_path)+1+hotfix_strlen(task.dll_folder_path)+1+hotfix_strlen(task.library_path)+1);
        memset(header_folder_path_temp,0,hotfix_strlen(task.header_folder_path)+1+hotfix_strlen(task.sll_folder_path)+1+hotfix_strlen(task.dll_folder_path)+1+hotfix_strlen(task.library_path)+1);
        hotfix_strcat(header_folder_path_temp,task.header_folder_path);
        hotfix_strcat(header_folder_path_temp," ");
        hotfix_strcat(header_folder_path_temp,task.sll_folder_path);
        hotfix_strcat(header_folder_path_temp," ");
        hotfix_strcat(header_folder_path_temp,task.dll_folder_path);
        hotfix_strcat(header_folder_path_temp," ");
        hotfix_strcat(header_folder_path_temp,task.library_path);

        // 将header_folder_path_temp以空格分割
        char** header_folder_path_split = splitString(header_folder_path_temp, ' ');
        // 将header_folder_path_split[i]中包含.h文件的文件夹及子文件夹
        // 添加到header_folder_list中。（每次添加前会检查，避免重复添加）
        for (int i = 0; header_folder_path_split[i] != NULL; i++) {
            if (hotfix_strlen(header_folder_path_split[i]) != 0) {
                addHeaderFolderList(header_folder_path_split[i], &task);
            }
        }
        // printfHeaderFolderList(&task);
        // 根据header_folder_list创建header_folders
        createHeaderFolders(&task);
        // printf("header_folders: %s\n", task.header_folders);

        // 释放该步骤所需的临时内存
        free(header_folder_path_temp);
        freeSplitResult(header_folder_path_split);
        freeSplitResult(header_sig_files_split);
        freeHeaderFolderList(&task);
/****************************************************************************/
        // 载入静态链接库文件（非必要）
        
        // 载入sll_sig_files
        // char** sll_sig_files_split = splitString(sll_sig_files, ' ');
        int* sll_sig_files_num = (int*)malloc(sizeof(int));
        char** sll_sig_files_split = splitStringBySpace(task.sll_sig_files, sll_sig_files_num);
        // 添加到sll_list中
        for(int i = 0; i < *sll_sig_files_num; i++) {
            if (access(sll_sig_files_split[i], F_OK)==0&&isFileWithSuffix(sll_sig_files_split[i], ".a")) {
                addSllfileToList(sll_sig_files_split[i], &task);
            }
        }
        free(sll_sig_files_num);
        // printfSlllist();


        // 将sll_folder_path和library_path合并，以便操作
        char* sll_folder_path_temp = (char*)malloc(hotfix_strlen(task.sll_folder_path)+hotfix_strlen(task.library_path)+2);
        memset(sll_folder_path_temp,0,hotfix_strlen(task.sll_folder_path)+hotfix_strlen(task.library_path)+2);
        hotfix_strcat(sll_folder_path_temp,task.sll_folder_path);
        hotfix_strcat(sll_folder_path_temp," ");
        hotfix_strcat(sll_folder_path_temp,task.library_path);

        // 将sll_folder_path以空格分割
        char** sll_folder_path_split = splitString(sll_folder_path_temp, ' ');
        // 将sll_folder_path_split[i]文件夹及子文件夹中的.a文件
        // 添加到sll_list中。（每次添加前会检查，避免重复添加）
        for (int i = 0; sll_folder_path_split[i] != NULL; i++) {
            if (hotfix_strlen(sll_folder_path_split[i]) != 0) {
                addSlllist(sll_folder_path_split[i], &task);
            }
        }
        // printfSlllist();
        // 根据sll_list创建sll_files
        createSllFiles(&task);

        free(sll_folder_path_temp);
        freeSplitResult(sll_folder_path_split);
        freeSlllist(&task); 
/****************************************************************************/
        // 载入动态链接库文件（非必要）
        
        // 载入dll_sig_files
        // char** dll_sig_files_split = splitString(dll_sig_files, ' ');
        int* dll_sig_files_num = (int*)malloc(sizeof(int));
        char** dll_sig_files_split = splitStringBySpace(task.dll_sig_files, dll_sig_files_num);
        // 添加到dll_list中
        for(int i = 0; i < *dll_sig_files_num; i++) {
            if (access(dll_sig_files_split[i], F_OK)==0&&isFileWithSuffix(dll_sig_files_split[i], ".so")) {
                addDllfileToList(dll_sig_files_split[i], &task);
            }
        }
        free(dll_sig_files_num);

        // 将dll_folder_path和library_path合并，以便操作
        char* dll_folder_path_temp = (char*)malloc(hotfix_strlen(task.dll_folder_path)+hotfix_strlen(task.library_path)+2);
        memset(dll_folder_path_temp,0,hotfix_strlen(task.dll_folder_path)+hotfix_strlen(task.library_path)+2);
        hotfix_strcat(dll_folder_path_temp,task.dll_folder_path);
        hotfix_strcat(dll_folder_path_temp," ");
        hotfix_strcat(dll_folder_path_temp,task.library_path);

        // 将dll_folder_path以空格分割
        char** dll_folder_path_split = splitString(dll_folder_path_temp, ' ');
        // 将dll_folder_path_split[i]文件夹及子文件夹中的.so文件
        // 添加到dll_list中。（每次添加前会检查，避免重复添加）
        for (int i = 0; dll_folder_path_split[i] != NULL; i++) {
            if (hotfix_strlen(dll_folder_path_split[i]) != 0) {
                addDlllist(dll_folder_path_split[i],&task);
            }
        }
        // printfDlllist();
        // 根据dll_list创建dll_files
        createDllFiles(&task);

        free(dll_folder_path_temp);
        freeSplitResult(dll_folder_path_split);
        freeSplitResult(dll_sig_files_split);
/****************************************************************************/

        // 获取单个的源文件
        // char** source_sig_files_split = splitString(source_sig_files, ' ');
        int* source_sig_files_num = (int*)malloc(sizeof(int));
        char** source_sig_files_split = splitStringBySpace(task.source_sig_files, source_sig_files_num);
        // 添加到source_list中
        for (int i = 0; i < *source_sig_files_num; i++) {
            if (access(source_sig_files_split[i], F_OK)==0) {
                addSourcefileToList(source_sig_files_split[i], &task);
            }
        }
        free(source_sig_files_num);

        // 获取源文件组
        char* source_folder_path_temp;
        source_folder_path_temp = (char*)malloc(hotfix_strlen(task.source_folder_path)+hotfix_strlen(task.library_path)+2);
        memset(source_folder_path_temp,0,hotfix_strlen(task.source_folder_path)+hotfix_strlen(task.library_path)+2);
        hotfix_strcat(source_folder_path_temp,task.source_folder_path);
        hotfix_strcat(source_folder_path_temp," ");
        hotfix_strcat(source_folder_path_temp,task.library_path);


        // 将source_folder_path_tmp以空格分割
        char** source_folder_path_split = splitString(source_folder_path_temp, ' ');
        // 将source_folder_path_split[i]文件夹及子文件夹中的.c/.cpp文件
        // 添加到sources_list中。（每次添加前会检查，避免重复添加）
        for (int i = 0; source_folder_path_split[i] != NULL; i++) {
            if (hotfix_strlen(source_folder_path_split[i]) != 0) {
                addSourcelist(source_folder_path_split[i], &task);
            }
        }

        // printfSourcelist();

        free(source_folder_path_temp);
        freeSplitResult(source_folder_path_split);
        freeSplitResult(source_sig_files_split);
/****************************************************************************/
        // 计算中间文件依赖关系
        struct file_node* source_file = task.source_list;
        while (source_file != NULL) {
            addRelianceList(source_file->file_path, &task);
            source_file = source_file->next;
        }

        // printfRelianceList();
/****************************************************************************/

        // 计算目标依赖关系
        createTargetReliance(&task);
        // printfTargetReliance();

/****************************************************************************/

        // 获取中间文件组
        createObjFiles(&task);
/****************************************************************************/
        // 处理依赖
        handleReliance(&task);
}

/**
 * @brief 释放任务
 * 
 * @param task 需要释放的编译任务
 */
void freeTask(struct COMPILE_TASK* task) {
    free(task->target_name);
    free(task->target_type);

    free(task->compiler);
    free(task->compile_flags);
    
    free(task->linker);
    free(task->link_flags);

    free(task->source_sig_files);
    free(task->source_folder_path);
    free(task->header_sig_files);
    free(task->header_folder_path);

    free(task->sll_sig_files);
    free(task->sll_folder_path);
    free(task->dll_sig_files);
    free(task->dll_folder_path);

    free(task->obj_path);
    free(task->output_path);

    free(task->library_path);
}