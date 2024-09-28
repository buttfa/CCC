# <div align="center">CCC</div>
### <div align="center">![CCC_ICON](img/icon.png)</div>

### <div align="center">|[简体中文](doc/cn/README.md)|[English](README.md)|</div>

## <div align="center">Directory</div>
- [Project Name](#project-name)
- [Project Introduction](#project-introduction)
- [Installation and uninstallation methods](#installation-and-uninstallation-methods)
- [Usage](#usage)
  - [Method 1: Create your own. ccc file](#method-1-create-your-own-ccc-file)
## Project Name
#### CCC / C-series compiler coprocessor

## Project Introduction
#### This project aims to provide a simple build tool for Linux, which is used to compile multiple c/c++ source files into target files.

## Installation and uninstallation methods
#### （1） Compile project
```c
make COMPILE_MODE=release
// Or (provided that CCC has been installed)
ccc release
```
#### （2） Installation project
```c
make install
```
#### （3） Delete intermediate files and target
```c
make clean
// Or (provided that CCC has been installed)
ccc clean
``` 
#### （4） Uninstall Project
```c
make uninstall
```

## Usage
<!-- #### Method 1: Create a C/C++ project using CCC
##### Create a C/C++ project
```c
// Create a C project
ccc newc project_name
// Create a C++ project
ccc newcpp project_name
```
##### Compile project
```c
// Enter the project directory
cd project_name
// Compile only
ccc project_name.ccc
// Compile and run
ccc project_name.ccc run
// Delete intermediate and target files
ccc project_name.ccc clean
``` -->

#### Method 1: Create your own. ccc file
#### If you have already created a project, you can create a .ccc file by yourself to manage the project.
#### （1） Create a .ccc file
##### Create an XXX.ccc file(Recommended to be named project.ccc). Please refer to the [CCC_en.md](doc/en/CCC_en.md) under this project for specific content.
#### （2） Edit .ccc file
##### For specific details, please refer to [CCC_en.md](doc/en/CCC_en.md) under this project
#### （3） Run the CCC command
##### Run the ```ccc XXX.ccc``` command to execute the first task in the ccc file, or the ```ccc XXX.ccc task_name``` command to execute the specified task in the ccc file.(If the .ccc file name is project.ccc, then XXX.ccc can be omitted)

<!--## About dependencies
#### CCC will create. o files for each. c/. cpp file and establish dependencies for these. o files. The dependent files are the corresponding. c/. cpp and the header files contained in. c/. cpp. Therefore, when you modify the corresponding. c/. cpp file for a certain. o and the header files contained in. c/. cpp, the. o file will be recompiled.
#### In addition, the final output file depends on all. o files.-->