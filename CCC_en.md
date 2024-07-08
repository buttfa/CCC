## Variable required for file
```c
target_type =

compiler =
compile_flags = 

linker = 
linker_flags =

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

## About variables
##### If you want to use CCC to organize a project, the necessary variables must be included in the CCC file, otherwise it cannot be used.

## Necessary variables
|Variable Name | Value | Explanation|
|:-|:-:|:-|
|target_type|1.  C<br>2. c++| Specify whether to compile the source file as c or c++|
|Compiler | | Specify the compiler|
|Linker | | Specify linker|
|Source_sig_files<br>or source_folder_path | | Source file group, where at least one of the two variables has a value|
|Obj_path | | Path for storing intermediate files|
|Output_path | | The path where the output file is stored|

## Non essential variables
|Variable Name | Value | Explanation|
|-|-|-|
|Compiler flags | | compiler compilation options|
|Linker | | Linker Link Options|
|Source_sig_files | | Source file group|
|Header_sig_files | | Header file group|
|Header_folder_path | | Path to the header file folder|
|SLL_files | | Static link library file group|
|SLL_folder_path | | Path to the static link library|
|Dll-files | | Dynamic Link Library file group|
|Dll-folder_path | | Path to the dynamic link library|
|Library_path | | External library file path|


## About Writing Format
#### （1） Leave spaces on both sides of the equal sign for variables.
#### （2） Annotations are single line comments starting with #.
