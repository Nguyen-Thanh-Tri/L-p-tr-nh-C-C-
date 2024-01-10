// Bài 1:
// Cài đặt lớp Matrix để biểu diễn 01 ma trận vuông cấp n các số nguyên
// gồm n là cấp của ma trân và 01 mảng động 2 chiều chưa các phần tử của 
// ma trận; và các hàm: hàm dựng, hàm dựng sao chép, hàm hủy, các phép toán 
// +, -, * 2 ma trận; các phép toán >>, << để nhập, xuất ma trận; toán tử = 
// gán 2 ma trận; toán tử ( ) để truy xuất phần tử của ma trận
#include "Matrix.h"
#include "Matrix.cpp"
#include <iostream>
using namespace std;
int main(){
    int size;
    cout <<"Cấp của Matrix : ";
    cin >> size;
    //khai báo
    Matrix a(size);
    Matrix b(size);
    cout << endl <<"Phần tử ma trận một :"<<endl;
    cin >> a;
    cout << endl <<"Phần tử ma trận hai :"<<endl;
    cin >> b;
    cout <<"Ma trận a:"<<endl<< a << endl <<"Ma trận b:"<<endl<< b << endl;
    //Tổng,Hiệu,Tích
    Matrix s = a + b;
    cout << endl <<"Tổng :"<< endl << s ;
    Matrix d = a - b;
    cout << endl <<"Hiệu :"<< endl << d;
    Matrix m = a * b;
    cout << endl <<"Tích :"<< endl << m;
    cout << endl;
    //Truy xuất
    int i,j;
    cout << " Phần tử tại hàng ";cin >> i; cout << "và cột ";cin >> j; cout << "của ma trận a là:" <<a(i,j);
    cout<<endl << " Phần tử tại hàng ";cin >> i; cout << "và cột ";cin >> j; cout << "của ma trận b là:" <<b(i,j);
return 0;
}