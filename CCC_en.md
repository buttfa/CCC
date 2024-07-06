## Variable required for file
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

## Explanation
|Variable Name | Value | Explanation|
|-|-|-|
|target_type|1.  C<br>2. c++| Specify whether to compile the source file as c or c++|
|Compiler | | Specify the compiler|
|Compiler flags | | compiler compilation options|
|Linker | | Specify linker|
|Linker | | Linker Link Options|
|Source_folder_path | | Source file folder path|
|Header_folder_path | | Path to the header file folder|
|SLL_folder_path | | Path to the static link library|
|Dll-folder_path | | Path to the dynamic link library|
|Obj_path | | Path for storing intermediate files|
|Output_path | | The path where the output file is stored|
|Library_path | | External library file path|

## About variables
#### For a CCC based project, the necessary variables mentioned above are:
```c
target_type
compiler
linker
source_folder_path
obj_path
output_path。
```

## About Writing Format
#### （1） Leave spaces on both sides of the equal sign for variables.
#### （2） Annotations are single line comments starting with #.