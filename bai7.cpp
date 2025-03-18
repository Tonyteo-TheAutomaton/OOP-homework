#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Cấu trúc lưu thông tin học sinh
struct HocSinh {
    string hoTen;
    double diemToan, diemVan, diemAnh, diemTrungBinh;
    string xepLoai;
};

// Hàm kiểm tra họ tên hợp lệ (không chứa số)
bool kiemTraHoTen(const string& ten) {
    for (char c : ten) {
        if (isdigit(c)) return false;
    }
    return !ten.empty();
}

// Hàm kiểm tra điểm hợp lệ (từ 0 đến 10)
double nhapDiem(const string& mon) {
    double diem;
    while (true) {
        cout << "Nhập điểm " << mon << ": ";
        cin >> diem;
        if (cin.fail() || diem < 0 || diem > 10) {
            cout << "Điểm không hợp lệ! Vui lòng nhập lại.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    return diem;
}

// Hàm tính điểm trung bình và phân loại học sinh
void tinhDiemVaXepLoai(HocSinh &hs) {
    hs.diemTrungBinh = (2 * hs.diemToan + hs.diemVan + hs.diemAnh) / 4.0;

    if (hs.diemTrungBinh >= 9) hs.xepLoai = "Xuất sắc";
    else if (hs.diemTrungBinh >= 8) hs.xepLoai = "Giỏi";
    else if (hs.diemTrungBinh >= 6.5) hs.xepLoai = "Khá";
    else if (hs.diemTrungBinh >= 5) hs.xepLoai = "Trung bình";
    else hs.xepLoai = "Yếu";
}

// Hàm nhập danh sách học sinh
void nhapDanhSachHocSinh(vector<HocSinh>& danhSach, int n) {
    for (int i = 0; i < n; i++) {
        HocSinh hs;
        cin.ignore();  // Xóa bộ đệm trước khi nhập họ tên
        do {
            cout << "Nhập họ tên học sinh " << i + 1 << ": ";
            getline(cin, hs.hoTen);
            if (!kiemTraHoTen(hs.hoTen)) {
                cout << "Tên không hợp lệ! Vui lòng nhập lại.\n";
            }
        } while (!kiemTraHoTen(hs.hoTen));

        hs.diemToan = nhapDiem("Toán");
        hs.diemVan = nhapDiem("Văn");
        hs.diemAnh = nhapDiem("Ngoại ngữ");

        tinhDiemVaXepLoai(hs);
        danhSach.push_back(hs);
    }
}

// Hàm hiển thị danh sách học sinh
void hienThiDanhSach(const vector<HocSinh>& danhSach) {
    cout << "\nDanh sách học sinh:\n";
    for (const auto& hs : danhSach) {
        cout << "Họ tên: " << hs.hoTen
             << ", Điểm TB: " << hs.diemTrungBinh
             << ", Xếp loại: " << hs.xepLoai << endl;
    }
}

// Hàm tìm học sinh có điểm trung bình cao nhất
void timHocSinhDiemCaoNhat(const vector<HocSinh>& danhSach) {
    double maxDiem = -1;
    for (const auto& hs : danhSach) {
        if (hs.diemTrungBinh > maxDiem) {
            maxDiem = hs.diemTrungBinh;
        }
    }

    cout << "\nHọc sinh có điểm trung bình cao nhất:\n";
    for (const auto& hs : danhSach) {
        if (hs.diemTrungBinh == maxDiem) {
            cout << "Họ tên: " << hs.hoTen << ", Điểm TB: " << hs.diemTrungBinh << endl;
        }
    }
}

// Hàm tìm kiếm học sinh theo tên
void timKiemHocSinh(const vector<HocSinh>& danhSach, const string& keyword) {
    cout << "\nKết quả tìm kiếm học sinh có từ khóa '" << keyword << "':\n";
    bool found = false;
    for (const auto& hs : danhSach) {
        if (hs.hoTen.find(keyword) != string::npos) {
            cout << "Họ tên: " << hs.hoTen << ", Điểm TB: " << hs.diemTrungBinh << endl;
            found = true;
        }
    }
    if (!found) cout << "Không tìm thấy học sinh nào!\n";
}

// Hàm tìm danh sách học sinh có điểm Toán thấp nhất
void timHocSinhDiemToanThapNhat(const vector<HocSinh>& danhSach) {
    double minDiem = 10;
    for (const auto& hs : danhSach) {
        if (hs.diemToan < minDiem) {
            minDiem = hs.diemToan;
        }
    }

    cout << "\nHọc sinh có điểm Toán thấp nhất:\n";
    for (const auto& hs : danhSach) {
        if (hs.diemToan == minDiem) {
            cout << "Họ tên: " << hs.hoTen << ", Điểm Toán: " << hs.diemToan << endl;
        }
    }
}

int main() {
    int n;
    cout << "Nhập số lượng học sinh: ";
    cin >> n;

    vector<HocSinh> danhSach;
    nhapDanhSachHocSinh(danhSach, n);
    
    hienThiDanhSach(danhSach);
    timHocSinhDiemCaoNhat(danhSach);
    
    string tenTimKiem;
    cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi tìm kiếm
    cout << "\nNhập tên cần tìm: ";
    getline(cin, tenTimKiem);
    timKiemHocSinh(danhSach, tenTimKiem);
    
    timHocSinhDiemToanThapNhat(danhSach);

    return 0;
}
