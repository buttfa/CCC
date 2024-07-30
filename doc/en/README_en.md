# <div align="center">CCC</div>
### <div align="center">![CCC_ICON](../../img/icon.png)</div>

### <div align="center">|[简体中文](../../README.md)|[English](README_en.md)|</div>

## <div align="center">Directory</div>
- [Project Name](#project-name)
- [Project Introduction](#project-introduction)
- [Installation and uninstallation methods](#installation-and-uninstallation-methods)
- [Usage](#usage)

## Project Name
#### CCC / C-series compiler coprocessor

## Project Introduction
#### This project aims to provide a simple build tool for Linux, which is used to compile multiple c/c++source files into target files.

## Installation and uninstallation methods
#### （1） Compile project
```c
make 
// Or (provided that CCC has been installed)
ccc ccc.ccc
```
#### （2） Installation project
```c
make install
```
#### （3） Delete intermediate files and target
```c
make clean
// Or (provided that CCC has been installed)
ccc ccc.ccc clean
``` 
#### （4） Uninstall Project
```c
make uninstall
```

## Usage
#### （1） Create a. ccc file
##### Create an XXX.ccc file. Please refer to the [CCC_en.md](CCC_en.md) under this project for specific content
#### （2） Edit. ccc file
##### For specific details, please refer to [CCC_en.md](CCC_en.md) under this project
#### （3） Run the CCC command
##### Run the ccc XXX.ccc command to execute the first task in the ccc file, or the ccc XXX.ccc taskname command to execute the specified task in the ccc file.
<!--####  （4） Delete intermediate files -->
<!--#####  Run the ccc $(ccc_file) clean command to delete intermediate files. -->

<!--## About dependencies
#### CCC will create. o files for each. c/. cpp file and establish dependencies for these. o files. The dependent files are the corresponding. c/. cpp and the header files contained in. c/. cpp. Therefore, when you modify the corresponding. c/. cpp file for a certain. o and the header files contained in. c/. cpp, the. o file will be recompiled.
#### In addition, the final output file depends on all. o files.-->