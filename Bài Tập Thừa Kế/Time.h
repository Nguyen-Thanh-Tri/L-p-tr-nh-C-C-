#ifndef Time_h
#define Time_h
#include <iostream>
using namespace std;
class Time{
    private:
        int hour, minute, second;
    public:
        Time(int hour, int minute, int second);
        Time(const Time &t);
        ~Time();
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        //Toán tử logic
        Time &operator ++();
        Time operator++(int);
        Time &operator --();
        Time operator--(int);
        friend istream &operator >> (istream &in, Time &t);
        friend ostream &operator << (ostream &out,const Time &t);
};
#endif