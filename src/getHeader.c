#include <getHeader.h>

/**
 * @brief 头文件夹链表
 * 
 */
struct header_folder* header_folder_list;
/**
 * @brief 头文件夹字符串
 * 
 */
char* header_folders;



/**
 * @brief 初始化哈希集合
 * 
 * @return PathHashSet* 
 */
PathHashSet* initHashSet() {
    PathHashSet* set = (PathHashSet*)malloc(sizeof(PathHashSet));
    set->paths = NULL;
    set->size = 0;
    return set;
}

/**
 * @brief 在哈希集合中查找路径
 * 
 * @param set 
 * @param path 
 * @return true 
 * @return false 
 */
bool isInHashSet(PathHashSet* set, const char* path) {
    for (size_t i = 0; i < set->size; ++i) {
        if (strcmp(set->paths[i], path) == 0) {
            return true;
        }
    }
    return false;
}

/**
 * @brief 向哈希集合中添加路径
 * 
 * @param set 
 * @param path 
 */
void addToHashSet(PathHashSet* set, const char* path) {
    set->paths = (char**)realloc(set->paths, sizeof(char*) * (set->size + 1));
    set->paths[set->size] = strdup(path);
    set->size++;
}

/**
 * @brief 释放哈希集合资源
 * 
 * @param set 
 */
void freeHashSet(PathHashSet* set) {
    for (size_t i = 0; i < set->size; ++i) {
        free(set->paths[i]);
    }
    free(set->paths);
    free(set);
}

/**
 * @brief 检查目录下是否有.h文件
 * 
 * @param dir_path 
 * @return true 
 * @return false 
 */
bool hasHFile(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(dir_path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strstr(entry->d_name, ".h") != NULL) {
                closedir(dir);
                return true;
            }
        }
        closedir(dir);
    }
    return false;
}

/**
 * @brief 向链表中添加目录路径
 * 
 * @param folder_path 
 */
void appendToHeaderFolderList(const char* folder_path) {
    struct header_folder* new_node = (struct header_folder*)malloc(sizeof(struct header_folder));
    new_node->folder_path = strdup(folder_path);
    new_node->next = header_folder_list;
    header_folder_list = new_node;
}

/**
 * @brief 将header_folder_path中包含.h文件的文件夹及子文件夹
 *        添加到header_folder_list中。（每次添加前会检查，避免重复添加）
 * 
 * @param header_folder_path 
 */
void addHeaderFolderList(const char* header_folder_path) {
    PathHashSet* seen_dirs = initHashSet();

    // 首先检查传入的路径本身是否包含.h文件
    if (hasHFile(header_folder_path)) {
        if (!isInHashSet(seen_dirs, header_folder_path)) {
            addToHashSet(seen_dirs, header_folder_path);
            appendToHeaderFolderList(header_folder_path);
        }
    }

    DIR *dir;
    struct dirent *entry;
    
    if ((dir = opendir(header_folder_path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char full_path[hotfix_strlen((char*)header_folder_path) + hotfix_strlen(entry->d_name) + 2];
            snprintf(full_path, sizeof(full_path), "%s/%s", header_folder_path, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                addHeaderFolderList(full_path); // 递归调用
            } else if (strstr(entry->d_name, ".h") != NULL) {
                // 这里实际上不需要处理，因为hasHFile在开始时已经检查过了根目录
                // 保留此注释作为理解流程的参考
            }
        }
        closedir(dir);
    }
    
    freeHashSet(seen_dirs);
}

/**
 * @brief 打印头文件夹链表
 * 
 */
void printfHeaderFolderList(){
    struct header_folder* current = header_folder_list;
    while (current != NULL) {
        printf("%s\n", current->folder_path);
        current = current->next;
    }
}

/**
 * @brief 释放header_folder_list
 * 
 */
void freeHeaderFolderList() {
    struct header_folder* current = header_folder_list;
    struct header_folder* next;

    while (current != NULL) {
        // 释放当前节点的folder_path指向的字符串内存
        free(current->folder_path);
        
        // 记录下一个节点
        next = current->next;
        
        // 释放当前节点的内存
        free(current);
        
        // 移动到下一个节点
        current = next;
    }

    // 最后，将链表头指针设为NULL
    header_folder_list = NULL;
}

/**
 * @brief 根据header_folder_list创建header_folders
 * 
 */
void createHeaderFolders() {
    struct header_folder* current = header_folder_list;
    size_t total_size = 0; // 计算总长度以预先分配足够的内存

    // 遍历链表，计算总长度
    while (current != NULL) {
        total_size += 3 + hotfix_strlen(current->folder_path) + 1; // +1是为了添加分隔符（如逗号或换行符）
        current = current->next;
    }

    // 分配足够的内存，+1是为了存放末尾的空字符
    header_folders = (char*)malloc(total_size + 1);

    // 初始化字符串为空
    header_folders[0] = '\0';

    // 再次遍历链表，拼接路径到字符串
    current = header_folder_list;
    while (current != NULL) {
        hotfix_strcat(header_folders, "-I ");
        hotfix_strcat(header_folders, current->folder_path);
        
        // 可以根据需要添加分隔符
        if (current->next != NULL) {
            hotfix_strcat(header_folders, " ");
        }
        
        current = current->next;
    }
}