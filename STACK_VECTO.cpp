// // Cài đặt lớp Vecto trong không gian n chiều gồm n là số chiều, 
// và một mảng động chứa toạ độ của vecto.
// // Định nghĩa các hàm dựng, huỷ, dựng sao chép, hàm nhập, xuất vecto, 
// hàm tính tổng, hiệu, tích vô hướng của 2 vecto.
// // Viết chương trình minh hoạ.
#include <iostream>
#include <vector>
using namespace std;
class VectorND {
private:
    int n; // Số chiều của vecto
    vector<double> toado; // Mảng động chứa toạ độ của vecto

public:
    // Hàm dựng
    VectorND(int kichthuoc) {
        n = kichthuoc;
        toado.resize(n, 0.0);
    }

    // Hàm huỷ
    ~VectorND() {
        // Không cần gì cả, vector tự quản lý bộ nhớ
    }

    // Hàm dựng sao chép
    VectorND(const VectorND& other) {
        n = other.n;
        toado = other.toado;
    }

    // Hàm nhập vecto
    void input() {
        cout << "Nhập toạ độ cho vecto " << n << " chiều:" << endl;
        for (int i = 0; i < n; i++) {
            double coordinate;
            cin >> coordinate;
            toado[i] = coordinate;
        }
    }

    // Hàm xuất vecto
    void output() const {
        cout << "Vecto " << n << " chiều: ";
        for (int i = 0; i < n; i++) {
            cout << toado[i] << " ";
        }
        cout << endl;
    }

    // Hàm tính tổng hai vecto
    VectorND add(const VectorND& other) const {
        if (n != other.n) {
            cerr << "Không thể tính tổng hai vecto có số chiều khác nhau." << endl;
            return VectorND(0); // Trả về vecto rỗng
        }
        VectorND result(n);
        for (int i = 0; i < n; i++) {
            result.toado[i] = toado[i] + other.toado[i];
        }
        return result;
    }

    // Hàm tính hiệu hai vecto
    VectorND subtract(const VectorND& other) const {
        if (n != other.n) {
            cerr << "Không thể tính hiệu hai vecto có số chiều khác nhau." << endl;
            return VectorND(0); // Trả về vecto rỗng
        }
        VectorND result(n);
        for (int i = 0; i < n; i++) {
            result.toado[i] = toado[i] - other.toado[i];
        }
        return result;
    }

    // Hàm tính tích vô hướng hai vecto
    double dotProduct(const VectorND& other) const {
        if (n != other.n) {
            cerr << "Không thể tính tích vô hướng hai vecto có số chiều khác nhau." << endl;
            return 0; // Trả về 0
        }
        double result = 0;
        for (int i = 0; i < n; i++) {
            result += toado[i] * other.toado[i];
        }
        return result;
    }
};

int main() {
    int kichthuoc;
    cout << "Nhập số chiều của vecto: ";
    cin >> kichthuoc;

    VectorND vector1(kichthuoc);
    vector1.input();
    vector1.output();

    VectorND vector2(kichthuoc);
    vector2.input();
    vector2.output();

    VectorND sum = vector1.add(vector2);
    sum.output();

    VectorND difference = vector1.subtract(vector2);
    difference.output();

    double dot = vector1.dotProduct(vector2);
    cout << "Tích vô hướng của hai vecto: " << dot << endl;

    return 0;
}

