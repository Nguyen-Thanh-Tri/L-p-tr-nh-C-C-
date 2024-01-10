// 1.Xem trước về nội dung hàm dựng conctructor, hàm hủy destructor, 
//     hàm dựng sao chép (copy constructor)
// 2.Cài đặt lớp Stack để biểu diễn 01 ngăn xếp (dùng mảng động) và định nghĩa 
//  các hàm dựng, hàm hủy, dựng sao chép, hàm thêm 01 phần tử vào Stack, hàm 
//  ấy 01 phần tử ra khỏi Stack, hàm kiểm tra Stack đầy, hàm kiểm tra Stack 
//   rỗng. Viết chương trình ứng dụng lớp Stack đổi 01 số nguyên bất kỳ 
//   (nhập từ bàn phím) từ hệ thập phân qua hệ thập lục phân.
#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data; // Dùng mảng động để lưu trữ phần tử của Stack
    int maxSize; // Kích thước tối đa của Stack

public:
    // Hàm dựng (constructor)
    Stack(int size) : maxSize(size) {
        data.reserve(maxSize);
    }

    // Hàm hủy (destructor)
    ~Stack() {
        data.clear();
    }

    // Hàm dựng sao chép (copy constructor)
    Stack(const Stack& other) {
        maxSize = other.maxSize;
        data = other.data;
    }

    // Hàm kiểm tra Stack rỗng
    bool isEmpty() const {
        return data.empty();
    }

    // Hàm kiểm tra Stack đầy
    bool isFull() const {
        return data.size() >= maxSize;
    }

    // Hàm thêm 1 phần tử vào Stack
    void push(int value) {
        if (!isFull()) {
            data.push_back(value);
        } else {
            cout << "Stack is full. Cannot push more elements." << endl;
        }
    }

    // Hàm lấy 1 phần tử ra khỏi Stack
    int pop() {
        if (!isEmpty()) {
            int top = data.back();
            data.pop_back();
            return top;
        } else {
            cout << "Stack is empty. Cannot pop an element." << endl;
            return -1; // Trả về một giá trị mặc định (có thể thay đổi)
        }
    }
};

int main() {
    int decimalNumber;
    cout << "Nhập số nguyên từ hệ thập phân: ";
    cin >> decimalNumber;

    Stack stack(100); // Khởi tạo một Stack với kích thước tối đa 100

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 16;
        stack.push(remainder);
        decimalNumber /= 16;
    }

    cout << "Số sau khi chuyển sang hệ thập lục phân: ";
    while (!stack.isEmpty()) {
        int digit = stack.pop();
        if (digit < 10) {
            cout << digit;
        } else {
            char hexDigit = 'A' + digit - 10;
            cout << hexDigit;
        }
    }

    cout << endl;

    return 0;
}
