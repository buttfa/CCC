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
        // Determine if necessary CCC file information is missing.
        // The necessary information includes, target_type、compiler、linker、
        // source_folder_path(or source_sig_files)、obj_path、output_path。

        checkCCC(task);
/****************************************************************************/
        // Retrieve header file directory (non essential)
        
        // 1. Retrieve the header folder directory from header_sig_files
        int header_sig_files_num = 0;
        char** header_sig_files_split = splitStringBySpace(task.header_sig_files, &header_sig_files_num);
/* Dynamic Memory 1 --^*/
        for (int i = 0; i < header_sig_files_num; i++)
            if (access(header_sig_files_split[i], F_OK)==0&&isFileWithSuffix(header_sig_files_split[i],".h"))
              addSigHeaderFolderList(header_sig_files_split[i], &task);
/* Dynamic Memory 4 --^*/
        
        
        // 2. Retrieve the header folder directory from header_folder_path, sll_folder_path, dll_folder_path, and library_path.
        // Merge header_folder_path, sll_folder_path, dll_folder_path, and library_path for ease of operation.
        char* header_folder_path_temp = (char*)malloc(hotfix_strlen(task.header_folder_path)+1+hotfix_strlen(task.sll_folder_path)+1+hotfix_strlen(task.dll_folder_path)+1+hotfix_strlen(task.library_path)+1);
/* Dynamic Memory 2 --^*/
        sprintf(header_folder_path_temp,"%s %s %s %s",
                                        task.header_folder_path != NULL ? task.header_folder_path : "" ,
                                        task.sll_folder_path != NULL ? task.sll_folder_path : "" ,
                                        task.dll_folder_path != NULL ? task.dll_folder_path : "" ,
                                        task.library_path != NULL ? task.library_path : "" );


        // Split header_folder_path_temp with spaces
        char** header_folder_path_split = splitString(header_folder_path_temp, ' ');
/* Dynamic Memory 3 --^*/ 
        // Add the folder and subfolders containing the .h file in header_folder_path_stlit[i] to 
        // the header_folder_list in task. (Check before each addition to avoid duplicate additions)
        for (int i = 0; header_folder_path_split[i] != NULL; i++)
            if (hotfix_strlen(header_folder_path_split[i]) != 0)
                addHeaderFolderList(header_folder_path_split[i], &task);
/* Dynamic Memory 4 --^*/
        // printfHeaderFolderList(&task); /* print header_folder_list */



        // 3. Create header_folders based on header_folder_list
        createHeaderFolders(&task);
/* Dynamic Memory header_folders --^ */
        // printf("header_folders: %s\n", task.header_folders); /* print header_folders */
/****************************************************************************/
        // Retrieve static link library file (non essential)
        
        // 1. Retrieve sll_sig_files
        int sll_sig_files_num = 0;
        char** sll_sig_files_split = splitStringBySpace(task.sll_sig_files, &sll_sig_files_num);
/* Dynamic Memory 5 --^ */
        // Add the .a file from the sll_sig_files_split[i] folder to the sll_list.
        for(int i = 0; i < sll_sig_files_num; i++)
            if (access(sll_sig_files_split[i], F_OK)==0&&isFileWithSuffix(sll_sig_files_split[i], ".a"))
                addSllfileToList(sll_sig_files_split[i], &task);
/* Dynamic Memory 8 --^ */


        // Merge sll_folder_path and library_path for ease of operation.
        char* sll_folder_path_temp = (char*)malloc(hotfix_strlen(task.sll_folder_path)+hotfix_strlen(task.library_path)+2);
/* Dynamic Memory 6 --^ */ 
        sprintf(sll_folder_path_temp,"%s %s",
                                        task.sll_folder_path != NULL ? task.sll_folder_path : "" ,
                                        task.library_path != NULL ? task.library_path : "" );


        // Split sll_folder_path_temp with spaces
        char** sll_folder_path_split = splitString(sll_folder_path_temp, ' ');
/* Dynamic Memory 7 --^ */ 
        // 2. Add the .a file from the sll_folder_path_split[i] folder to the sll_list.
        for (int i = 0; sll_folder_path_split[i] != NULL; i++)
            if (hotfix_strlen(sll_folder_path_split[i]) != 0)
                addSlllist(sll_folder_path_split[i], &task);
/* Dynamic Memory 8 --^ */ 
        // printfSlllist(); /*  print sll_list */


        // 3. Create sll_files based on sll_list
        createSllFiles(&task);
/* Dynamic Memory sll_files --^ */
        // printf("sll_files: %s\n", task.sll_files); /* print sll_files */
/****************************************************************************/
        // Retrieve dynamic link library file (non essential)
        
        // 1. Retrieve dll_sig_files
        int dll_sig_files_num = 0;
        char** dll_sig_files_split = splitStringBySpace(task.dll_sig_files, &dll_sig_files_num);
/* Dynamic Memory 9 --^*/
        // Add the .so file from the dll_sig_files_split[i] folder to the dll_list.
        for(int i = 0; i < dll_sig_files_num; i++) 
            if (access(dll_sig_files_split[i], F_OK)==0&&isFileWithSuffix(dll_sig_files_split[i], ".so"))
                addDllfileToList(dll_sig_files_split[i], &task);
/* Dynamic Memory 12 --^*/


        // Merge dll_folder_path and library_path for ease of operation.
        char* dll_folder_path_temp = (char*)malloc(hotfix_strlen(task.dll_folder_path)+hotfix_strlen(task.library_path)+2);
