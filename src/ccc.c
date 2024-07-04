#include <ccc.h>

int main(int argc, char* argv[]) {
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
        if (isFileWithSuffix(argv[1],".ccc")) {
            printf("%s\n",argv[1]);
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