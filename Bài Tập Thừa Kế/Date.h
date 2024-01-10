#ifndef Date_h
#define Date_h
#include <iostream>
using namespace std;
class Date{
    private:
        int day, month, year;
        int dayinmonth(int month, int year);
    public:
        Date(int day, int month, int year);
        Date(const Date &v);
        ~Date();
        //Toán tử logic
        Date &operator ++();
        Date &operator --();
        Date operator++(int);
        Date operator--(int);
        friend istream &operator >> (istream &in, Date &d);
        friend ostream &operator << (ostream &out,const Date &d);
};
#endif