#include <iostream>
#include "Dathuc.h"
using namespace std;
// Hàm dựng
Dathuc::Dathuc(int bac) : n(bac){
    data = new double[n+1];
    for (int i=0; i<=n; i++){
        data[i]=0.0;
    }
}
//Hàm dựng sao chép
Dathuc::Dathuc(const Dathuc& dt) : n(dt.n){
    data = new double[n+1];
    for(int i=0;i<=n;i++){
        data[i]=dt.data[i];
    }
}
//Hàm huỷ
Dathuc::~Dathuc(){
    delete [] data;
}
//Toán tử cộng
Dathuc Dathuc::operator +(const Dathuc &dt)const{
    int maxbac= max(n, dt.n);
    Dathuc result1(maxbac);
    for(int i=0;i<=maxbac;i++){
        result1[i] = ((*this)[i]) + dt[i];
    }
    return result1;
}
//trừ
Dathuc Dathuc::operator -(const Dathuc &dt)const{
    int maxbac= max(n, dt.n);
    Dathuc result2(maxbac);
    for(int i=0;i<=maxbac;i++){
        result2[i] = ((*this)[i]) - dt[i];
    }
    return result2;
}
//gán
Dathuc &Dathuc::operator =(const Dathuc &dt){
    if(this!= &dt){
        delete [] data;
        n = dt.n;
        data = new double[n+1];
        for(int i=0; i<=n;i++){
            data[i] = dt.data[i];
        }
    }
    return *this;
}
//dùng để truy xuất hệ số thập phân
double &Dathuc::operator [] (int index){
    return data[index];
}
//truy xuất hệ số nguyên
const double &Dathuc::operator [](int index)const{
    return data[index];
}
// tính giá trị của đa thức
double Dathuc::operator ()(double x)const{
    double result3 = 0.0;
    for (int i=n;i>=0;i--){
        result3 = result3 * x + data[i];
    }
    return result3;
}
//nhập
istream &operator >>(istream &in, Dathuc &dathuc){
    for(int i=dathuc.n;i>=0;i--){
        cout <<"   Nhập hệ số bậc "<<i<<":";
        in>>dathuc[i];
    }
    return in;
}
//xuất
ostream &operator <<(ostream &out, Dathuc &dathuc){
    for(int i=dathuc.n;i>=0;i--){
        out<<dathuc[i]<<"*x^"<<i;
        if(i>0){
            out << " + ";
        }
    }
    return out;
}

