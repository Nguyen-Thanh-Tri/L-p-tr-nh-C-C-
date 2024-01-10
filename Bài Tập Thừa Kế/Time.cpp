// Cài đặt lớp Time để biểu diễn giờ, phút, giây và các hàm dựng, hàm toán tử nhập xuất, 
// tăng, giảm 01 giây.
#include <iostream>
#include <iostream>
#include "Time.h"
using namespace std;
Time::Time(int hour, int minute, int second):hour(hour), minute(minute), second(second){}
Time::Time(const Time&t):hour(t.hour),minute(t.minute),second(t.second){}
Time::~Time(){
}
Time &Time::operator++() {
    second++;
    // Xử lý khi tăng giây
    if (second >= 60) {
        second = 0;
        minute++;
        // Xử lý khi tăng phút
        if (minute >= 60) {
            minute = 0;
            hour++;
            // Xử lý khi tăng giờ
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
    return *this;
}
Time Time::operator++(int) {
    Time temp(*this);
    ++(*this);
    return temp;
}
Time& Time::operator--() {
    second--;
    // Xử lý khi giảm giây
    if (second < 0) {
        second = 59;
        minute--;
        // Xử lý khi giảm phút
        if (minute < 0) {
            minute = 59;
            hour--;
            // Xử lý khi giảm giờ
            if (hour < 0) {
                hour = 23;
            }
        }
    }
    return *this;
}
Time Time::operator--(int) {
    Time temp(*this);
    --(*this);
    return temp;
}
 int Time::getHour() const {
        return hour;
    }

int Time::getMinute() const {
        return minute;
    }

int Time::getSecond() const {
        return second;
    }
istream &operator >> (istream &in, Time &t){
    in >> t.hour >> t.minute >> t.second;
    return in;
}
ostream & operator << ( ostream &out , const Time &t ){
    out << t.hour <<':'<< t.minute <<':'<< t.second;
    return out;
}