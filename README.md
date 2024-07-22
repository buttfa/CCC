# <div align="center">CCC</div>
### <div align="center">![CCC_ICON](img/icon.png)</div>

### <div align="center">|[简体中文](README.md)|[English](doc/en/README_en.md)|</div>

## <div align="center">目录</div> 
- [项目名称](#项目名称)
- [项目简介](#项目简介)
- [安装以及卸载方式](#安装以及卸载方式)
- [使用方法](#使用方法)
 
## 项目名称 
#### CCC / C-series compiler coprocessor

## 项目简介
#### 本项目旨在提供一个Linux下简单的构建工具，用于将多个c/c++源文件编译成目标文件。
 
## 安装以及卸载方式
#### （一）编译项目  
```c
make 
// 或（已经安装CCC的前提下）
ccc ccc.ccc
```
#### （二）安装项目
```c
make install
```
#### （三）删除中间文件
```c
make clean
// 或（已经安装CCC的前提下）
ccc ccc.ccc clean
``` 
#### （四）卸载项目
```c
make uninstall
``` 


## 使用方法
#### （一）创建.ccc文件
##### 创建XXX.ccc文件。其中的具体内容，请参考如下本项目下的[CCC.md](doc/cn/CCC.md)
#### （二）编辑.ccc文件  
##### 其中的具体内容，请参考如下本项目下的[CCC.md](doc/cn/CCC.md)
#### （三）运行ccc命令
##### 运行ccc XXX.ccc命令执行ccc文件中的第一个任务，或ccc XXX.ccc task_name命令执行ccc文件中的指定任务。
<!--#### （四）删除中间文件-->
<!--##### 运行ccc $(ccc_file) clean命令，即可删除中间文件。-->


<!--## 关于依赖
#### CCC会为每个.c/.cpp文件创建.o文件，并为这些.o文件建立依赖，依赖的文件为对应的.c/.cpp以及.c/.cpp包含的头文件。因此，当你修改某个.o的对应的.c/.cpp文件以及.c/.cpp包含的头文件时，这个.o文件会重新编译。
#### 此外，最终的输出文件依赖于所有的.o文件。-->