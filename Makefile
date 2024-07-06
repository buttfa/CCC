# 编译器
COMPILER = gcc
# 编译选项
C_FLAGS = -static -Wall -O3 -finput-charset=UTF-8 -fexec-charset=GBK -g

# 源文件目录
C_SOURCES = src
# 头文件目录
C_INCLUDE = inc

# 生成文件目录
BUILD_DIR = build
# 中间文件存放目录
OBJ_PATH = $(BUILD_DIR)/obj
# 编译输出文件的存放位置
OUTPUT = $(BUILD_DIR)
 
###########################################################################
# CCC源文件的路径
CCC_SRC_PATH = $(C_SOURCES)
# 读取CCC源文件路径下的所有.c文件
CCC_SRC_FILES = $(wildcard $(CCC_SRC_PATH)/*.c)
# CCC的所有.o中间文件（包含存放的目标路径）
CCC_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(CCC_SRC_FILES)))
# FTS头文件文件夹
CCC_INC_FOLDER = $(C_INCLUDE)

# 链接生成CCC程序
ccc: $(CCC_OBJ_FILES)
	$(COMPILER) $(CCC_OBJ_FILES) -o $(OUTPUT)/ccc
	
# 迭代编译所需源文件
$(CCC_OBJ_FILES): $(OBJ_PATH)/%.o: $(CCC_SRC_PATH)/%.c
	$(COMPILER) -c $^ -o $@ -I $(CCC_INC_FOLDER) $(C_FLAGS)
###########################################################################

###########################################################################
test:
	make ccc
	./build/ccc ./example/easy/easy.ccc

#	./build/ccc ./example/easy/src/a.ccc
#	./build/ccc version
#	./build/ccc 
###########################################################################


###########################################################################
clean:
	rm -rf build/ccc
	rm -rf build/obj/*.o
###########################################################################