## Project Name
#### CCC / C-series compiler coprocessor

## Project Introduction
#### This project aims to provide a simple build tool for Linux, which is used to compile multiple c/c++source files into target files.

## Installation and uninstallation methods
#### （1） Compile project
```c
make 
//Or
make ccc 
//Or (provided that CCC has been installed)
ccc ccc.ccc
```
#### （2） Installation project
```c
make install
```
#### （3） Delete intermediate files
```c
make clean
```
#### （4） Uninstall Project
```c
make uninstall
```

## Usage
#### （1） Create a. ccc file
##### Create a \$(ccc_file). ccc file in the root directory of the project. For specific details, please refer to CCC.md under this project
#### （2） Edit. ccc file
##### For specific details, please refer to CCC.md under this project
#### （3） Run the CCC command
##### Run the ccc (ccc_file) command to compile multiple source files into target files. (The file name of the target file is (ccc_file), which is stored in the path of (output_path) in the ccc file.)
<!--####  （4） Delete intermediate files -->
<!--#####  Run the ccc $(ccc_file) clean command to delete intermediate files. -->

## About dependencies
#### CCC will create. o files for each. c/. cpp file and establish dependencies for these. o files. The dependent files are the corresponding. c/. cpp and the header files contained in. c/. cpp. Therefore, when you modify the corresponding. c/. cpp file for a certain. o and the header files contained in. c/. cpp, the. o file will be recompiled.
#### In addition, the final output file depends on all. o files.