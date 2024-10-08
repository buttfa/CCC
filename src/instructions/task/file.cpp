/**
 * @file file.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 实现了所需的字符串操作的函数
 * @version 0.1
 * @date 2024-08-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <file.h>

/**
 * @brief 接受一个文件路径path和一个后缀字符串suffix作为
 *        参数，判断该路径对应的文件是否存在并且文件名以指定的后缀结束。
 * 
 * @param path 文件路径
 * @param suffix 后缀字符串
 * @return true 文件存在且文件名以指定的后缀结束
 * @return false 文件不存在或不以指定的后缀结束
 */
bool isFileWithSuffix(char *path, char *suffix) {
    // 首先检查路径是否以suffix结尾
    size_t path_len = hotfix_strlen(path);
    size_t suffix_len = hotfix_strlen(suffix);
    if (path_len < suffix_len || strcmp(path + path_len - suffix_len, suffix) != 0) {
        return false; // 不是以指定后缀结尾
    }

    // // 使用stat函数获取文件状态信息
    // struct stat st;
    // if (stat(path, &st) == -1) {
    //     // 文件不存在或无法访问
    //     return false;
    // }

    // // 检查是否为常规文件
    // if (!S_ISREG(st.st_mode)) {
    //     return false; // 不是常规文件
    // }

    return true; // 文件存在且以指定后缀结尾
}

/**
 * @brief 将字符串str拆分成以delimiter为分隔符的数组，返回数组指针。
 * 
 * @param str 需要分割的字符串
 * @param delimiter 分割符
 * @return char** 分割后的字符串数组
 */
char **splitString(char *str, char delimiter) {
    if (str == NULL) return NULL;

    int argc = 0;
    int strLen = hotfix_strlen(str);
    char **result = NULL;

    // 预计算需要多少个子字符串
    for (int i = 0; i <= strLen; ++i) {
        if (str[i] == delimiter || str[i] == '\0') {
            argc++;
        }
    }
    if (argc == 0) return NULL; // 防止空字符串导致的错误

    result = (char **)calloc(argc + 1, sizeof(char *));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    int currentArg = 0;
    int startIndex = 0;
    for (int i = 0; i <= strLen; ++i) {
        if (str[i] == delimiter || str[i] == '\0') {
            int len = i - startIndex;
            result[currentArg] = (char *)calloc(len + 1, sizeof(char));
            if (result[currentArg] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                while (currentArg > 0) free(result[--currentArg]);
                free(result);
                return NULL;
            }
            strncpy(result[currentArg], &str[startIndex], len);
            result[currentArg][len] = '\0';
            startIndex = i + 1; // 移动到下一个子串的起始位置
            currentArg++;
        }
    }

    return result;
}

/**
 * @brief 释放分割字符串的数组。
 * 
 * @param splitResult 需要释放的数组指针
 */
void freeSplitResult(char **splitResult) {
    if (splitResult != NULL) {
        for (int i = 0; splitResult[i] != NULL; ++i) {
            free(splitResult[i]);
        }
        free(splitResult);
    }
}

/**
 * @brief 获取到filePath去除路径和后缀的文件名
 * 
 * @param filePath 需要提取的文件名的文件路径
 * @return char* 提取出的文件名
 */
char* getFileName(char* filePath) {
    if (filePath == NULL) return NULL;
    
    
    // 获得.的位置
    int point = hotfix_strlen(filePath)-1;
    while (point >= 0 && filePath[point] != '.') {
        point--;
    }
    
    // 获得最后一个/的位置
    int index = hotfix_strlen(filePath)-1;
    while (index >= 0 && filePath[index] != '/') {
        index--;
    }
    
    if (point == -1) {
        int size = hotfix_strlen(filePath+index+1)+1;
        char* fileName = (char*)malloc(sizeof(char)*size); 
        for (int i = 0; i < size-1; i++)
            fileName[i] = filePath[index+1+i];
        fileName[size-1] = '\0';
        return fileName;
    } else {
        int size = point-index;
        char* fileName = (char*)malloc(size);
        for (int i = 0; i < size-1; i++)
            fileName[i] = filePath[index+1+i];
        fileName[size-1] = '\0';
        return fileName;
    }

}

/**
 * @brief 提取input_str中的子字符串，以空格为分隔符
 * 
 * @param input_str 需要分割的字符串
 * @param out_num_tokens 分割后产生的字符串个数
 * @return char** 字符串数组
 */
char** splitStringBySpace(char* input_str, int* out_num_tokens) {
    if (input_str != NULL) {
        int count = 0;
        char* p = input_str;
        
        // 跳过开头的空格
        while (isspace(*p)) {
            ++p;
        }
        
        // 计算非空格分隔的单词数量
        while (*p != '\0') {
            if (!isspace(*p)) {
                ++count;
                while (*p != '\0' && !isspace(*p)) {
                    ++p;
                }
            } else {
                ++p; // 跳过空格
            }
        }

        // 分配足够的空间来存储指针数组和每个子字符串
        char** tokens = (char**)malloc((count + 1) * sizeof(char*));
        *out_num_tokens = 0;

        // 回退指针p到第一个单词的开始位置
        p = input_str;
        while (isspace(*p)) {
            ++p;
        }

        for(int i = 0; i < count; ++i) {
            while (isspace(*p)) {
                ++p; // 跳过前导空格
            }
            if (*p == '\0') break; // 如果到达字符串末尾，跳出循环

            // 找到单词的结束位置
            char* token_end = p;
            while (*token_end != '\0' && !isspace(*token_end)) {
                ++token_end;
            }

            // 分配内存并复制单词
            size_t len = token_end - p;
            tokens[(*out_num_tokens)++] = (char*)malloc(len + 1);
            strncpy(tokens[*out_num_tokens - 1], p, len);
            tokens[*out_num_tokens - 1][len] = '\0';

            // 移动到下一个单词的开始位置
            p = token_end;
            while (isspace(*p)) {
                ++p; // 跳过后导空格
            }
        }

        tokens[*out_num_tokens] = NULL; // 以NULL结束指针数组
        return tokens;
    }
    else {
        *out_num_tokens = 0;
        return NULL;
    }
}

/**
 * @brief 使用于本项目的特殊strlen，当str指向NULL时，返回0
 * 
 * @param str 需要获取长度的字符串
 * @return int 字符串长度
 */
int hotfix_strlen(char* str) {
    if (str == NULL){
        return 0;
    } else {
        return strlen(str);
    }
}

/**
 * @brief 使用于本项目的特殊strcat，当dest或str指向NULL时，不进行操作
 * 
 * @param dest 目标字符串
 * @param src 源字符串
 */
void hotfix_strcat(char* dest, char* src) {
    if (dest == NULL || src == NULL) {
        return;
    } else {
        strcat(dest, src);
    }
}