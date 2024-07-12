# 编译器
COMPILER = gcc
# 编译选项
C_FLAGS = -static -w -O3 -finput-charset=UTF-8 -fexec-charset=GBK -g

# 头文件目录
C_INCLUDE = -I inc -I inc/instructions/compile -I inc/instructions/help -I inc/instructions/version -I inc/instructions/clean
 
# 生成文件目录 
BUILD_DIR = build
# 中间文件存放目录
OBJ_PATH = $(BUILD_DIR)/obj
# 编译输出文件的存放位置 
OUTPUT = $(BUILD_DIR)
 

all: CCC VERSION HELP COMPILE CLEAN
	$(COMPILER) $(CCC_OBJ_FILES) $(VERSION_OBJ_FILES) $(HELP_OBJ_FILES) $(COMPILE_OBJ_FILES) $(CLEAN_OBJ_FILES) -o $(OUTPUT)/ccc

###########################################################################
# 编译CCC主体文件
CCC_FILES = $(wildcard src/*.c)
CCC_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(CCC_FILES)))
CCC: $(CCC_OBJ_FILES)
$(CCC_OBJ_FILES):  $(OBJ_PATH)/%.o: src/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译VERSION指令文件
VERSION_FILES = $(wildcard src/instructions/version/*.c)
VERSION_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(VERSION_FILES)))
VERSION: $(VERSION_OBJ_FILES)
$(VERSION_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/version/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译HELP指令文件
HELP_FILES = $(wildcard src/instructions/help/*.c)
HELP_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(HELP_FILES)))
HELP: $(HELP_OBJ_FILES)
$(HELP_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/help/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译COMPILE指令文件
COMPILE_FILES = $(wildcard src/instructions/compile/*.c)
COMPILE_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(COMPILE_FILES)))
COMPILE: $(COMPILE_OBJ_FILES)
$(COMPILE_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/compile/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译CLEAN指令文件
CLEAN_FILES = $(wildcard src/instructions/clean/*.c)
CLEAN_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(CLEAN_FILES)))
CLEAN: $(CLEAN_OBJ_FILES)
$(CLEAN_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/clean/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
install:
	@sudo cp build/ccc /usr/local/bin
	@echo "Successfully installed CCC."
###########################################################################
 
###########################################################################
uninstall:
	@sudo rm -rf /usr/local/bin/ccc
	@echo "Successfully uninstalled CCC."
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