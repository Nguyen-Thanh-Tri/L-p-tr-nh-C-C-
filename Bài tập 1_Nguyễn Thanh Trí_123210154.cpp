#include <iostream>
using namespace std;
int ngaytrongthang(int thang, int nam);

struct Date{
    int ngay, thang, nam;
};
//Nhập
istream &operator >> (istream &in, Date &spec){
    cout << "Nhập ngày:";in >> spec.ngay;
    cout << "Nhập tháng:";in >> spec.thang;
    cout << "Nhập năm:";in >> spec.nam;
    return in;
}
//Xuất
ostream &operator << (ostream &out, const Date &spec){
    out <<"("<<spec.ngay<<"/"<<spec.thang<<"/"<<spec.nam<<")";
    return out;
}
int ngaytrongthang(int thang, int nam){
    if (thang == 2){
        if((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)){
            return 29;
        } else{
            return 28;
    }
    } else if (thang == 4 || thang == 6 || thang == 9 || thang == 11){
        return 30;
    }else {
        return 31;
    }
}
//Tăng ngày
Date &operator ++ (Date &spec ) {
    if (spec.ngay < ngaytrongthang(spec.thang, spec.nam)){
        spec.ngay++;
    } else {
        spec.ngay = 1 ;
        if (spec.thang < 12){
            spec.thang++;
        } else {
            spec.thang =1;
            spec.nam++;
        }
    }
    return spec;
}
Date &operator -- (Date &spec ) {
    if (spec.ngay > 1 ){
        spec.ngay--;
    } else {
        if (spec.thang > 1){
            spec.thang--;
            spec.ngay =  ngaytrongthang(spec.thang, spec.nam);
        } else {
            spec.thang =12;
            spec.nam--;
            spec.ngay = 31;

        }
    }
    return spec;
}
int main() {
    Date myDate;
    cin >> myDate;
    cout << "ngày cần tăng: " << myDate << endl;
    ++myDate;
    cout << "Ngày sau khi tăng: " << myDate << endl;
    cin >> myDate;
    cout << "ngày cần giảm: " << myDate << endl;
    --myDate;
    cout << "Ngày sau khi giảm: " << myDate << endl;
    return 0;
}

