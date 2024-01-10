#include <iostream>
#include <vector>
#include <algorithm>

struct SINHVIEN {
    static int nextId;
    int id;
    std::string hoTen;
    char gioiTinh;
    int tuoi;
    float diemToan, diemLy, diemHoa;
    float diemTrungBinh;
    std::string hocLuc;

    SINHVIEN() {
        id = nextId++;
    }

    void tinhDiemTrungBinh() {
        diemTrungBinh = (diemToan + diemLy + diemHoa) / 3;
        if (diemTrungBinh >= 8.0) hocLuc = "Giỏi";
        else if (diemTrungBinh >= 6.5) hocLuc = "Khá";
        else if (diemTrungBinh >= 5.0) hocLuc = "Trung Bình";
        else hocLuc = "Yếu";
    }

    friend std::ostream& operator<<(std::ostream& os, const SINHVIEN& sv) {
        os << "ID: " << sv.id << ", Họ tên: " << sv.hoTen << ", Giới tính: " << sv.gioiTinh
           << ", Tuổi: " << sv.tuoi << ", Điểm TB: " << sv.diemTrungBinh << ", Học lực: " << sv.hocLuc;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SINHVIEN& sv) {
        std::cout << "Nhập thông tin sinh viên:" << std::endl;
        std::cout << "Họ tên: ";
        std::getline(is, sv.hoTen);
        std::cout << "Giới tính: ";
        is >> sv.gioiTinh;
        std::cout << "Tuổi: ";
        is >> sv.tuoi;
        std::cout << "Điểm Toán: ";
        is >> sv.diemToan;
        std::cout << "Điểm Lý: ";
        is >> sv.diemLy;
        std::cout << "Điểm Hóa: ";
        is >> sv.diemHoa;

        sv.tinhDiemTrungBinh();

        return is;
    }

    bool operator==(const SINHVIEN& other) const {
        return id == other.id;
    }

    bool operator<(const SINHVIEN& other) const {
        return diemTrungBinh < other.diemTrungBinh;
    }

    bool operator>(const SINHVIEN& other) const {
        return diemTrungBinh > other.diemTrungBinh;
    }
};

int SINHVIEN::nextId = 1;

class LIST {
private:
    std::vector<SINHVIEN> danhSach;

public:
    void operator+(const SINHVIEN& sv) {
        auto it = std::find(danhSach.begin(), danhSach.end(), sv);
        if (it == danhSach.end()) {
            danhSach.push_back(sv);
            std::cout << "Thêm sinh viên thành công." << std::endl;
        } else {
            std::cout << "Sinh viên đã tồn tại trong danh sách." << std::endl;
        }
    }

    void operator-(int id) {
        auto it = std::find_if(danhSach.begin(), danhSach.end(), [id](const SINHVIEN& sv) {
            return sv.id == id;
        });

        if (it != danhSach.end()) {
            danhSach.erase(it);
            std::cout << "Xoá sinh viên thành công." << std::endl;
        } else {
            std::cout << "Không tìm thấy sinh viên có ID " << id << "." << std::endl;
        }
    }

    SINHVIEN operator()(int id) {
        auto it = std::find_if(danhSach.begin(), danhSach.end(), [id](const SINHVIEN& sv) {
            return sv.id == id;
        });

        if (it != danhSach.end()) {
            return *it;
        } else {
            std::cerr << "Không tìm thấy sinh viên có ID " << id << "." << std::endl;
            return SINHVIEN(); // Trả về SINHVIEN mặc định nếu không tìm thấy
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LIST& list) {
        for (const auto& sv : list.danhSach) {
            os << sv << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, LIST& list) {
        int n;
        std::cout << "Nhập số lượng sinh viên: ";
        is >> n;
        is.ignore(); // Đọc bỏ ký tự '\n' sau khi nhập số lượng

        for (int i = 0; i < n; ++i) {
            SINHVIEN sv;
            is >> sv;
            list + sv; // Sử dụng toán tử + để thêm sinh viên vào danh sách
        }

        return is;
    }

    void sapXep(bool tang) {
        if (tang) {
            std::sort(danhSach.begin(), danhSach.end());
        } else {
            std::sort(danhSach.begin(), danhSach.end(), std::greater<SINHVIEN>());
        }
    }
};

int main() {
    LIST danhSachSinhVien;

    std::cout << "Nhập danh sách sinh viên:" << std::endl;
    std::cin >> danhSachSinhVien;

    danhSachSinhVien.sapXep(true); // Sắp xếp tăng dần theo điểm trung bình
    std::cout << "Danh sách sinh viên sau khi sắp xếp tăng dần:" << std::endl;
    std::cout << danhSachSinhVien << std::endl;

    danhSachSinhVien.sapXep(false); // Sắp xếp giảm dần theo điểm trung bình
    std::cout << "Danh sách sinh viên sau khi sắp xếp giảm dần:" << std::endl;
    std::cout << danhSachSinhVien << std::endl;

    int idTimKiem;
    std::cout << "Nhập ID sinh viên cần tìm: ";
    std::cin >> idTimKiem;

    SINHVIEN svTimKiem = danhSachSinhVien(idTimKiem);
    std::cout << "Thông tin sinh viên có ID " << idTimKiem << ": " << svTimKiem << std::endl;

    return 0;
}
