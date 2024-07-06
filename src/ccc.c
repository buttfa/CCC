#include <ccc.h>
// .ccc文件信息
char* target_type = NULL;
char* compiler = NULL;
char* compiler_flags = NULL;
char* linker = NULL;
char* linker_flags = NULL;
char* source_folder_path = NULL;
char* header_folder_path = NULL;
char* sll_folder_path = NULL;
char* dll_folder_path = NULL;
char* obj_path = NULL;
char* output_path = NULL;
char* library_path = NULL;

char ccc_file_path[128];
char run_path[128];
char ccc_file_name[128];
int main(int argc, char* argv[]) {
    // 获取运行路径
    getcwd(run_path, sizeof(run_path));
/****************************************************************************/
    // 解析参数，打印对应信息，或依据.ccc文件组织编译
    if (argc == 1) {
        printfVersion();
        printfHelp();
    } else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0)) {
        printfHelp();
    } else if (argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "version") == 0)) {
        printfVersion();
    } else if (argc == 2) { 
        // 获取ccc文件路径
        hotfix_strcat(ccc_file_path,argv[1]);
        
        // 获取文件的绝对路径
        char *ccc_path = (char*)malloc(hotfix_strlen(run_path)+hotfix_strlen(argv[1])+2);
        hotfix_strcat(ccc_path,run_path);
        hotfix_strcat(ccc_path,"/");
        hotfix_strcat(ccc_path,argv[1]);
        // 判断文件是否存在以及是否为.ccc文件
        if (isFileWithSuffix(ccc_path,".ccc")) {
            // 获取文件名（不包含路径和后缀名）
            hotfix_strcat(ccc_file_name,getFileName(ccc_path));
/****************************************************************************/            
            // 解析.ccc文件
            parseCCC(ccc_path);
/****************************************************************************/
            // 判断是否缺少必要ccc文件信息
            // 必要信息包括，target_type、compiler、linker、
            // source_folder_path、obj_path、output_path。
            checkCCC();
/****************************************************************************/
            // 获取头文件目录（非必要）
            // 将header_folder_path和library_path合并，以便操作
            char* header_folder_path_temp = (char*)malloc(hotfix_strlen(header_folder_path)+hotfix_strlen(library_path)+2);
            memset(header_folder_path_temp,0,hotfix_strlen(header_folder_path)+hotfix_strlen(library_path)+2);
            hotfix_strcat(header_folder_path_temp,header_folder_path);
            hotfix_strcat(header_folder_path_temp," ");
            hotfix_strcat(header_folder_path_temp,library_path);

            // 将header_folder_path_temp以空格分割
            char** header_folder_path_split = splitString(header_folder_path_temp, ' ');
            // 将header_folder_path_split[i]中包含.h文件的文件夹及子文件夹
            // 添加到header_folder_list中。（每次添加前会检查，避免重复添加）
            for (int i = 0; header_folder_path_split[i] != NULL; i++) {
                if (hotfix_strlen(header_folder_path_split[i]) != 0) {
                    addHeaderFolderList(header_folder_path_split[i]);
                }
            }
            // printfHeaderFolderList();
            // 根据header_folder_list创建header_folders
            createHeaderFolders();

            // 释放该步骤所需的临时内存
            free(header_folder_path_temp);
            freeSplitResult(header_folder_path_split);
            freeHeaderFolderList(header_folder_list);
/****************************************************************************/
            // 载入静态链接库文件（非必要）
            
            // 判断是否需要载入静态链接库文件
            if (sll_folder_path != NULL || library_path != NULL) {
                // 将sll_folder_path和library_path合并，以便操作
                char* sll_folder_path_temp = (char*)malloc(hotfix_strlen(sll_folder_path)+hotfix_strlen(library_path)+2);
                memset(sll_folder_path_temp,0,hotfix_strlen(sll_folder_path)+hotfix_strlen(library_path)+2);
                hotfix_strcat(sll_folder_path_temp,sll_folder_path);
                hotfix_strcat(sll_folder_path_temp," ");
                hotfix_strcat(sll_folder_path_temp,library_path);

                // 将sll_folder_path以空格分割
                char** sll_folder_path_split = splitString(sll_folder_path_temp, ' ');
                // 将sll_folder_path_split[i]文件夹及子文件夹中的.a文件
                // 添加到sll_list中。（每次添加前会检查，避免重复添加）
                for (int i = 0; sll_folder_path_split[i] != NULL; i++) {
                    if (hotfix_strlen(sll_folder_path_split[i]) != 0) {
                        addSlllist(sll_folder_path_split[i]);
                    }
                }
                // printfSlllist();
                // 根据sll_list创建sll_files
                createSllFiles();

                free(sll_folder_path_temp);
                freeSplitResult(sll_folder_path_split);
            } 
/****************************************************************************/
            // 载入动态链接库文件（非必要）
            
            // 判断是否需要载入动态链接库文件
            if (dll_folder_path != NULL || library_path != NULL) {
                // 将dll_folder_path和library_path合并，以便操作
                char* dll_folder_path_temp = (char*)malloc(hotfix_strlen(dll_folder_path)+hotfix_strlen(library_path)+2);
                memset(dll_folder_path_temp,0,hotfix_strlen(dll_folder_path)+hotfix_strlen(library_path)+2);
                hotfix_strcat(dll_folder_path_temp,dll_folder_path);
                hotfix_strcat(dll_folder_path_temp," ");
                hotfix_strcat(dll_folder_path_temp,library_path);

                // 将dll_folder_path以空格分割
                char** dll_folder_path_split = splitString(dll_folder_path_temp, ' ');
                // 将dll_folder_path_split[i]文件夹及子文件夹中的.so文件
                // 添加到dll_list中。（每次添加前会检查，避免重复添加）
                for (int i = 0; dll_folder_path_split[i] != NULL; i++) {
                    if (hotfix_strlen(dll_folder_path_split[i]) != 0) {
                        addDlllist(dll_folder_path_split[i]);
                    }
                }
                // printfDlllist();
                // 根据dll_list创建dll_files
                createDllFiles();

                free(dll_folder_path_temp);
                freeSplitResult(dll_folder_path_split);
            } 
/****************************************************************************/

            // 获取源文件组
            char* source_folder_path_temp;
            if (library_path != NULL) {
                // 将source_folder_path和library_path合并，以便操作
                source_folder_path_temp = (char*)malloc(hotfix_strlen(source_folder_path)+hotfix_strlen(library_path)+2);
                memset(source_folder_path_temp,0,hotfix_strlen(source_folder_path)+hotfix_strlen(library_path)+2);
                hotfix_strcat(source_folder_path_temp,source_folder_path);
                hotfix_strcat(source_folder_path_temp," ");
                hotfix_strcat(source_folder_path_temp,library_path);
            } else {
                source_folder_path_temp = (char*)malloc(hotfix_strlen(source_folder_path)+1);
                memset(source_folder_path_temp,0,hotfix_strlen(source_folder_path)+1);
                hotfix_strcat(source_folder_path_temp,source_folder_path);
            }


            // 将source_folder_path_tmp以空格分割
            char** source_folder_path_split = splitString(source_folder_path_temp, ' ');
            // 将source_folder_path_split[i]文件夹及子文件夹中的.c/.cpp文件
            // 添加到sources_list中。（每次添加前会检查，避免重复添加）
            for (int i = 0; source_folder_path_split[i] != NULL; i++) {
                if (hotfix_strlen(source_folder_path_split[i]) != 0) {
                    addSourcelist(source_folder_path_split[i]);
                }
            }

            // printfSourcelist();

            free(source_folder_path_temp);
            freeSplitResult(source_folder_path_split);
/****************************************************************************/
            // 计算中间文件依赖关系
            struct file_node* source_file = source_list;
            while (source_file != NULL) {
                addRelianceList(source_file->file_path);
                source_file = source_file->next;
            }

            // printfRelianceList();
/****************************************************************************/

            // 计算目标依赖关系
            createTargetReliance();
            // printfTargetReliance();

/****************************************************************************/

            // 获取中间文件组
            createObjFiles();
/****************************************************************************/
            // 检查依赖
            handleReliance();
/****************************************************************************/
        } else {
            printf("The target file does not exist or does not have a. ccc suffix\n");
        }
    } else {
        printf("Error: Invalid argument\n");
    }
/****************************************************************************/
    
    // 释放内存
    free(target_type);
    free(compiler);
    free(compiler_flags);
    free(linker);
    free(linker_flags);
    free(source_folder_path);
    free(header_folder_path);
    free(sll_folder_path);
    free(dll_folder_path);
    // free(obj_path);
    free(output_path);
    free(library_path);

    free(header_folders);
    free(sll_files);
    free(dll_files);

    freeSlllist();
    freeDlllist();
    freeSourcelist();

    freeRelianceList();
    free(obj_path);
    freeTargetReliance();
    return 0;
}


/**
 * @brief 打印版本信息
 * 
 */
void printfVersion() {
    printf("CCC version:");
    printf(CCC_VERSION);
    printf("\n");
}
/**
 * @brief 打印帮助信息
 * 
 */
void printfHelp() {
    printf("Usage: ccc [OPTION]\n");
    printf("Options:-\n");
    printf("  -h, --help      display this help and exit\n");
    printf("  -v, --version   display version information and exit\n");
    printf("  ccc_file        compile based on ccc_file\n");
    printf("Report bugs to <https://github.com/buttfa/CCC/issues>\n");
}