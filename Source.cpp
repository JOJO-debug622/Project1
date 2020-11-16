#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
using namespace std;


struct matrix

{
    int row;
    int column;
    double **m ;

};

matrix pm(matrix m1, matrix m2){
    matrix m;
    m.row = m1.row;
    m.column = m2.column;
    int x = m1.column;
    m.m = new double* [m.row];
    for (int i = 0; i < m.row; i++) {
        m.m[i] = new double[m.column];
        for (int j = 0; j < m.column; j++) {
            m.m[i][j]=0;
            for (int a = 0; a < x; a++) {
                m.m[i][j] += m1.m[i][a] * m2.m[a][j];
            }
        }
    }
    return m;
}

matrix pm2(matrix m1, matrix m2) {
    matrix m;
    m.row = m1.row;
    m.column = m2.column;
    int x = m1.column;
    m.m = new double* [m.row];
    for (int i = 0; i < m.row; i++) {
        m.m[i] = new double[m.column];
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

void showm(matrix m1, matrix m2,matrix m3) {
    if (m1.column == m2.row) {

        m3 = pm(m1, m2);

        cout << "有第一个矩阵左乘第二个矩阵得：" << endl;
        for (int i = 0; i < m3.row; i++) {
            for (int j = 0; j < m3.column; j++) {
                cout << m3.m[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (m1.row == m2.column) {
        m3 = pm(m2, m1);
        cout << "有第二个矩阵左乘第一个矩阵得：" << endl;
        for (int i = 0; i < m3.row; i++) {
            for (int j = 0; j < m3.column; j++) {
                cout << m3.m[i][j] << " ";
            }
            cout << endl;
        }
    }
}

matrix pm4(matrix m1, matrix m2) {
    matrix m;
    m.row = m1.row;
    m.column = m2.column;
    m.m = new double* [m.row];
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

int    main()

{
    using namespace std::literals;
 

    matrix m1,m2,m3;
    cout << "请输入第一个矩阵的行数和列数：";
    cin >> m1.row;
    cin >> m1.column;
    cout << "请输入第二个矩阵的行数和列数：";
    cin >> m2.row;
    cin >> m2.column;
    if (m2.row != m1.column && m2.column != m1.row) {
        cout << "这两个矩阵不可以相乘！"<<endl;
        return 0;
    }
   m1.m=new double *[m1.row];
   cout << "请输入矩阵一得元素：" << endl;
   for (int i = 0; i < m1.row; i++) {
       m1.m[i] = new double[m1.column];
       for (int j = 0; j < m1.column; j++) {
           m1.m[i][j] = 0;
           //cin >> m1.m[i][j];
       }
   }
   
   m2.m = new double* [m2.row];
   cout << "请输入矩阵二得元素：" << endl;
   for (int i = 0; i < m2.row; i++) {
       m2.m[i] = new double[m2.column];
       for (int j = 0; j < m2.column; j++) {
          m2.m[i][j] = 0;
          // cin >> m2.m[i][j];
       }
   }



   auto start = std::chrono::steady_clock::now();
   pm4(m1, m2);
   auto end = std::chrono::steady_clock::now();
   std::cout
       << "Slow calculations took "
       << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
       << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms";

   for (int i = 0; i < m1.row; i++)delete[]m1.m[i];
   delete[]m1.m;
   for (int i = 0; i < m2.row; i++)delete[]m2.m[i];
   delete[]m2.m;
    return 0;

} 