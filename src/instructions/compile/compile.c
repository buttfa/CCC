#include <compile.h>
// .ccc文件信息
char ccc_file_path[128];
char run_path[128];

/**
 * @brief compile的条件函数
 * 
 * @param argc 
 * @param argv
 * @return true 
 * @return false 
 */
bool cdt_compile(int argc, char** argv) {
    if (argc == 2) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief 编译函数
 * 
 * @param argc 
 * @param argv 
 */
void compile_func(int argc, char** argv) {
    // 获取运行路径
    getcwd(run_path, sizeof(run_path));
    // 获取ccc文件路径
    hotfix_strcat(ccc_file_path,argv[1]);
    
    // 获取文件的绝对路径
    char *ccc_path = (char*)malloc(hotfix_strlen(run_path)+hotfix_strlen(argv[1])+2);
    hotfix_strcat(ccc_path,run_path);
    hotfix_strcat(ccc_path,"/");
    hotfix_strcat(ccc_path,argv[1]);
    // 判断文件是否存在以及是否为.ccc文件
    if (access(ccc_file_path, F_OK)==0 && isFileWithSuffix(ccc_file_path,".ccc")) {
/****************************************************************************/            
        // 解析.ccc文件
        // parseCCC(ccc_file_path);
        compileTask task; 
        // task = parseCCCtask(ccc_file_path);
        ini* ccc_ini = iniParseFile(ccc_file_path);
        for (int i = 0; i < ccc_ini->section_num; i++) {
            task = parseCCCIni(ccc_ini->sections[i]);
            handTask(task);
        }
    } else {
        printf("[CCC]The target file does not exist or does not have a. ccc suffix\n");
    }
}