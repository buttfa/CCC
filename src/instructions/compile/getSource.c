#include <getSource.h>

/**
 * @brief source文件链表
 * 
 */
struct file_node* source_list;


/**
 * @brief 检查链表中是否存在特定路径
 * 
 * @param node 
 * @param path 
 * @return int 
 */
int isPathInSourceList(const struct file_node* node, const char* path) {
    while (node != NULL) {
        if (strcmp(node->file_path, path) == 0) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

/**
 * @brief 向链表追加节点
 * 
 * @param head 
 * @param path 
 */
void appendToSourceList(struct file_node** head, const char* path) {
    struct file_node* newNode = (struct file_node*)malloc(sizeof(struct file_node));
    newNode->file_path = strdup(path);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct file_node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/**
 * @brief 将source_folder_path文件夹及其子文件夹中的.c文件添加到source_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param source_folder_path 
 */
void addSourcelist(const char* source_folder_path) {
    // 确定源文件后缀
    // char* suffix;
    // if (strcmp(target_type,"c")==0) {
    //     suffix = (char*)malloc(hotfix_strlen(".c") + 1);
    //     memset(suffix, 0, hotfix_strlen(".c") + 1);
    //     hotfix_strcat(suffix, ".c\0");
    // } else if (strcmp(target_type,"c++")==0) {
    //     suffix = (char*)malloc(hotfix_strlen(".cpp") + 1);
    //     memset(suffix, 0, hotfix_strlen(".cpp") + 1);
    //     hotfix_strcat(suffix, ".cpp\0");
    // }

    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(source_folder_path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char full_path[FILENAME_MAX];
            snprintf(full_path, FILENAME_MAX, "%s/%s", source_folder_path, ent->d_name);
            if (ent->d_type == DT_DIR) {
                // 递归遍历子目录
                addSourcelist(full_path);
            // } else if (strstr(ent->d_name, suffix) != NULL) {
            //     // 检查并添加.c文件到链表
            //     if (!isPathInSourceList(source_list, full_path)) {
            //         appendToSourceList(&source_list, full_path);
            //     }
            // }
            // } else if (strstr(ent->d_name, suffix) != NULL) {
            //     char* tmp = strstr(ent->d_name, suffix);
            //     // 检查并添加.c/.cpp文件到链表
            //     if (strcmp(tmp,suffix)==0 && !isPathInSourceList(source_list, full_path)) {
            //         appendToSourceList(&source_list, full_path);
            //     }
            // }
            } else if (strstr(ent->d_name, ".c") != NULL || strstr(ent->d_name, ".s") != NULL) {
                char* tmp_c = strstr(ent->d_name, ".c");
                char* tmp_s = strstr(ent->d_name, ".s");
                // 如果是汇编文件则直接加入
                if (tmp_s != NULL && strcmp(tmp_s,".s")==0 && !isPathInSourceList(source_list, full_path)) {
                    appendToSourceList(&source_list, full_path);
                }
                // 如果target_type是c，则只加入.c而不加入.cpp
                else if (tmp_c != NULL && strcmp(target_type,"c")==0) {
                    if (strcmp(tmp_c,".c")==0 && !isPathInSourceList(source_list, full_path)) {
                        appendToSourceList(&source_list, full_path);
                    }
                }
                // 如果target_type是c++，则加入.cpp和.c
                else if (tmp_c != NULL && strcmp(target_type,"c++")==0 ) {
                    if ((strcmp(tmp_c,".c")==0 || strcmp(tmp_c,".cpp")==0) && !isPathInSourceList(source_list, full_path)) {
                        appendToSourceList(&source_list, full_path);
                    }
                }
            }
        }
        closedir(dir);
        // free(suffix);
    } else {
        perror("opendir");
    }
}

/**
 * @brief 将单个源文件添加到source_list
 * 
 */
void addSourcefileToList(char* file_path){
    if (!(isPathInSourceList(source_list, file_path))) {
        appendToSourceList(&source_list, file_path);
    }
}

/**
 * @brief 打印source_list
 * 
 */
void printfSourcelist() {
    struct file_node* current = source_list;
    while (current != NULL) {
        printf("%s\n", current->file_path);
        current = current->next;
    }
}

/**
 * @brief 释放source_list
 * 
 */
void freeSourcelist() {
    struct file_node* current = source_list;
    struct file_node* next;

    while (current != NULL) {
        // 释放当前节点中file_path指向的字符串内存
        free(current->file_path);
        
        // 记录下一个节点，以便在释放当前节点后能够继续遍历
        next = current->next;

        // 释放当前节点的内存
        free(current);

        // 移动到下一个节点
        current = next;
    }

    // 清空链表头指针
    source_list = NULL;
}
