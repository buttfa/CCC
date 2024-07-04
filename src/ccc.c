#include <ccc.h>

int main(int argc, char* argv[]) {
/****************************************************************************/
    if (argc == 1) {
        printfVersion();
        printfHelp();
    } else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0)) {
        printfHelp();
    } else if (argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "version") == 0)) {
        printfVersion();
    } else if (argc == 2 && checkFilePath(argv[1]) == 1) {

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