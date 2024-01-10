// Cài đặt lớp DateTime thừa kế từ Date và Time, định nghĩa các hàm dựng, hàm toán tử nhập xuất, 
// tăng, giảm 01 đơn vị thời gian.
#include <iostream>
#include "DateTime.h"
using namespace std;
DateTime::DateTime(int day, int month, int year, int hour, int minute, int second):Date(day, month, year), Time(hour, minute, second){}
DateTime::DateTime(const DateTime&other):Date(other), Time(other){}
DateTime::~DateTime(){
}
DateTime& DateTime::operator++() {
    // Tăng giây
    Time::operator ++();
    // Kiểm tra xem có cần tăng ngày không
    if (Time::getSecond() == 0 && Time::getMinute() == 0 && Time::getHour() == 0) {
        Date::operator++();  // Tăng ngày
    }
    return *this;
}
DateTime DateTime::operator++(int) {
    DateTime temp(*this);
    ++(*this);
    return temp;
}
DateTime& DateTime::operator --() {
    // Giảm giây
    Time::operator--();

    // Kiểm tra xem có cần giảm ngày không
    if (Time::getSecond() == 59 && Time::getMinute() == 59 && Time::getHour() == 23) {
        Date::operator--();  // Giảm ngày
    }

    return *this;
}
DateTime DateTime::operator--(int) {
    DateTime temp(*this);
    --(*this);
    return temp;
}
istream &operator >> (istream &in, DateTime &dt){
    in >> static_cast<Date&>(dt) >> static_cast<Time&>(dt);
    return in;
}
ostream &operator << (ostream &out,const DateTime &dt){
    out << static_cast<const Date&>(dt) << " " << static_cast<const Time&>(dt);
    return out;
}
