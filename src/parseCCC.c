#include <parseCCC.h>

/**
 * @brief 解析ccc文件中的内容填入ccc文件信息
 * 
 * @param ccc_path 
 */
void parseCCC(char* ccc_path) {
    // 打开ccc文件
    FILE* ccc_file = fopen(ccc_path, "r");
    if (ccc_file == NULL) {
        printf("Error: Cannot open ccc file.\n");
        exit(0);
    }

    int row;
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    while (fscanf(ccc_file, "%s", buf) != EOF) {
        if (strcmp(buf, "target_type") == 0) {
            char symbol[128];
            fscanf(ccc_file, "%s", symbol)!=EOF;
            if (strcmp(symbol, "=")==0) {

                
                target_type = (char*)malloc(strlen(buf) + 1);
                memset(target_type, 0, strlen(buf) + 1);
                strcpy(target_type, buf);
            } else {
                printf("Error: Invalid target_type.\n");
                exit(0);
            }
        } 
    }


    // 关闭ccc文件
    fclose(ccc_file);
}