#include <compileTask.h>

/**
 * @brief 释放任务
 * 
 * @param task 
 */
void freeTask(struct COMPILE_TASK* task) {
    free(task->target_type);

    free(task->compiler);
    free(task->compile_flags);
    
    free(task->linker);
    free(task->link_flags);

    free(task->source_sig_files);
    free(task->source_folder_path);
    free(task->header_sig_files);
    free(task->header_folder_path);

    free(task->sll_sig_files);
    free(task->sll_folder_path);
    free(task->dll_sig_files);
    free(task->dll_folder_path);

    free(task->obj_path);
    free(task->output_path);

    free(task->library_path);
}