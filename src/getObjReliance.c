#include <getObjReliance.h>

/**
 * @brief 中间文件依赖列表
 * 
 */
struct reliance* reliance_list;

/**
 * @brief 中间文件组
 * 
 */
char* obj_files;

/**
 * @brief 将reliance节点追加到reliance_list中
 * 
 * @param reliance 
 */
void appendToRelianceList(struct reliance* reliance) {
    if (reliance_list == NULL) {
        reliance_list = reliance;
    } else {
        struct reliance * current = reliance_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = reliance;
    }
}

/**
 * @brief 为传入的.c/.cpp文件对应的.o文件创建依赖
 * 
 * @param source_file_path 
 */
void addRelianceList(char* source_file_path) {
    // 获取对应的.o文件及路径
    // char* file_name = getFileName(source_file_path);
    // char* obj_file = (char*)malloc(hotfix_strlen(run_path)+1+hotfix_strlen(obj_path)+1+hotfix_strlen(file_name)+1+hotfix_strlen(".o\0")+1);
    // memset(obj_file, 0, hotfix_strlen(run_path)+1+hotfix_strlen(obj_path)+1+hotfix_strlen(file_name)+1+hotfix_strlen(".o\0")+1);
    // hotfix_strcat(obj_file, run_path);
    // hotfix_strcat(obj_file, "/");
    // hotfix_strcat(obj_file, obj_path);
    // hotfix_strcat(obj_file, "/");
    // hotfix_strcat(obj_file, file_name);
    // hotfix_strcat(obj_file, ".o\0");
    char* file_name = getFileName(source_file_path);
    char* obj_file = (char*)malloc(hotfix_strlen(obj_path)+1+hotfix_strlen(file_name)+1+hotfix_strlen(".o\0")+1);
    memset(obj_file, 0, hotfix_strlen(obj_path)+1+hotfix_strlen(file_name)+1+hotfix_strlen(".o\0")+1);
    hotfix_strcat(obj_file, obj_path);
    hotfix_strcat(obj_file, "/");
    hotfix_strcat(obj_file, file_name);
    hotfix_strcat(obj_file, ".o\0");

    // 创建依赖节点并写入中间文件
    struct reliance *reliance = (struct reliance*)malloc(sizeof(struct reliance));
    memset(reliance, 0, sizeof(struct reliance));
    reliance->file_path = obj_file;
    // .o文件必定依赖对应的.c/.cpp文件，因此reliance_num初始值为1
    reliance->reliance_num = 1;

    // 使用system()获取源文件依赖的头文件
    char* cmd = (char*)malloc(hotfix_strlen("gcc -MM ")+hotfix_strlen(source_file_path)+1+hotfix_strlen(header_folders)+hotfix_strlen(" > tmp\0")+1);
    memset(cmd, 0, hotfix_strlen("gcc -MM ")+hotfix_strlen(source_file_path)+1+hotfix_strlen(header_folders)+hotfix_strlen(" > tmp\0")+1);
    hotfix_strcat(cmd, "gcc -MM ");
    hotfix_strcat(cmd, source_file_path);
    hotfix_strcat(cmd, " ");
    hotfix_strcat(cmd, header_folders);
    hotfix_strcat(cmd, " > tmp\0");
    system(cmd);

    // 遍历tmp文件，确定依赖文件数量
    FILE* fp = fopen("tmp", "r"); char buf[1024];
    // 跳过tmp文件前两个无关字符串
    fscanf(fp, "%s", buf);
    fscanf(fp, "%s", buf);
    while (fscanf(fp, "%s", buf) != EOF) {
        if (buf[0] != '\\') {
            // printf("%s\n", buf);
            reliance->reliance_num++;
        }     
    }
    fclose(fp);

    // 写入依赖文件路径
    reliance->reliant_file = (char**)malloc(sizeof(char*)*reliance->reliance_num);
    // 写入对应的.c/.cpp文件
    reliance->reliant_file[0] = (char*)malloc(hotfix_strlen(source_file_path)+1);
    memset(reliance->reliant_file[0], 0, hotfix_strlen(source_file_path)+1);
    hotfix_strcat(reliance->reliant_file[0], source_file_path);
    // 读取tmp文件，写入依赖的头文件
    fp = fopen("tmp", "r"); 
    // 跳过tmp文件前两个无关字符串
    fscanf(fp, "%s", buf);
    fscanf(fp, "%s", buf);
    int index = 1;
    while (fscanf(fp, "%s", buf) != EOF) {
        if (buf[0] != '\\') {
            reliance->reliant_file[index] = (char*)malloc(hotfix_strlen(buf)+1);
            memset(reliance->reliant_file[index], 0, hotfix_strlen(buf)+1);
            hotfix_strcat(reliance->reliant_file[index], buf);
            index++;
        }     
    }
    fclose(fp);

    // 删除临时文件
    remove("tmp");

    // 将依赖节点添加到依赖列表中
    appendToRelianceList(reliance);
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

/**
 * @brief 根据reliance_list创建中间文件组
 * 
 */
void createObjFiles() {
    struct reliance* temp = reliance_list;
    // 第一次遍历统计所需长度
    int length = 0;
    while (temp != NULL) {
        length += hotfix_strlen(temp->file_path)+1;
        temp = temp->next;
    }
    // 第二次遍历读取中间文件路径
    obj_files = (char*)malloc(length+1);
    memset(obj_files, 0, length+1);
    temp = reliance_list;
    while (temp != NULL) {
        hotfix_strcat(obj_files, temp->file_path);
        hotfix_strcat(obj_files, " ");
        temp = temp->next;
    }
}