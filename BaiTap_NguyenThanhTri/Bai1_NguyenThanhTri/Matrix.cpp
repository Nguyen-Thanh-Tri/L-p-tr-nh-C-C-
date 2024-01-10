#include <iostream>
#include "Matrix.h"
using namespace std;
Matrix::Matrix(int size):n(size){
    data = new int*[n];
    for (int i=0;i<n;i++){
        data[i] = new int[n];
    }} //Hàm dựng
Matrix::~Matrix(){
    for (int i=0; i<n;i++){ 
    delete [] data[i];}
    delete [] data;
}
//Hàm dựng sao chép
Matrix::Matrix(const Matrix &v) : n(v.n){   
    data = new int*[n];
    for (int i=0; i<n;i++){
        data[i] = new int[n];
        for (int j=0; j<n;++j){
            data[i][j]= v.data[i][j];
        }
    }
}
//Toán tử +
Matrix Matrix::operator +(const Matrix &v)const{
    Matrix result0(n);
    for (int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            result0.data[i][j]= this->data[i][j] + v.data[i][j];
        }
    }
    return result0;
}
//Toán tử -
Matrix Matrix::operator -(const Matrix &v)const{
    Matrix result1(n);
    for (int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            result1.data[i][j]= this->data[i][j] - v.data[i][j];
        }
    }
    return result1;
}
// Toán tử *
Matrix Matrix::operator *(const Matrix &v)const{
    Matrix result2(n);
    for (int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            result2.data[i][j]= this->data[i][j] * v.data[i][j];
        }
    }
    return result2;
}
//toán tử gán
Matrix &Matrix::operator =(const Matrix &v){
    if(this != &v){
        for(int i=0;i<n;i++){
            delete [] data[i];
        }
        delete [] data;
        n = v.n;
        data = new int*[n];
        for(int i=0;i<n;i++){
            data[i]= new int[n];
            for(int j=0;j<n;j++){
                data[i][j] = v.data[i][j];
            }
        }
    }
    return *this;
}
//Toán tử truy xuất
int &Matrix::operator () (int row,int col){
    return data[row-1][col-1];
}
//Nhập
istream &operator >>(istream &in, Matrix &matrix){
    for(int i =0; i < matrix.n; i++){
        for(int j=0;j < matrix.n; j++){
            in >> matrix.data[i][j];
        }
    }
    return in;
}
//Xuất
ostream &operator <<(ostream &out, const Matrix &matrix){
    for(int i =0; i < matrix.n; i++){
        cout << endl;
        for(int j=0;j < matrix.n; j++){
            out << matrix.data[i][j]<<" ";
        }
    }
    return out;
}

