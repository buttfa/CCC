# 编译器
COMPILER = gcc
# 编译选项
C_FLAGS = 

# 头文件目录
C_INCLUDE = -I inc \
-I inc/instructions/task \
-I inc/instructions/help \
-I inc/instructions/version \
-I inc/instructions/template \
-I third_party/EIniP/einip

# 生成文件目录 
BUILD_DIR = build
# 中间文件存放目录
OBJ_PATH = $(BUILD_DIR)/obj
# 编译输出文件的存放位置 
OUTPUT = $(BUILD_DIR)
 

all: CCC VERSION HELP TASK TEMPLATE EINIP
	$(COMPILER) $(CCC_OBJ_FILES) $(VERSION_OBJ_FILES) $(HELP_OBJ_FILES) $(TASK_OBJ_FILES) $(TEMPLATE_OBJ_FILES) $(EINIP_OBJ_FILES) -o $(OUTPUT)/ccc

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
# 编译TASK指令文件
TASK_FILES = $(wildcard src/instructions/task/*.c)
TASK_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(TASK_FILES)))
TASK: $(TASK_OBJ_FILES)
$(TASK_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/task/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译TEMPLATE指令文件
TEMPLATE_FILES = $(wildcard src/instructions/template/*.c)
TEMPLATE_OBJ_FILES = $(patsubst %.c, $(OBJ_PATH)/%.o, $(notdir $(TEMPLATE_FILES)))
TEMPLATE: $(TEMPLATE_OBJ_FILES)
$(TEMPLATE_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/template/%.c
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译EINIP库
EINIP_OBJ_FILES = $(OBJ_PATH)/ini.o
EINIP: $(OBJ_PATH)/ini.o
$(OBJ_PATH)/ini.o: third_party/EIniP/einip/ini.c
	$(COMPILER) -c third_party/EIniP/einip/ini.c -I third_party/EIniP/einip -o $(OBJ_PATH)/ini.o
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
	make -C test
###########################################################################
 

###########################################################################
clean:
	rm -rf build/ccc
	rm -rf build/obj/*.o
###########################################################################