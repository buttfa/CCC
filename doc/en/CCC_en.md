## <div align="center">Directory</div>
- [CCC file format](#ccc-file-format)
- [Task format](#task-format)
- [About Writing Format](#about-writing-format)

## CCC file format
#### The ccc file is in the form of an ini file, and its content is organized by tasks. CCC tasks include Shell tasks and Compile tasks.

## Task format
#### 1. Shell task
#### Require that the section_name starts with \<shell>, the key in  the key value pairs represent the output content before execution, and the value represents the shell command to be executed. If you do not want to output a key before execution, add (null) or (NULL) before the key as follows:
```c
[<shell>example]
first = echo "hello world"
(null)seconde = echo "Hello world!"
```

#### 2. Compile Task
#### Require section_name to start with \<task>, and the key value pairs in this section are considered as variables required for compiling tasks. For details, please refer to [Task Variables](#task-variable), [Task Required Variables](#task-required-variables), and [Task Non Essential Variables](#task-non-essential-variables). The ultimate goal of compilation is to remove the part of \<task> from section_name. For example, the following example will compile a ccc file as the final destination:
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

## Task variable
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

## Task Required Variables
|Variable Name|Value|Explanation|
|:-|:-:|:-|
|target_type|1. c<br>2. c++|Specify whether to compile the source file as c or c++|
|compiler||Specify the compiler|
|linker||Specify the linker|
|source_sig_files<br>or source_folder_path ||Source file group, where at least one of the two variables has a value|
|obj_path||Path for storing intermediate files|
|output_path||The path where the output file is stored|

## Task non essential variables
|Variable Name|Value|Explanation|
|-|-|-|
|compile_flags||Compiler compilation options|
|link_flags||Linker Link Options|
|source_sig_files||Source file group|
|header_sig_files||Header file group|
|header_folder_path|| Path to the header file folder|
|sll_files||Static link library file group|
|sll_folder_path|| Path to the static link library|
|dll_files||Dynamic Link Library file group|
|dll_folder_path||Path to the dynamic link library|
|library_path||External library file path|


## About Writing Format
#### （1） Annotations are single line comments starting with #.
