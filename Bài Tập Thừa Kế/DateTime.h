#ifndef DateTime_h
#define DateTime_h
#include "Date.cpp"
#include "Time.cpp"
#include <iostream>
using namespace std;
class DateTime:public Date, public Time{
    public:
        DateTime(int day, int month, int year, int hour, int minute, int second);
        DateTime(const DateTime &other);
        ~DateTime();
        //Toán tử logic
        DateTime &operator ++();
        DateTime operator++(int);
        DateTime &operator --();
        DateTime operator--(int);
        friend istream &operator >> (istream &in, DateTime &dt);
        friend ostream &operator << (ostream &out,const DateTime &dt);
};
#endif