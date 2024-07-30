#include <checkCCC.h>

/**
 * @brief 检查是否缺少必要ccc文件信息
 * 
 */
void checkCCC(struct COMPILE_TASK task) {
    int flag = 1;
    // 检查是否设置target_type
    if (task.target_type == NULL) {
        printf("Error: target_type is not set.\n");
        flag = 0;
    }

    // 检查是否设置compiler
    if (task.compiler == NULL) {
        printf("Error: compiler is not set.\n");
        flag = 0;
    }

    // 检查是否设置linker
    if (task.linker == NULL) {
        printf("Error: linker is not set.\n");
        flag = 0;
    }

    // 检查是否设置source_folder_path或source_sig_files
    if (task.source_folder_path == NULL && task.source_sig_files == NULL) {
        printf("Error: source_folder_path is not set.\n");
        flag = 0;
    }

    // 检查是否设置obj_path
    if (task.obj_path == NULL) {
        printf("Error: obj_path is not set.\n");
        flag = 0;
    }

    // 检查是否设置output_path
    if (task.output_path == NULL) {
        printf("Error: output_path is not set.\n");
        flag = 0;
    }


    // 当缺少必要ccc文件信息时退出
    if (flag == 0) {
        exit(0);
    }
}