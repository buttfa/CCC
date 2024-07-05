#include <getDll.h>

/**
 * @brief dll文件链表
 * 
 */
struct file_node* dll_list;

/**
 * @brief dll文件字符串
 * 
 */
char* dll_files;


/**
 * @brief 检查链表中是否存在特定路径
 * 
 * @param node 
 * @param path 
 * @return int 
 */
int isPathInDllList(const struct file_node* node, const char* path) {
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
void appendToDllList(struct file_node** head, const char* path) {
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
 * @brief 将dll_folder_path文件夹及其子文件夹中的.so文件添加到dll_list中
 *        （每次添加前需要检查，避免重复添加）
 * 
 * @param dll_folder_path 
 */
void addDlllist(const char* dll_folder_path) {
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
                addDlllist(full_path);
            } else if (strstr(ent->d_name, ".so") != NULL) {
                // 检查并添加.so文件到链表
                if (!isPathInDllList(dll_list, full_path)) {
                    appendToDllList(&dll_list, full_path);
                }
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
    }
}

/**
 * @brief 打印dll_list
 * 
 */
void printfDlllist() {
    struct file_node* current = dll_list;
    while (current != NULL) {
        printf("%s\n", current->file_path);
        current = current->next;
    }
}

/**
 * @brief 释放dll_list
 * 
 */
void freeDlllist() {
    struct file_node* current = dll_list;
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
    dll_list = NULL;
}

/**
 * @brief 根据dll_list创建dll_files
 * 
 */
void createDllFiles() {
    int total_length = 0; // 用于计算总的字符串长度
    struct file_node* current = dll_list;

    // 遍历链表，计算总长度
    while (current != NULL) {
        total_length += strlen(current->file_path) + 1; // 加1是为了每个路径后的null字符
        current = current->next;
    }

    // 分配足够的内存空间给dll_files
    dll_files = (char*)malloc(total_length * sizeof(char));

    // 确保内存分配成功
    if (dll_files == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char* position = dll_files; // 用于追踪dll_files中的当前位置
    current = dll_list;

    // 再次遍历链表，复制文件路径到dll_files中
    while (current != NULL) {
        strcpy(position, current->file_path);
        strcat(position, " ");
        position += strlen(current->file_path) + 1; // 移动到下一个路径开始的位置
        current = current->next;
    }

    // 确保字符串以null字符结尾
    *position = '\0';
}