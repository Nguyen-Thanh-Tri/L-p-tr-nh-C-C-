#ifndef Matran_h
#define Matran_h
#include <iostream>
using namespace std;
class Matrix{
private: 
    int n;
    int** data;
public:
        Matrix(int size);  //Hàm dựng
        Matrix(const Matrix &v);  //Hàm dựn sao chép
       ~Matrix();   //Hàm huỷ
       //Toán tử logic
        Matrix &operator =(const Matrix &v);
        Matrix operator +(const Matrix &v) const;
        Matrix operator -(const Matrix &v) const;
        Matrix operator *(const Matrix &v) const;
        int &operator () (int row,int col);
        //Nhập xuất
        friend istream &operator >>(istream &in, Matrix &matrix);
        friend ostream &operator <<(ostream &out,const Matrix &matrix);
};
#endif

