#include <getObjReliance.h>

/**
 * @brief Append reliance to reliance list.
 * 
 * @param reliance 
 */
static void appendToRelianceList(struct reliance* reliance, struct COMPILE_TASK* task) {
    if (task->reliance_list == NULL) {
        task->reliance_list = reliance;
    } else {
        struct reliance * current = task->reliance_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = reliance;
    }
}

/**
 * @brief Create dependencies for the .o files corresponding to the incoming .c/.cpp files
 * 
 * @param source_file_path .c/.cpp file path
 * @param task Task variables that require information to be filled in.
 */
void addRelianceList(char* source_file_path, struct COMPILE_TASK* task) {
    char buf[4096];
    // Get the target obj file path
    char* file_name = getFileName(source_file_path);
    char* obj_file = (char*)malloc(hotfix_strlen(task->obj_path)+1+hotfix_strlen(file_name)+hotfix_strlen((char*)".o")+1);
    sprintf(obj_file, "%s/%s.o", 
                    task->obj_path!=NULL ? task->obj_path : "", 
                    file_name!=NULL ? file_name : "");
    free(file_name);

    // Create obj reliance struct
    struct reliance *reliance = (struct reliance*)malloc(sizeof(struct reliance));
    memset(reliance, 0, sizeof(struct reliance));
    reliance->file_path = obj_file;
    reliance->reliance_num = 0;

    // Excute command to get the obj file's reliance
    char* cmd = (char*)malloc(hotfix_strlen((char*)"gcc -MM")+1+hotfix_strlen(source_file_path)+1+hotfix_strlen(task->header_folders)+1);
    sprintf(cmd, "gcc -MM %s %s", 
                    source_file_path!=NULL ? source_file_path : "", 
                    task->header_folders!=NULL ? task->header_folders : "");
    FILE* pipe = popen(cmd, "r");

    
    // Get reliance file path
    if (fscanf(pipe, "%s", buf) == EOF)
        return;
    while (fscanf(pipe, "%s", buf) != EOF) {
        if (buf[0] != '\\') {
            reliance->reliance_num++;
            reliance->reliant_file = (char**)realloc(reliance->reliant_file, sizeof(char**)*reliance->reliance_num);
            reliance->reliant_file[reliance->reliance_num-1] = (char*)malloc(hotfix_strlen(buf)+1);
            sprintf(reliance->reliant_file[reliance->reliance_num-1], "%s", buf);
        }
    }

    // Close pipe
    pclose(pipe);

    // Add reliance node to reliance list
    appendToRelianceList(reliance, task);
}

/**
 * @brief Printf the reliance list.
 * 
 */
void printfRelianceList(struct COMPILE_TASK* task) {
    struct reliance* temp = task->reliance_list;
    while (temp != NULL) {
        printf("%s(%d):\n", temp->file_path,temp->reliance_num);
        for (int i = 0; i < temp->reliance_num; i++) {
            printf("%s\n", temp->reliant_file[i]);
        }
        temp = temp->next;
    }
}

/**
 * @brief Free reliance list.
 * 
 */
void freeRelianceList(struct COMPILE_TASK* task) {
    struct reliance* current = task->reliance_list;
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
    task->reliance_list = NULL;
}

/**
 * @brief Create an obj_files based on relience list.
 * 
 */
void createObjFiles(struct COMPILE_TASK* task) {
    struct reliance* temp = task->reliance_list;
    // 第一次遍历统计所需长度
    int length = 0;
    while (temp != NULL) {
        length += hotfix_strlen(temp->file_path)+1;
        temp = temp->next;
    }
    // 第二次遍历读取中间文件路径
    task->obj_files = (char*)malloc(length+1);
    memset(task->obj_files, 0, length+1);
    temp = task->reliance_list;
    while (temp != NULL) {
        hotfix_strcat(task->obj_files, temp->file_path);
        hotfix_strcat(task->obj_files, (char*)" ");
        temp = temp->next;
    }
}