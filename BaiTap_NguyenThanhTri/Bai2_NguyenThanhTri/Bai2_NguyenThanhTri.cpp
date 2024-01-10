// Bài 2: 
// Cài đặt lớp Dathuc để biểu diễn 01 đa thức gồm bậc n và 01 mảng động 
// chứa hệ số của đa thức; các hàm dựng, hàm dựng sao chép, hàm hủy; hàm 
// toán tử +, - 2 đa thức; hàm toán tử [ ] để truy xuất 01 hệ số của đa 
// thức; toán tử ( ) để tinh giá trị của đa thức; toán tử = để gán 2 đa 
// thức; toán tử >>, << để nhập, xuất 2 đa thức.
#include "Dathuc.h"
#include "Dathuc.cpp"
#include <iostream>
using namespace std;
int main(){
    //khai báo
    int bac;
    cout <<"Nhập bậc của đa thức:";
    cin >> bac;
    Dathuc a(bac), b(bac);
    //nhập và xuất
    cout<<"Nhập đa thức a:"<<endl;
    cin >> a;
    cout<< endl<<"Nhập đa thức b:"<<endl;
    cin >> b;
    cout <<endl<<"Đa thức a:"<<endl<< a << endl<< endl <<"Đa thức b:"<<endl<< b << endl << endl;
    Dathuc s = a + b;
    Dathuc d = a - b;
    //tổng và hiêuj
    cout<<"Tổng a+b ="<< s << endl<<endl;
    cout<<"Hiệu a-b ="<< d << endl<<endl;
    double x;
    cout << "Nhập giá trị x tính a(x) và b(x):"<<endl;
    cin >> x;
    cout <<endl<< "a("<<x<<")="<<a(x)<<endl;
    cout <<endl<< "b("<<x<<")="<<b(x)<<endl<<endl;
    //truy xuất bậc của đa thức
    for(int i=bac;i>=0;i--){
        cout << "Hệ số bậc" << i <<" của a:"<< a[i]<<endl;
    }
    cout<<endl;
    for(int i=bac;i>=0;i--){
        cout << "Hệ số bậc" << i <<" của b:"<< b[i]<<endl;
    }
}