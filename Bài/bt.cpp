#include <iostream>
#include <algorithm>
using namespace std;
struct SINHVIEN {
    static int nextid;
    string name;
    char gtinh[10];
    string hocluc;
    double t, l, h, tb, tuoi;
    int id;
    SINHVIEN *next;
    SINHVIEN(){
        id = nextid++;
    }
void diemtrungbinh(){
    tb = (t + l + h) / 3;
        if (tb >= 8.0) hocluc = "Giỏi";
        else if (tb >= 6.5) hocluc = "Khá";
        else if (tb >= 5.0) hocluc = "Trung Bình";
        else hocluc = "Yếu";
}
friend istream &operator >>(istream &in, SINHVIEN &v){
    cout<<"Nhập thông tin sinh viên"<<endl;
    cout<<"Nhâp họ và tên: "; getline(in,v.name);
    cout<<"Giới tính: "; in>>v.gtinh;  
    cout<<"Tuổi: "; in>>v.tuoi; 
    cout<<"Nhâp điểm toán: "; in>>v.t;
    cout<<"Nhâp điểm lý: "; in>>v.l;
    cout<<"Nhâp điểm hoá: "; in>>v.h;
    v.diemtrungbinh();
    return in;
}
friend ostream &operator <<(ostream &out,SINHVIEN &v ){
    out <<"id: "<<v.id<<", Họ tên:"<<v.name<<", Giới tính:"<<v.gtinh<<", Tuổi:"<<v.tuoi<<", Diểm trung bình:"<<v.tb<<", Học lực:"<<v.hocluc<<endl;
    return out;
}
bool operator ==(const SINHVIEN &v)const{
    return id == v.id;
}
bool operator <(const SINHVIEN &v)const{
    return tb < v.tb;
}
bool operator >(const SINHVIEN &v)const{
    return tb > v.tb;
}
};
