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