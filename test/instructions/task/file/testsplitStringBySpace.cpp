#include "gtest/gtest.h"
#include "file.h"
#include <stdlib.h>

TEST(splitStringBySpace, test0)
{
    // 测试用例
    char* str = (char*)"Hello World";
    char* expeciotn[] = {(char*)"Hello", (char*)"World"};

    // 运行结果
    int* num = (int*)malloc(sizeof(int));
    char** result = splitStringBySpace(str, num);

    // 断言
    EXPECT_EQ(sizeof(expeciotn)/sizeof(*expeciotn), *num);
    for (int i = 0; i < *num; i++) {
        EXPECT_STREQ(expeciotn[i], result[i]);
    }
}

TEST(splitStringBySpace, test1)
{
    // 测试用例
    char* str = (char*)"Hello, World!";
    char* expeciotn[] = {(char*)"Hello,", (char*)"World!"};

    // 运行结果
    int* num = (int*)malloc(sizeof(int));
    char** result = splitStringBySpace(str, num);

    // 断言
    EXPECT_EQ(sizeof(expeciotn)/sizeof(*expeciotn), *num);
    for (int i = 0; i < *num; i++) {
        EXPECT_STREQ(expeciotn[i], result[i]);
    }
}

TEST(splitStringBySpace, test2)
{
    // 测试用例
    char* str = (char*)"I don't like work.";
    char* expeciotn[] = {(char*)"I", (char*)"don't", (char*)"like", (char*)"work."};

    // 运行结果
    int* num = (int*)malloc(sizeof(int));
    char** result = splitStringBySpace(str, num);

    // 断言
    EXPECT_EQ(sizeof(expeciotn)/sizeof(*expeciotn), *num);
    for (int i = 0; i < *num; i++) {
        EXPECT_STREQ(expeciotn[i], result[i]);
    }
}

TEST(splitStringBySpace, test3)
{
    // 测试用例
    char* str = (char*)"  ww ss    ssf  ddf ss -s s-=sa s   ";
    char* expeciotn[] = {(char*)"ww", (char*)"ss", (char*)"ssf", (char*)"ddf", (char*)"ss", (char*)"-s", (char*)"s-=sa", (char*)"s"};

    // 运行结果
    int* num = (int*)malloc(sizeof(int));
    char** result = splitStringBySpace(str, num);

    // 断言
    EXPECT_EQ(sizeof(expeciotn)/sizeof(*expeciotn), *num);
    for (int i = 0; i < *num; i++) {
        EXPECT_STREQ(expeciotn[i], result[i]);
    }
}