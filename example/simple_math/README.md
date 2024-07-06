## 项目名称
#### simple_math

## 项目描述
#### 作为简单的案例展示CCC的使用方法

## 编译方法
```c
// 1. 编译math.a
// my_math.a为包含函数库的静态库
ccc my_math.a.ccc
```
```c
// 2. 编译main
// main为调用my_math.a的测试程序
ccc main.ccc
```