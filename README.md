# Project1
matrix product
## 一、基本代码：
* 首先定义矩阵结构struct：
``` cpp
struct matrix{
    int row;
    int column;
    double **m ;
};
```
m是代表矩阵的个元素
* 最基本的算法下抛出的结果：
![]
(https://github.com/JOJO-debug622/Project1/blob/main/picture/1.PNG)
## 二、运算加速优化：
* 使用最基本算法（三重循环）时，一亿个元素的矩阵在10分钟内没有出结果，故使用1000*1000的矩阵先计算：