/* Dynamic Memory 10 --^*/
        sprintf(dll_folder_path_temp,"%s %s",
                                        task.dll_folder_path != NULL ? task.dll_folder_path : "" ,
                                        task.library_path != NULL ? task.library_path : "" );


        // Split dll_folder_path_temp with spaces
        char** dll_folder_path_split = splitString(dll_folder_path_temp, ' ');
/* Dynamic Memory 11 --^*/
        // 2. Add the .so file from the dll_folder_path_split[i] folder to the dll_list.
        for (int i = 0; dll_folder_path_split[i] != NULL; i++)
            if (hotfix_strlen(dll_folder_path_split[i]) != 0)
                addDlllist(dll_folder_path_split[i],&task);
/* Dynamic Memory 12 --^*/
        // printfDlllist(); /* print dll_list */


        // 3. Create dll_files based on dll_list
        createDllFiles(&task);
/* Dynamic Memory dll_files --^ */
        // printf("dll_files: %s\n", task.dll_files); /* print dll_files */
/****************************************************************************/
        // Retrieve source_sig_files
        int source_sig_files_num = 0;
        char** source_sig_files_split = splitStringBySpace(task.source_sig_files, &source_sig_files_num);
/* Dynamic Memory 13 --^ */
        // 1. Retrieve source_sig_files
        for (int i = 0; i < source_sig_files_num; i++)
            if (access(source_sig_files_split[i], F_OK)==0)
                addSourcefileToList(source_sig_files_split[i], &task);
/* Dynamic Memory source_list --^ */


        // Merge source_folder_path and library_path for ease of operation.
        char* source_folder_path_temp = (char*)malloc(hotfix_strlen(task.source_folder_path)+hotfix_strlen(task.library_path)+2);
/* Dynamic Memory 14 --^ */
        sprintf(source_folder_path_temp,"%s %s",
                                        task.source_folder_path != NULL ? task.source_folder_path : "" ,
                                        task.library_path != NULL ? task.library_path : "" );


        // Split source_folder_path_temp with spaces
        char** source_folder_path_split = splitString(source_folder_path_temp, ' ');
/* Dynamic Memory 15 --^ */
        // 2. Add the .c/.cpp file from the source_folder_path_split[i] folder to the source_list.
        for (int i = 0; source_folder_path_split[i] != NULL; i++)
            if (hotfix_strlen(source_folder_path_split[i]) != 0)
                addSourcelist(source_folder_path_split[i], &task);
/* Dynamic Memory source_list --^ */
        // printfSourcelist(); /* print source_list */
/****************************************************************************/
        // Create reliances
        struct file_node* source_file = task.source_list;
        while (source_file != NULL) {
            addRelianceList(source_file->file_path, &task);
/* Dynamic Memory reliance_list --^ */
            source_file = source_file->next;
        }
        // printfRelianceList(); /* print reliance_list */
/****************************************************************************/
        // Create target_reliance
        createTargetReliance(&task);
/* Dynamic Memory target_reliance --^ */
        // printfTargetReliance(); /* print target_reliance */

/****************************************************************************/
        // Generate obj_files
        createObjFiles(&task);
/* Dynamic Memory obj_files --^ */
/****************************************************************************/
        // Handle reliance
        handleReliance(&task);

/****************************************************************************/
        freeSplitResult(header_sig_files_split); header_sig_files_split = NULL;
/* Release memory 1 --^ */ 
        free(header_folder_path_temp); header_folder_path_temp = NULL;
/* Release memory 2 --^ */ 
        freeSplitResult(header_folder_path_split); header_folder_path_split = NULL;
/* Release memory 3 --^ */
        freeHeaderFolderList(&task); 
/* Release memory 4 --^ */


        freeSplitResult(sll_sig_files_split); sll_sig_files_split = NULL;
/* Release memory 5 --^ */ 
        free(sll_folder_path_temp); sll_folder_path_temp = NULL;
/* Release memory 6 --^ */
        freeSplitResult(sll_folder_path_split); sll_folder_path_split = NULL;
/* Release memory 7 --^ */ 
        freeSlllist(&task);
/* Release memory 8 --^ */  


        freeSplitResult(dll_sig_files_split); dll_sig_files_split = NULL;
/* Release memory 9 --^ */ 
        free(dll_folder_path_temp); dll_folder_path_temp = NULL;
/* Release memory 10 --^ */
        freeSplitResult(dll_folder_path_split); dll_folder_path_split = NULL;
/* Release memory 11 --^ */
        freeDlllist(&task);
/* Release memory 12 --^ */ 


        freeSplitResult(source_sig_files_split);
/* Release memory 13 --^ */
        free(source_folder_path_temp);
/* Release memory 14 --^ */
        freeSplitResult(source_folder_path_split);
/* Release memory 15 --^ */


        freeRelianceList(&task);
/* Release memory reliance_list --^ */
        freeTargetReliance(&task);
/* Release memory target_reliance --^ */


        freeSourcelist(&task);
/* Release memory source_list --^ */


        freeTask(&task);
/* Release memory header_folders --^ */
/* Release memory sll_files --^ */
/* Release memory dll_files --^ */
/* Release memory obj_files --^ */
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
    free(task->header_folders);

    free(task->sll_sig_files);
    free(task->sll_folder_path);
    free(task->sll_files);
    free(task->dll_sig_files);
    free(task->dll_folder_path);
    free(task->dll_files);

    free(task->obj_path);
    free(task->obj_files);
    free(task->output_path);

    free(task->library_path);
}