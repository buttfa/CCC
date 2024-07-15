## Variable required for file
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

## About variables
##### If you want to use CCC to organize a project, the necessary variables must be included in the CCC file, otherwise it cannot be used.

## Necessary variables
|Variable Name | Value | Explanation|
|:-|:-:|:-|
|target_type|1.  c<br>2. c++| Specify whether to compile the source file as c or c++|
|compiler | | Specify the compiler|
|linker | | Specify linker|
|source_sig_files<br>or source_folder_path | | Source file group, where at least one of the two variables has a value|
|obj_path | | Path for storing intermediate files|
|output_path | | The path where the output file is stored|

## Non essential variables
|Variable Name | Value | Explanation|
|-|-|-|
|compile_flags | | compiler compilation options|
|link_flags | | Linker Link Options|
|source_sig_files | | Source file group|
|header_sig_files | | Header file group|
|header_folder_path | | Path to the header file folder|
|sll_files | | Static link library file group|
|sll_folder_path | | Path to the static link library|
|dll_files | | Dynamic Link Library file group|
|dll_folder_path | | Path to the dynamic link library|
|library_path | | External library file path|


## About Writing Format
#### （1） Leave spaces on both sides of the equal sign for variables.
#### （2） Annotations are single line comments starting with #.
