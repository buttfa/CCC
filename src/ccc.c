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
char* output_file_path;
char* library_path = NULL;
int main(int argc, char* argv[]) {
    // 获取运行路径
    char run_path[128];
    getcwd(run_path, sizeof(run_path));
    printf("%s\n",run_path);
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
        // 获取文件的绝对路径
        char *ccc_path = (char*)malloc(strlen(run_path)+strlen(argv[1])+2);
        strcat(ccc_path,run_path);
        strcat(ccc_path,"/");
        strcat(ccc_path,argv[1]);
        // 判断文件是否存在以及是否为.ccc文件
        if (isFileWithSuffix(ccc_path,".ccc")) {
            printf("%s\n",ccc_path);
            // 解析.ccc文件
            parseCCC(ccc_path);
        } else {
            printf("The target file does not exist or does not have a. ccc suffix\n");
        }
    } else {
        printf("Error: Invalid argument\n");
    }
/****************************************************************************/
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
    printf("Report bugs to <https://github.com/buttfa/ccc/issues>\n");
}