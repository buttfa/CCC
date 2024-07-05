#include <getObjReliance.h>

/**
 * @brief 中间文件依赖列表
 * 
 */
struct reliance* reliance_list;

/**
 * @brief 为传入的.c/.cpp文件对应的.o文件创建依赖
 * 
 * @param source_file_path 
 */
void addRelianceList(const char* source_file_path) {
    // 获取对应的.o文件及路径
    char* file_name = getFileName(source_file_path);
    char* obj_file = (char*)malloc(strlen(run_path)+1+strlen(file_name)+1+strlen(".o")+1);
    memset(obj_file, 0, strlen(run_path)+1+strlen(file_name)+1+strlen(".o")+1);
    strcat(obj_file, run_path);
    strcat(obj_file, "/");
    strcat(obj_file, file_name);
    strcat(obj_file, "/");
    strcat(obj_file, ".o\0");
    free(file_name);

    // 创建依赖节点并写入中间文件
    struct reliance *reliance = (struct reliance*)malloc(sizeof(struct reliance));
    memset(reliance, 0, sizeof(struct reliance));
    reliance->file_path = obj_file;
    reliance->reliance_num = 1;



    // 将依赖节点添加到依赖列表中
    struct reliance* temp = reliance_list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = reliance;
}

/**
 * @brief 打印依赖列表
 * 
 */
void printfRelianceList() {
    struct reliance* temp = reliance_list;
    while (temp != NULL) {
        printf("%s(%d):\n", temp->file_path,temp->reliance_num);
        for (int i = 0; i < temp->reliance_num; i++) {
            printf("%s\n", temp->reliant_file[i]);
        }
        temp = temp->next;
    }
}

/**
 * @brief 释放依赖列表内存 
 * 
 */
void freeRelianceList() {
    struct reliance* current = reliance_list;
    struct reliance* next;
    while (current != NULL) {
        next = current->next;
        free(current->file_path);
        for (int i = 0; i < current->reliance_num; i++) {
            free(current->reliant_file[i]);
        }
        free(current->reliant_file);
        free(current);
        current = next;
    }
    reliance_list = NULL;
}