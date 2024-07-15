## 文件所需变量
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

## 关于变量
##### 如果想使用CCC组织项目，则ccc文件中必须包含必要变量，否则无法使用。

## 必要变量
|变量名称|值|解释|
|:-|:-:|:-|
|target_type|1. c<br>2. c++|指定编译源文件为c还是c++|
|compiler||指定编译器|
|linker||指定链接器|
|source_sig_files<br>或source_folder_path||源文件组，两个变量至少有一个有值|
|obj_path||中间文件存放路径|
|output_path||输出文件存放路径|

## 非必要变量
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
#### （一）变量的等号两边都要留空格。
#### （二）注释为以#开头的单行注释。
