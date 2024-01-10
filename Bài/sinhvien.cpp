#include <iostream>
#include "sinhvien.h"
#include "bt.cpp"
using namespace std;
LIST::LIST() : head(nullptr){}
LIST::~LIST(){
    while (head){
        SINHVIEN *temp = head;
        head = head->next;
        delete temp;
    }
}

