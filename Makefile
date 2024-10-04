# 编译器
COMPILER = g++
# 编译选项
C_FLAGS = 
# 编译模式选择
COMPILE_MODE = debug

ifeq ($(COMPILE_MODE), debug)
	C_FLAGS += -g -Og -W -Wall -std=c++17
else ifeq ($(COMPILE_MODE), release)
	C_FLAGS += -O3 -W -Wall -std=c++17
else
compile_mode_error:
	$(error Unknown compile mode: $(COMPILE_MODE))
endif


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
OUTPUT_PATH = $(BUILD_DIR)
 

all: build_folder ccc version help task template einip
	$(COMPILER) $(CCC_OBJ_FILES) $(VERSION_OBJ_FILES) $(HELP_OBJ_FILES) $(TASK_OBJ_FILES) $(TEMPLATE_OBJ_FILES) $(EINIP_OBJ_FILES) -o $(OUTPUT_PATH)/ccc

build_folder:
	mkdir -p $(OUTPUT_PATH) $(OBJ_PATH)

###########################################################################
# 编译CCC主体文件
CCC_FILES = $(wildcard src/*.cpp)
CCC_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(CCC_FILES)))
ccc: $(CCC_OBJ_FILES)
$(CCC_OBJ_FILES):  $(OBJ_PATH)/%.o: src/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译VERSION指令文件
VERSION_FILES = $(wildcard src/instructions/version/*.cpp)
VERSION_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(VERSION_FILES)))
version: $(VERSION_OBJ_FILES)
$(VERSION_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/version/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译HELP指令文件
HELP_FILES = $(wildcard src/instructions/help/*.cpp)
HELP_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(HELP_FILES)))
help: $(HELP_OBJ_FILES)
$(HELP_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/help/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译TASK指令文件
TASK_FILES = $(wildcard src/instructions/task/*.cpp)
TASK_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(TASK_FILES)))
task: $(TASK_OBJ_FILES)
$(TASK_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/task/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译TEMPLATE指令文件
TEMPLATE_FILES = $(wildcard src/instructions/template/*.cpp)
TEMPLATE_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(TEMPLATE_FILES)))
template: $(TEMPLATE_OBJ_FILES)
$(TEMPLATE_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/template/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)
###########################################################################

###########################################################################
# 编译EINIP库
EINIP_OBJ_FILES = $(OBJ_PATH)/ini.o
einip: $(OBJ_PATH)/ini.o
$(OBJ_PATH)/ini.o: third_party/EIniP/einip/ini.c
	$(COMPILER) -c third_party/EIniP/einip/ini.c -o $(OBJ_PATH)/ini.o -I third_party/EIniP/einip $(C_FLAGS)
###########################################################################

###########################################################################
install:
	@cp build/ccc /usr/local/bin
	@echo "Successfully installed CCC."
###########################################################################
 
###########################################################################
uninstall:
	@rm -rf /usr/local/bin/ccc
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