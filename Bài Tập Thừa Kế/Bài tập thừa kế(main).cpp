#include <iostream>
#include "DateTime.h"
#include "DateTime.cpp"
using namespace std;
int main() {
    int day, month, year, hour, minute, second;

    // Nhập giá trị cho Date
    cout << "Nhập ngày, Tháng, Năm (e.g., 1 1 2023): "<<endl;
    cin >> day >> month >> year;

    // Nhập giá trị cho Time
    cout << "Nhập giờ, phút, giây (e.g., 12 30 45): "<<endl;
    cin >> hour >> minute >> second;
    // Khởi tạo đối tượng DateTime
    DateTime dt(day, month, year, hour, minute, second);

    cout << "Thời gian hiện tại: " << dt << endl;

    // Tăng theo đơn vị thời gian
    ++dt; // Tăng theo 1 đơn vị thời gian
    cout << "Sau khi tăng: " << dt << endl;

    dt++; // tăng 1 đơn vị thời gian, hậu tố
    cout << "Sau khi tăng hậu tố: " << dt << endl;

    --dt; // Giảm theo 1 đơn vị thời gian
    cout << "Sau khi giảm: " << dt << endl;

    dt--; // Giảm 1 đơn vị thời gian, hậu tố
    cout << "Sau khi giảm hậu tố: " << dt << endl;
    return 0;
}
