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

    // 依次读取ccc文件中的每一行进行分析
    int row = 0;
    char buf[1024];
    while (fgets(buf, 1024, ccc_file) != NULL) {
        row++;

        // 如果是单独的一行空内容或注释，则跳过处理
        if (buf[0] == '\n' || buf[0] == '#') {
            continue;
        }

        // 将buf中换行符替换为\0
        int index  = 0; 
        while (buf[index] != '\n' && buf[index] != '\0') {
            index++;
        } buf[index] = '\0';

        // 将buf转化为arg参数
        // char **argv = splitString(buf, ' ');
        // int argc = 0;
        // while (argv[argc] != NULL) {
        //     argc++;
        // }
        int* argc = (int*)malloc(sizeof(int));
        char** argv = split_string_by_space(buf,argc);

        // 获取target_type的数据
        if (*argc == 3 && strcmp(argv[0], "target_type") == 0 && strcmp(argv[1], "=")==0 && (strcmp(argv[2], "c") == 0 || strcmp(argv[2], "c++") == 0)) {
            target_type = (char*)malloc(hotfix_strlen(argv[2]) + 1);
            memset(target_type, 0, hotfix_strlen(argv[2]) + 1);
            hotfix_strcat(target_type, argv[2]);
        }

        // 获取compiler的数据
        else if (*argc == 3 && strcmp(argv[0], "compiler") == 0 && strcmp(argv[1], "=")==0) {
            compiler = (char*)malloc(hotfix_strlen(argv[2]) + 1);
            memset(compiler, 0, hotfix_strlen(argv[2]) + 1);
            hotfix_strcat(compiler, argv[2]);
        }

        // 获取compiler_flags的数据
        else if (*argc >= 3 && strcmp(argv[0], "compile_flags") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            compiler_flags = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(compiler_flags, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(compiler_flags, argv[i]);
                hotfix_strcat(compiler_flags, " ");
            }
        }

        // 获取linker的数据
        else if (*argc == 3 && strcmp(argv[0], "linker") == 0 && strcmp(argv[1], "=")==0) {
            linker = (char*)malloc(hotfix_strlen(argv[2]) + 1);
            memset(linker, 0, hotfix_strlen(argv[2]) + 1);
            hotfix_strcat(linker, argv[2]);
        }

        // 获取linker_flags的数据
        else if (*argc >= 3 && strcmp(argv[0], "link_flags") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            linker_flags = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(linker_flags, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(linker_flags, argv[i]);
                hotfix_strcat(linker_flags, " ");
            }            
        }

        // 获取source_folder_path的数据
        else if (*argc >= 3 && strcmp(argv[0], "source_folder_path") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            source_folder_path = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(source_folder_path, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(source_folder_path, argv[i]);
                hotfix_strcat(source_folder_path, " ");
            }   
        }


        // 获取header_folder_path的数据
        else if (*argc >= 3 && strcmp(argv[0], "header_folder_path") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            header_folder_path = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(header_folder_path, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(header_folder_path, argv[i]);
                hotfix_strcat(header_folder_path, " ");
            }   
        }

        // 获取sll_folder_path的数据
        else if (*argc >= 3 && strcmp(argv[0], "sll_folder_path") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            sll_folder_path = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(sll_folder_path, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(sll_folder_path, argv[i]);
                hotfix_strcat(sll_folder_path, " ");
            }   
        }

        // 获取dll_folder_path的数据
        else if (*argc >= 3 && strcmp(argv[0], "dll_folder_path") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            dll_folder_path = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(dll_folder_path, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(dll_folder_path, argv[i]);
                hotfix_strcat(dll_folder_path, " ");
            }   
       }

        // 获取obj_path的数据
        else if (*argc == 3 && strcmp(argv[0], "obj_path") == 0 && strcmp(argv[1], "=")==0) {
            obj_path = (char*)malloc(hotfix_strlen(argv[2]) + 1);
            memset(obj_path, 0, hotfix_strlen(argv[2]) + 1);
            hotfix_strcat(obj_path, argv[2]);
        }

        // 获取output_path的数据
        else if (*argc == 3 && strcmp(argv[0], "output_path") == 0 && strcmp(argv[1], "=")==0) {
            output_path = (char*)malloc(hotfix_strlen(argv[2]) + 1);
            memset(output_path, 0, hotfix_strlen(argv[2]) + 1);
            hotfix_strcat(output_path, argv[2]);
        }


        // 获取library_path的数据
        else if (*argc >= 3 && strcmp(argv[0], "library_path") == 0 && strcmp(argv[1], "=")==0) {
            // 判断拼接字符串的长度
            int malloc_size = 0;
            for (int i = 2; i < *argc; i++) {
                malloc_size += hotfix_strlen(argv[i]) + 1;
            }

            // 分配内存
            library_path = (char*)malloc(malloc_size + 1);
            // 拼接字符串
            memset(library_path, 0, malloc_size + 1);
            for (int i = 2; i < *argc; i++) {
                hotfix_strcat(library_path, argv[i]);
                hotfix_strcat(library_path, " ");
            }  
        }

        // .ccc文件错误行报错
        else {
            printf("[%s]Error: Unknown argument: %d row.\n", ccc_file_path, row);
            // exit(0);
        }


        // 释放分配的内存
        // freeSplitResult(argv);
        for (int i = 0; i < *argc; i++) {
            free(argv[i]);
        }
        free(argv);
        free(argc);
    }
    // 关闭ccc文件
    fclose(ccc_file);
}

