#pragma once
class CMatrix
{
private:
    const int ROWS,COLS;
    int **m_matrix;


public:
	CMatrix(int rows,int cols);
	~CMatrix(void);	
	
	void Show();
	void InputVal(int row, int col);
	void Transpose();
};

