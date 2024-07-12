#include <clean.h>
/**
 * @brief clean指令的条件函数
 * 
 * @param argc 
 * @param argv 
 * @return true 
 * @return false 
 */
bool cdt_clean(int argc, char* argv[]) {
    if (argc == 3 && strcmp(argv[2], "clean") == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 清除编译产生的文件，包含中间文件和目标文件
 * 
 * @param arg 
 * @param argv 
 */
void clean_func(int arg, char* argv[]) {
    // 判断ccc文件是否存在，且以.ccc为后缀
    if (access(argv[1], F_OK)==0 && isFileWithSuffix(argv[1],".ccc")) {
        // 获取文件名（不包含路径和后缀名）
        hotfix_strcat(ccc_file_name,getFileName(argv[1]));
/****************************************************************************/            
        // 解析.ccc文件
        parseCCC(argv[1]);
/****************************************************************************/
        // 判断是否缺少必要ccc文件信息
        // 必要信息包括，target_type、compiler、linker、
        // source_folder_path(或source_sig_files)、obj_path、output_path。
        checkCCC();
/****************************************************************************/
        // 根据obj_path和output_path删除指定文件
        char* cmd = (char*)malloc(hotfix_strlen("rm -rf ")+hotfix_strlen(obj_path)+hotfix_strlen("/*.o")+1+hotfix_strlen(output_path)+1+hotfix_strlen(ccc_file_name)+1);
        memset(cmd,0,hotfix_strlen("rm -rf ")+hotfix_strlen(obj_path)+hotfix_strlen("/*.o")+1+hotfix_strlen(output_path)+1+hotfix_strlen(ccc_file_name)+1);
        hotfix_strcat(cmd,"rm -rf ");
        hotfix_strcat(cmd,obj_path);
        hotfix_strcat(cmd,"/*.o");
        hotfix_strcat(cmd," ");
        hotfix_strcat(cmd,output_path);
        hotfix_strcat(cmd,"/");
        hotfix_strcat(cmd,ccc_file_name);

        printf("%s\n",cmd);
        system(cmd);

        
    }  else {
        printf("[CCC]The target file does not exist or does not have a. ccc suffix\n");
    }
}

