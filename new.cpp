#include <iostream>
using namespace std;
struct Sinhvien {
    char name[30];
    double t,l,h,tb;
};
istream &operator >>(istream &in, Sinhvien &v){
    cout<<"Nhâp họ và tên:"; in>>v.name;  //có sapce là bị lỗi
    cout<<"Nhâp điểm toán:"; in>>v.t;
    cout<<"Nhâp điểm lý:"; in>>v.l;
    cout<<"Nhâp điểm hoá:"; in>>v.h;
    return in;
}
ostream &operator <<(ostream &out, Sinhvien &v){
    v.tb=(v.t+v.l+v.h)/3;
    out<<v.name<<" / "<<v.t<<" / "<<v.l<<" / "<<v.h<<" / "<<v.tb<<endl;
    return out;
}
int main(){
    int n;
    cout<<"Số lượng sinh viên cần nhập"<<endl;
    cin>>n;
    Sinhvien dssv[n];
    for (int i=0;i<n;i++){
        cout<<"Nhập thông tin sinh viên thứ "<<i+1<<" :"<<endl;
        cin >> dssv[i];
    }
    for(int k=0;k<n;k++){ // sắp xếp tăng dần
        for(int l= k+1; l<n; l++){
            if (dssv[k].tb > dssv[l].tb) {
                Sinhvien temp = dssv[k]; dssv[k] = dssv[l]; dssv[l] = temp;
            }}}
    for (int j=0; j<n;j++){
        cout<<j+1<<dssv[j];
    }
}
