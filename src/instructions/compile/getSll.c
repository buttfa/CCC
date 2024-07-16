#include <getSll.h>


/**
 * @brief 检查链表中是否存在特定路径
 * 
 * @param node 
 * @param path 
 * @return int 
 */
int isPathInSllList(const struct file_node* node, const char* path) {
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
void appendToSllList(struct file_node** head, const char* path) {
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
 * @brief 将sll_folder_path文件夹及其子文件夹中的.a文件添加到sll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param sll_folder_path 
 */
void addSlllist(const char* sll_folder_path, struct COMPILE_TASK* task) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(sll_folder_path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char full_path[FILENAME_MAX];
            snprintf(full_path, FILENAME_MAX, "%s/%s", sll_folder_path, ent->d_name);
            if (ent->d_type == DT_DIR) {
                // 递归遍历子目录
                addSlllist(full_path, task);
            } else if (strstr(ent->d_name, ".a") != NULL) {
                // 检查并添加.a文件到链表
                if (!isPathInSllList(task->sll_list, full_path)) {
                    appendToSllList(&task->sll_list, full_path);
                }
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
    }
}

/**
 * @brief 将单个文件添加到sll_list中
 * 
 * @param file_path 
 */
void addSllfileToList(char* file_path, struct COMPILE_TASK* task) {
    if (!isPathInSllList(task->sll_list, file_path)) {
        appendToSllList(&task->sll_list, file_path);
    }
}

/**
 * @brief 打印sll_list
 * 
 */
void printfSlllist(struct COMPILE_TASK* task) {
    struct file_node* current = task->sll_list;
    while (current != NULL) {
        printf("%s\n", current->file_path);
        current = current->next;
    }
}

/**
 * @brief 释放sll_list
 * 
 */
void freeSlllist(struct COMPILE_TASK* task) {
    struct file_node* current = task->sll_list;
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
    task->sll_list = NULL;
}

/**
 * @brief 根据sll_list创建sll_files
 * 
 */
void createSllFiles(struct COMPILE_TASK* task) {
    int total_length = 0; // 用于计算总的字符串长度
    struct file_node* current = task->sll_list;

    // 遍历链表，计算总长度
    while (current != NULL) {
        total_length += hotfix_strlen(current->file_path) + 1; // 加1是为了每个路径后的null字符
        current = current->next;
    }

    // 分配足够的内存空间给sll_files
    task->sll_files = (char*)malloc(total_length * sizeof(char));

    // 确保内存分配成功
    if (task->sll_files == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char* position = task->sll_files; // 用于追踪sll_files中的当前位置
    current = task->sll_list;

    // 再次遍历链表，复制文件路径到sll_files中
    while (current != NULL) {
        strcpy(position, current->file_path);
        hotfix_strcat(position, " ");
        position += hotfix_strlen(current->file_path) + 1; // 移动到下一个路径开始的位置
        current = current->next;
    }

    // 确保字符串以null字符结尾
    *position = '\0';
}