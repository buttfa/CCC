## <div align="center">目录</div> 
- [ccc文件格式](#ccc文件格式)
- [任务格式](#任务格式)
- [关于书写格式](#关于书写格式)

## ccc文件格式
#### ccc文件形式上是ini文件，内容上是以任务为组织方式的文件。CCC任务包含Shell任务和Task任务。

## 任务格式
#### 1. Shell任务
#### 要求secion_name以\<shell>开头，该section中键值对的键为执行前的输出内容，值为要执行的Shell命令。（如果不希望在执行前输出键，则在键前加(null)或(NULL)）如下：
```c
[<shell>example]
first = echo "hello world"
(null)seconde = echo "Hello world!"
```

#### 2. Task任务
#### 要求secion_name以\<task>开头，该section的键值对视为编译任务所需的变量，详情请看[Task任务变量](#task任务变量)、[Task任务必要变量](#task任务必要变量)和[Task任务非必要变量](#task任务非必要变量)。其中编译的最终目标为section_name中除去\<task>的部分。例如，以下示例将编译出ccc文件作为最终目标：
```c
[<task>ccc]
target_type  = c
compiler = gcc
linker = gcc
source_folder_path = src
header_folder_path = inc
obj_path = build/obj
output_path = build
library_path = lib
```

## Task任务变量
```c
target_type =

compiler =
compile_flags = 

linker = 
link_flags =

source_sig_files = 
source_folder_path =
header_sig_files = 
header_folder_path =

sll_sig_files = 
sll_folder_path = 
dll_sig_files = 
dll_folder_path =

obj_path =
output_path =

library_path =
```
## Task任务必要变量
|变量名称|值|解释|
|:-|:-:|:-|
|target_type|1. c<br>2. c++|指定编译源文件为c还是c++|
|compiler||指定编译器|
|linker||指定链接器|
|source_sig_files<br>或source_folder_path||源文件组，两个变量至少有一个有值|
|obj_path||中间文件存放路径|
|output_path||输出文件存放路径|

## Task任务非必要变量
|变量名称|值|解释|
|-|-|-|
|compile_flags||编译器编译选项|
|linker||链接器链接选项|
|source_sig_files||源文件组|
|header_sig_files||头文件组|
|header_folder_path||头文件文件夹路径|
|sll_files||静态链接库文件组|
|sll_folder_path||静态链接库的路径|
|dll_files||动态链接库文件组|
|dll_folder_path||动态链接库的路径|
|library_path||外部库文件路径|


## 关于书写格式
#### （一）注释为以#开头的单行注释。
