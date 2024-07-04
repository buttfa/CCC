#include <file.h>
bool isFileWithSuffix(const char *path, const char *suffix) {
    // 首先检查路径是否以suffix结尾
    size_t path_len = strlen(path);
    size_t suffix_len = strlen(suffix);
    if (path_len < suffix_len || strcmp(path + path_len - suffix_len, suffix) != 0) {
        return false; // 不是以指定后缀结尾
    }

    // 使用stat函数获取文件状态信息
    struct stat st;
    if (stat(path, &st) == -1) {
        // 文件不存在或无法访问
        return false;
    }

    // 检查是否为常规文件
    if (!S_ISREG(st.st_mode)) {
        return false; // 不是常规文件
    }

    return true; // 文件存在且以指定后缀结尾
}

/**
 * @brief 将字符串str拆分成以delimiter为分隔符的数组，返回数组指针。
 * 
 * @param str 
 * @param delimiter 
 * @return char** 
 */
char **splitString(const char *str, char delimiter) {
    if (str == NULL) return NULL;

    int argc = 0;
    int strLen = strlen(str);
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
 * @param splitResult 
 */
void freeSplitResult(char **splitResult) {
    if (splitResult != NULL) {
        for (int i = 0; splitResult[i] != NULL; ++i) {
            free(splitResult[i]);
        }
        free(splitResult);
    }
}

