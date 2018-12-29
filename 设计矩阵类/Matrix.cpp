#include "Matrix.h"
#include <iostream>
using namespace std;

//矩阵构造函数，进行了动态内存分配
CMatrix::CMatrix(int rows = 10, int cols = 10):ROWS(rows),COLS(cols)
{
    m_matrix = new int*[ROWS];
    for(int i=0;i<ROWS;i++)
    {
        m_matrix[i] = new int[COLS];
        for(int j=0;j<COLS;j++)
        {
          m_matrix[i][j] = rand()%100;
		}
	}
}

//矩阵析构函数，释放动态分配的内存
CMatrix::~CMatrix()
{
    for(int i = 0 ;i<ROWS;i++)
	{  
    delete[] m_matrix[i];
	}
    delete[] m_matrix;
}

void CMatrix::Show()
{
	for(int i =0;i<ROWS;i++)
	{
      for(int j =0;j<COLS;j++)
        {
        cout << m_matrix[i][j] << "\t";
	  }
        cout << endl;
    }

}