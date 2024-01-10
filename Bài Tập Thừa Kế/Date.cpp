// Cài đặt lớp Date để biểu diễn ngày tháng năm và các hàm dựng, hàm toán tử nhập xuất, 
// tăng, giảm 01 ngày.
#include "Date.h"
using namespace std;
Date::Date(int day, int month, int year):day(day), month(month), year(year){}
Date::Date(const Date&v):day(v.day), month(v.month), year(v.year){}
Date::~Date(){
}
int Date::dayinmonth(int month, int year){
    if (month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            return 29;
        } else{
            return 28;
    }
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }else {
        return 31;
    }
}
Date &Date::operator ++(){
    if (day < dayinmonth(month, year)){
        day++;
    } else {
        day = 1 ;
        if (month < 12){
            month++;
        } else {
            month =1;
            year++;
        }
    }
    return *this;
}
Date &Date::operator --(){
    if (day > 1 ){
        day--;
    } else {
        if (month > 1){
            month--;
            day =  dayinmonth(month, year);
        } else {
            month =12;
            year--;
            day = 31;

        }
    }
    return *this;
}
Date Date::operator++(int) {
    Date temp(*this);
    ++(*this);
    return temp;
}
Date Date::operator--(int) {
    Date temp(*this);
    --(*this);
    return temp;
}
istream &operator >> (istream &in, Date &d){
    in>> d.day>> d.month>> d.year;
    return in;
    }
ostream &operator << (ostream &out,const Date &d){
    out<< d.day<< "/"<< d.month<< "/"<< d.year;
    return out;
}