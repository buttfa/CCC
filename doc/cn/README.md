# <div align="center">CCC</div>
### <div align="center">![CCC_ICON](../../img/icon.png)</div>

### <div align="center">|[简体中文](README.md)|[English](../../README.md)|</div>

## <div align="center">目录</div> 
- [项目名称](#项目名称)
- [项目简介](#项目简介)
- [安装以及卸载方式](#安装以及卸载方式)
- [使用方法](#使用方法)
  <!-- - [方法一：使用CCC创建C/C++工程](#方法一使用ccc创建cc工程) -->
  - [方法一：自行创建CCC文件](#方法一自行创建ccc文件)
## 项目名称 
#### CCC / C-series compiler coprocessor
 
## 项目简介
#### 本项目旨在提供一个Linux下简单的构建工具，用于将多个c/c++源文件编译成目标文件。
  
## 安装以及卸载方式
#### （一）编译项目  
```c
make COMPILE_MODE=release
// 或（已经安装CCC的前提下）
ccc release
```
#### （二）安装项目
```c
sudo make install
```
#### （三）删除中间文件
```c
make clean
// 或（已经安装CCC的前提下）
ccc clean
``` 
#### （四）卸载项目
```c
sudo make uninstall
``` 


## 使用方法
<!-- #### 方法一：使用CCC创建C/C++工程
##### 创建C/C++工程
```c
// 创建C工程
ccc newc project_name
// 创建C++工程
ccc newcpp project_name
```
##### 编译工程
```c
// 进入工程目录
cd project_name
// 仅编译
ccc project_name.ccc 
// 编译并运行
ccc project_name.ccc run
// 删除中间和目标文件
ccc project_name.ccc clean
``` -->

#### 方法一：自行创建.ccc文件
#### 如果您已经创建好工程，可以通过自行创建.ccc文件的方式，来实现CCC管理工程。
#### （一）创建.ccc文件
##### 创建XXX.ccc文件（推荐命名为project.ccc）。其中的具体内容，请参考如下本项目下的[CCC.md](CCC.md)
#### （二）编辑.ccc文件  
##### 其中的具体内容，请参考如下本项目下的[CCC.md](CCC.md)
#### （三）运行ccc命令
##### 运行```ccc XXX.ccc```命令执行ccc文件中的第一个任务，或```ccc XXX.ccc task_name```命令执行ccc文件中的指定任务。（如果.ccc文件名为project.ccc，则XXX.ccc可以省略）