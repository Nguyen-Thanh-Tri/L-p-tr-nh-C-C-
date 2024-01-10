#ifndef Dathuc_h
#define Dathuc_h
#include <iostream>
using namespace std;
class Dathuc{
    private:
        int n;  //Bậc
        double *data;// mảng động
    public:
        Dathuc(int bac);//Hàm dựng
        Dathuc(const Dathuc &v);// Hàm dựng sao chép
       ~Dathuc();//Ham huỷ
        Dathuc operator +(const Dathuc &dt)const;
        Dathuc operator -(const Dathuc &dt)const;
        Dathuc &operator =(const Dathuc &dt);
        double &operator [](int index);
        const double &operator [](int index)const;
        double operator ()(double x)const;
        friend istream &operator >> (istream &in, Dathuc &dt);
        friend ostream &operator << (ostream &out, Dathuc &dt);

};
#endif