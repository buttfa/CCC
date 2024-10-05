# Compiler
COMPILER = g++
# Compiler flags
C_FLAGS = 
# Linker
LINKER = g++
# Linker flags
L_FLAGS =
# Compile mode: debug/release
COMPILE_MODE = debug

# Determine compilation flags through compilation mode
ifeq ($(COMPILE_MODE), debug)
	C_FLAGS += -g -Og -W -Wall -std=c++17
else ifeq ($(COMPILE_MODE), release)
	C_FLAGS += -O3 -W -Wall -std=c++17
else
compile_mode_error:
	$(error Unknown compile mode: $(COMPILE_MODE))
endif


# Header folders path
C_INCLUDE = -I inc \
-I inc/instructions/task \
-I inc/instructions/help \
-I inc/instructions/version \
-I inc/instructions/template \
-I third_party/EIniP/einip

# Build directory path
BUILD_DIR = build
# Object file storage directory path
OBJ_PATH = $(BUILD_DIR)/obj
# CCC executable file storage path
OUTPUT_PATH = $(BUILD_DIR)
 

all: build_folder ccc version help task template einip
	$(LINKER) $(L_FLAGS) $(CCC_OBJ_FILES) $(VERSION_OBJ_FILES) $(HELP_OBJ_FILES) $(TASK_OBJ_FILES) $(TEMPLATE_OBJ_FILES) $(EINIP_OBJ_FILES) -o $(OUTPUT_PATH)/ccc

build_folder:
	mkdir -p $(OUTPUT_PATH) $(OBJ_PATH)


# Compile CCC main files
CCC_FILES = $(wildcard src/*.cpp)
CCC_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(CCC_FILES)))
ccc: $(CCC_OBJ_FILES)
$(CCC_OBJ_FILES):  $(OBJ_PATH)/%.o: src/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)


# Compile version command file
VERSION_FILES = $(wildcard src/instructions/version/*.cpp)
VERSION_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(VERSION_FILES)))
version: $(VERSION_OBJ_FILES)
$(VERSION_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/version/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)


# Compile help command file
HELP_FILES = $(wildcard src/instructions/help/*.cpp)
HELP_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(HELP_FILES)))
help: $(HELP_OBJ_FILES)
$(HELP_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/help/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)


# Compile task instruction file
TASK_FILES = $(wildcard src/instructions/task/*.cpp)
TASK_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(TASK_FILES)))
task: $(TASK_OBJ_FILES)
$(TASK_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/task/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)


# Compile template instruction file
TEMPLATE_FILES = $(wildcard src/instructions/template/*.cpp)
TEMPLATE_OBJ_FILES = $(patsubst %.cpp, $(OBJ_PATH)/%.o, $(notdir $(TEMPLATE_FILES)))
template: $(TEMPLATE_OBJ_FILES)
$(TEMPLATE_OBJ_FILES):  $(OBJ_PATH)/%.o: src/instructions/template/%.cpp
	$(COMPILER) -c $^ -o $@ $(C_INCLUDE) $(C_FLAGS)


# Compile EIniP library
EINIP_OBJ_FILES = $(OBJ_PATH)/ini.o
einip: $(OBJ_PATH)/ini.o
$(OBJ_PATH)/ini.o: third_party/EIniP/einip/ini.c
	$(COMPILER) -c third_party/EIniP/einip/ini.c -o $(OBJ_PATH)/ini.o -I third_party/EIniP/einip $(C_FLAGS)


install:
	@cp build/ccc /usr/local/bin
	@echo "Successfully installed CCC."


uninstall:
	@rm -rf /usr/local/bin/ccc
	@echo "Successfully uninstalled CCC."


test:
	make -C test


clean:
	rm -rf build/ccc
	rm -rf build/obj/*.o