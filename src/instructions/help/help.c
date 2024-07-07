#include <help.h>

/**
 * @brief help的条件函数
 * 
 * @return true 
 * @return false 
 */
bool cdt_help(int argc, char** argv) {
    if (argc == 2 &&(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "help") == 0)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 打印帮助信息
 * 
 */
void printfHelp() {
    printf("Usage: ccc [OPTION]\n");
    printf("Options:-\n");
    printf("  -h, help      display this help and exit\n");
    printf("  -v, version   display version information and exit\n");
    printf("  ccc_file        compile based on ccc_file\n");
    printf("Report bugs to <https://github.com/buttfa/CCC/issues>\n");
}