#include <version.h>

/**
 * @brief version的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_version(int argc, char** argv) {
    if (argc == 2 &&(strcmp(argv[1], "version") == 0 || strcmp(argv[1], "-v") == 0)) {
        return true;
    } else {
        return false;
    }
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