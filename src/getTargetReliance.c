#include <getTargetReliance.h>


/**
 * @brief 目标依赖
 * 
 */
struct reliance* target_reliance;


/**
 * @brief 根据reliance_list、sll_list和dll_list创建目标依赖
 * 
 */
void createTargetReliance() {
    // 创建目标依赖
    target_reliance = (struct reliance*)malloc(sizeof(struct reliance));
    memset(target_reliance, 0, sizeof(struct reliance));
    // 写入目标file_path
    target_reliance->file_path = (char*)malloc(hotfix_strlen(run_path)+1+hotfix_strlen(output_path)+1+hotfix_strlen(ccc_file_name)+1);
    memset(target_reliance->file_path, 0, hotfix_strlen(run_path)+1+hotfix_strlen(output_path)+1+hotfix_strlen(ccc_file_name)+1);
    hotfix_strcat(target_reliance->file_path, run_path);
    hotfix_strcat(target_reliance->file_path, "/");
    hotfix_strcat(target_reliance->file_path, output_path);
    hotfix_strcat(target_reliance->file_path, "/");
    hotfix_strcat(target_reliance->file_path, ccc_file_name);


    // 遍历reliance_list、sll_list和dll_list计算target->reliance_num
    int size = 0;
    struct reliance* reliance =  reliance_list;
    while (reliance != NULL) {
        size++;
        reliance = reliance->next;
    }
    struct file_node* sll =  sll_list;
    while (sll != NULL) {
        size++;
        sll = sll->next;
    }
    struct file_node* dll =  dll_list;
    while (dll != NULL) {
        size++;
        dll = dll->next;
    }
    target_reliance->reliance_num = size;

    // 创建reliant_file
    target_reliance->reliant_file = (char**)malloc(sizeof(char*)*size);
    memset(target_reliance->reliant_file, 0, sizeof(char*)*size);
    int index = 0;
    reliance = reliance_list;
    while (reliance != NULL) {
        target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(reliance->file_path)+1);
        memset(target_reliance->reliant_file[index], 0, hotfix_strlen(reliance->file_path)+1);
        hotfix_strcat(target_reliance->reliant_file[index], reliance->file_path);
        index++;
        reliance = reliance->next;
    }
    sll = sll_list;
    while (sll != NULL) {
        target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(sll->file_path)+1);
        memset(target_reliance->reliant_file[index], 0, hotfix_strlen(sll->file_path)+1);
        hotfix_strcat(target_reliance->reliant_file[index], sll->file_path);
        index++;
        sll = sll->next;
    }
    dll = dll_list;
    while (dll != NULL) {
        target_reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(dll->file_path)+1);
        memset(target_reliance->reliant_file[index], 0, hotfix_strlen(dll->file_path)+1);
        hotfix_strcat(target_reliance->reliant_file[index], dll->file_path);
        index++;
        dll = dll->next;
   }
}

/**
 * @brief 打印目标依赖信息
 * 
 */
void printfTargetReliance() {
    printf("Target:%s\n",target_reliance->file_path);
    printf("Reliance File Number:%d\n",target_reliance->reliance_num);
    for (int i = 0; i < target_reliance->reliance_num; i++) {
        printf("(%d)%s\n",i+1,target_reliance->reliant_file[i]);
    }
}

/**
 * @brief 释放目标依赖所使用的内存
 * 
 */
void freeTargetReliance() {
    free(target_reliance->file_path);
    for (int i = 0; i < target_reliance->reliance_num; i++) {
        free(target_reliance->reliant_file[i]);
    }
    free(target_reliance->reliant_file);
    free(target_reliance);
}