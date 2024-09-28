/**
 * @file getDll.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 实现了了获取dll_sig_files、dll_folder_path和library_path中dll文件的相关操作
 * @version 0.1
 * @date 2024-08-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <getDll.h>


/**
 * @brief 查询路径是否已经在dll_list中
 * 
 * @param node dll_list链表的头结点指针
 * @param path 需要查询
 * @return int 返回1 表示在链表中，0表示不在链表中
 */
static int isPathInDllList(const struct file_node* node, const char* path) {
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
 * @param head dll_list链表的头结点的二级指针
 * @param path 需要添加的文件路径
 */
static void appendToDllList(struct file_node** head, const char* path) {
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
 * @brief 将dll_folder_path文件夹及其子文件夹中的.a文件添加到dll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param dll_folder_path 需要遍历的文件夹路径
 * @param task 遍历到的.a文件会添加到task->dll_list中
 */
void addDlllist(const char* dll_folder_path, struct COMPILE_TASK* task) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(dll_folder_path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char full_path[FILENAME_MAX];
            snprintf(full_path, FILENAME_MAX, "%s/%s", dll_folder_path, ent->d_name);
            if (ent->d_type == DT_DIR) {
                // 递归遍历子目录
                addDlllist(full_path, task);
            } else if (strstr(ent->d_name, ".so") != NULL) {
                // 检查并添加.so文件到链表
                if (!isPathInDllList(task->dll_list, full_path)) {
                    appendToDllList(&task->dll_list, full_path);
                }
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
    }
}

/**
 * @brief 将单个文件添加到dll_list中
 * 
 * @param file_path 需要添加的文件路径
 * @param task 文件会添加到task->dll_list中
 */
void addDllfileToList(char* file_path, struct COMPILE_TASK* task) {
    if (!isPathInDllList(task->dll_list, file_path)) {
        appendToDllList(&task->dll_list, file_path);
    }
}

/**
 * @brief 打印dll_list
 * 
 * @param task 包含dll_list的task
 */
void printfDlllist(struct COMPILE_TASK* task) {
    struct file_node* current = task->dll_list;
    while (current != NULL) {
        printf("%s\n", current->file_path);
        current = current->next;
    }
}

/**
 * @brief 释放dll_list
 * 
 * @param task 包含需要释放的dll_list的task
 */
void freeDlllist(struct COMPILE_TASK* task) {
    struct file_node* current = task->dll_list;
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
    task->dll_list = NULL;
}

/**
 * @brief 根据dll_list创建dll_files
 * 
 * @param task 包含dll_list的task
 */
void createDllFiles(struct COMPILE_TASK* task) {
    int total_length = 0; // 用于计算总的字符串长度
    struct file_node* current = task->dll_list;

    // 遍历链表，计算总长度
    while (current != NULL) {
        total_length += hotfix_strlen(current->file_path) + 1; // 加1是为了每个路径后的null字符
        current = current->next;
    }

    // 分配足够的内存空间给dll_files
    task->dll_files = (char*)malloc(total_length * sizeof(char));

    // 确保内存分配成功
    if (task->dll_files == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char* position = task->dll_files; // 用于追踪dll_files中的当前位置
    current = task->dll_list;

    // 再次遍历链表，复制文件路径到dll_files中
    while (current != NULL) {
        strcpy(position, current->file_path);
        hotfix_strcat(position, (char*)" ");
        position += hotfix_strlen(current->file_path) + 1; // 移动到下一个路径开始的位置
        current = current->next;
    }

    // 确保字符串以null字符结尾
    *position = '\0';
}