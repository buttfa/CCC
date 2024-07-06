## 文件所需变量
```c
target_type =

compiler =
compile_flags = 

linker = 
linker_flags =

source_folder_path =
header_folder_path =

sll_folder_path =
dll_folder_path =

obj_path =
output_path =

library_path =
```

## 解释说明
|变量名称|值|解释|
|-|-|-|
|target_type|1. c<br>2. c++|指定编译源文件为c还是c++|
|compiler||指定编译器|
|compiler_flags||编译器编译选项|
|linker||指定链接器|
|linker||链接器链接选项|
|source_folder_path||源文件文件夹路径|
|header_folder_path||头文件文件夹路径|
|sll_folder_path||静态链接库的路径|
|dll_folder_path||动态链接库的路径|
|obj_path||中间文件存放路径|
|output_path||输出文件存放路径|
|library_path||外部库文件路径|

## 关于变量
#### 对于一个基于CCC的项目，上述中必要的变量有：
```c
target_type
compiler
linker
source_folder_path
obj_path
output_path。
```

## 关于书写格式
#### （一）变量的等号两边都要留空格。
#### （二）注释为以#开头的单行注释。
