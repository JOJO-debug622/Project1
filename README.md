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
! []
(https://github.com/JOJO-debug622/Project1/blob/main/picture/1.PNG)
## 二、运算加速优化：
* 使用最基本算法（三重循环）时，一亿个元素的矩阵在10分钟内没有出结果，故使用1000*1000的矩阵先计算：
![]
(https://github.com/JOJO-debug622/Project1/blob/main/picture/3.PNG)

* 联想之前学习向量乘法时候的方法，使用每次循环时算八个运算的方法：
```cpp
matrix pm2(matrix m1, matrix m2) {
    matrix m;
    m.row = m1.row;
    m.column = m2.column;
    int x = m1.column;
    m.m = new double* [m.row];
    for (int i = 0; i < m.row; i++) {
        m.m[i] = new double[m.column];
        for (int j = 0; j < m.column; j++) {
            m.m[i][j] = 0;
        }
    }
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.column; j+=8) {
            for (int a = 0; a < x; a++) {
                m.m[i][j] += m1.m[i][a] * m2.m[a][j];
                m.m[i][j+1] += m1.m[i][a] * m2.m[a][j+1];
                m.m[i][j+2] += m1.m[i][a] * m2.m[a][j+2];
                m.m[i][j+3] += m1.m[i][a] * m2.m[a][j+3];
                m.m[i][j+4] += m1.m[i][a] * m2.m[a][j+4];
                m.m[i][j+5] += m1.m[i][a] * m2.m[a][j+5];
                m.m[i][j+6] += m1.m[i][a] * m2.m[a][j+6];
                m.m[i][j+7] += m1.m[i][a] * m2.m[a][j+7];
               
            }
        }
    }
    return m;
}
```
即每个m1中的元素乘以m2中的八个元素，再分别添加到相应的位置，用时：
! []
(https://github.com/JOJO-debug622/Project1/blob/main/picture/4.PNG)

* 有考虑了另外一种每次循环多次计算的方法：
```cpp
matrix pm3(matrix m1, matrix n) {
    matrix m;
    m.row = m1.row;
    m.column = n.column;
    int x = m1.column;
    m.m = new double* [m.row];
    for (int i = 0; i < m.row; i++)
    {
        m.m[i] = new double[m.column];
        for (int j = 0; j < m.column; j++)
        {
            m.m[i][j] = 0;
            for (int l = 0; l < m1.column; l += 8)
            {
                m.m[i][j] +=
                    m1.m[i][l] * n.m[l][j] +
                    m1.m[i][l + 1] * n.m[l + 1][j] +
                    m1.m[i][l + 2] * n.m[l + 2][j] +
                    m1.m[i][l + 3] * n.m[l + 3][j] +
                    m1.m[i][l + 4] * n.m[l + 4][j] +
                    m1.m[i][l + 5] * n.m[l + 5][j] +
                    m1.m[i][l + 6] * n.m[l + 6][j] +
                    m1.m[i][l + 7] * n.m[l + 7][j];
            }
        }
    }

    return m;
}
```
最后的用时：
! []
(https://github.com/JOJO-debug622/Project1/blob/main/picture/5.PNG)
速度不如第二种方法。
* 考虑了每次循环多个运算，考虑到是矩阵，可以将矩阵分割，横向纵向同时多个计算：
```cpp
matrix pm4(matrix m1, matrix m2) {
    matrix m;
    m.row = m1.row;
    m.column = m2.column;
    m.m = new double* [m.row];
    for (int i = 0; i < m.row; i++) {
        m.m[i] = new double[m.column];
        for (int j = 0; j < m.column; j++) {
            m.m[i][j] = 0;
        }
    }

    for (int i = 0; i < m.row-4; i+=4) {
        for (int j = 0; j < m.column-4; j+=4) {
            for (int l = 0; l < m1.column;l++) {
                m.m[i][j] += m1.m[i][l] * m2.m[l][j];
                m.m[i+1][j] += m1.m[i+1][l] * m2.m[l][j];
                m.m[i+2][j] += m1.m[i+2][l] * m2.m[l][j];
                m.m[i+3][j] += m1.m[i+3][l] * m2.m[l][j];
               
                m.m[i][j+1] += m1.m[i][l] * m2.m[l][j+1];
                m.m[i + 1][j+1] += m1.m[i + 1][l] * m2.m[l][j+1];
                m.m[i + 2][j+1] += m1.m[i + 2][l] * m2.m[l][j+1];
                m.m[i + 3][j+1] += m1.m[i + 3][l] * m2.m[l][j+1];
             
                m.m[i][j + 2] += m1.m[i][l] * m2.m[l][j + 2];
                m.m[i + 1][j + 2] += m1.m[i + 1][l] * m2.m[l][j + 2];
                m.m[i + 2][j + 2] += m1.m[i + 2][l] * m2.m[l][j + 2];
                m.m[i + 3][j + 2] += m1.m[i + 3][l] * m2.m[l][j + 2];
               
                m.m[i][j + 3] += m1.m[i][l] * m2.m[l][j + 3];
                m.m[i + 1][j + 3] += m1.m[i + 1][l] * m2.m[l][j + 3];
                m.m[i + 2][j + 3] += m1.m[i + 2][l] * m2.m[l][j + 3];
                m.m[i + 3][j + 3] += m1.m[i + 3][l] * m2.m[l][j + 3];


            }
        }
    }
    return m;
    for (int i = 0; i < m.row; i++)delete[]m.m[i];
    delete[]m.m;
}
```
最后的用时：
! []
(https://github.com/JOJO-debug622/Project1/blob/main/picture/6.PNG)
是初始用时的近四分之一。
暂时没有想到更好的提速方法。

## 三、与openblas相比：
* 使用openblas上的方法写出代码：
```cpp

{
	const int M = 1000;
	const int N = 1000;
	const int K = 1000;
	const float alpha = 1;
	const float beta = 0;
	const int lda = M;
	const int ldb = K;
	const int ldc = N;
	const float* A = new float[M * K];
	const float *B=new float[N * K] ;
	float *C=new float[M * N];

	auto start = std::chrono::steady_clock::now();
	cblas_sgemm(CblasRowMajor, CblasTrans, CblasTrans, M, N, K, alpha, A, lda, B, ldb, beta, C, ldc);
	auto end = std::chrono::steady_clock::now();
	std::cout
		<< "Slow calculations took "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms";

}
```
用时：
! {}
(https://github.com/JOJO-debug622/Project1/blob/main/picture/openblas%EF%BC%88%E5%B0%8F%EF%BC%89.PNG)
计算10000*10000的矩阵用时：
! []
(https://github.com/JOJO-debug622/Project1/blob/main/picture/openblas.PNG)
实在是比不了。

## 四、疑问
* 还是很不了解提速的办法和关键，学术不够也很难看懂网上大神们的方法。任重道远。
