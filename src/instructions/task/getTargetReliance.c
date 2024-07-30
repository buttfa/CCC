#include <getTargetReliance.h>

/**
 * @brief 根据reliance_list、sll_list和dll_list创建目标依赖
 * 
 */
void createTargetReliance(struct COMPILE_TASK* task) {
    // 创建目标依赖
    task->target_reliance = (struct reliance*)malloc(sizeof(struct reliance));
    memset(task->target_reliance, 0, sizeof(struct reliance));
    // 写入目标file_path
    task->target_reliance->file_path = (char*)malloc(hotfix_strlen(task->output_path)+1+hotfix_strlen(task->target_name)+1);
    memset(task->target_reliance->file_path, 0, hotfix_strlen(task->output_path)+1+hotfix_strlen(task->target_name)+1);
    hotfix_strcat(task->target_reliance->file_path, task->output_path);
    hotfix_strcat(task->target_reliance->file_path, "/");
    hotfix_strcat(task->target_reliance->file_path, task->target_name);

    // 遍历reliance_list、sll_list和dll_list计算target->reliance_num
    int size = 0;
    struct reliance* reliance =  task->reliance_list;
    while (reliance != NULL) {
        size++;
        reliance = reliance->next;
    }
    struct file_node* sll =  task->sll_list;
    while (sll != NULL) {
        size++;
        sll = sll->next;
    }
    struct file_node* dll =  task->dll_list;
    while (dll != NULL) {
        size++;
        dll = dll->next;
    }
    task->target_reliance->reliance_num = size;

    // 创建reliant_file
    task->target_reliance->reliant_file = (char**)malloc(sizeof(char*)*size);
    memset(task->target_reliance->reliant_file, 0, sizeof(char*)*size);
    int index = 0;
    reliance = task->reliance_list;
    while (reliance != NULL) {
        task->target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(reliance->file_path)+1);
        memset(task->target_reliance->reliant_file[index], 0, hotfix_strlen(reliance->file_path)+1);
        hotfix_strcat(task->target_reliance->reliant_file[index], reliance->file_path);
        index++;
        reliance = reliance->next;
    }
    sll = task->sll_list;
    while (sll != NULL) {
        task->target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(sll->file_path)+1);
        memset(task->target_reliance->reliant_file[index], 0, hotfix_strlen(sll->file_path)+1);
        hotfix_strcat(task->target_reliance->reliant_file[index], sll->file_path);
        index++;
        sll = sll->next;
    }
    dll = task->dll_list;
    while (dll != NULL) {
        task->target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(dll->file_path)+1);
        memset(task->target_reliance->reliant_file[index], 0, hotfix_strlen(dll->file_path)+1);
        hotfix_strcat(task->target_reliance->reliant_file[index], dll->file_path);
        index++;
        dll = dll->next;
   }
}

/**
 * @brief 打印目标依赖信息
 * 
 */
void printfTargetReliance(struct COMPILE_TASK* task) {
    printf("Target:%s\n",task->target_reliance->file_path);
    printf("Reliance File Number:%d\n",task->target_reliance->reliance_num);
    for (int i = 0; i < task->target_reliance->reliance_num; i++) {
        printf("(%d)%s\n",i+1,task->target_reliance->reliant_file[i]);
    }
}

/**
 * @brief 释放目标依赖所使用的内存
 * 
 */
void freeTargetReliance(struct COMPILE_TASK* task) {
    if (task->target_reliance != NULL) {
        free(task->target_reliance->file_path);
        for (int i = 0; i < task->target_reliance->reliance_num; i++) {
            free(task->target_reliance->reliant_file[i]);
        }
        free(task->target_reliance->reliant_file);
        free(task->target_reliance);
    }
    
}