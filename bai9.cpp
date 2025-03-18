#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>
#include <ctime>

using namespace std;

struct SoTietKiem {
    string maSo;
    string loaiTietKiem;
    string hoTen;
    string cmnd;
    int ngay, thang, nam;
    double soTienGui;
};

// Kiểm tra dữ liệu nhập vào
bool kiemTraMaSo(const string& ma) { return regex_match(ma, regex("^[A-Za-z0-9]{1,5}$")); }
bool kiemTraHoTen(const string& ten) { return regex_match(ten, regex("^[A-Za-z ]{1,30}$")); }
bool kiemTraCMND(const string& cmnd) { return regex_match(cmnd, regex("^\\d{9}$|^\\d{12}$")); }
bool laNamNhuan(int nam) { return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0); }

bool kiemTraNgay(int ngay, int thang, int nam) {
    int ngayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (thang < 1 || thang > 12) return false;
    if (laNamNhuan(nam)) ngayTrongThang[1] = 29;
    return ngay > 0 && ngay <= ngayTrongThang[thang - 1];
}

// Nhập dữ liệu
void nhapSoTietKiem(SoTietKiem &stk) {
    do {
        cout << "Nhap ma so: "; cin >> stk.maSo;
    } while (!kiemTraMaSo(stk.maSo));
    
    cin.ignore();
    do {
        cout << "Nhap loai tiet kiem: "; getline(cin, stk.loaiTietKiem);
    } while (stk.loaiTietKiem.empty() || stk.loaiTietKiem.length() > 10);

    do {
        cout << "Nhap ho ten: "; getline(cin, stk.hoTen);
    } while (!kiemTraHoTen(stk.hoTen));

    do {
        cout << "Nhap CMND: "; cin >> stk.cmnd;
    } while (!kiemTraCMND(stk.cmnd));

    do {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> stk.ngay >> stk.thang >> stk.nam;
    } while (!kiemTraNgay(stk.ngay, stk.thang, stk.nam));

    do {
        cout << "Nhap so tien gui (>0): "; cin >> stk.soTienGui;
    } while (stk.soTienGui <= 0);
}

void xuatSoTietKiem(const SoTietKiem &stk) {
    cout << fixed << setprecision(0);
    cout << "\nMa so: " << stk.maSo
         << "\nLoai tiet kiem: " << stk.loaiTietKiem
         << "\nHo ten: " << stk.hoTen
         << "\nCMND: " << stk.cmnd
         << "\nNgay mo so: " << stk.ngay << "/" << stk.thang << "/" << stk.nam
         << "\nSo tien gui: " << stk.soTienGui << " VND\n";
}

// Tìm kiếm sổ tiết kiệm theo CMND hoặc mã sổ
void timKiemSoTietKiem(const vector<SoTietKiem>& ds, const string& key) {
    for (const auto& stk : ds) {
        if (stk.cmnd == key || stk.maSo == key) {
            xuatSoTietKiem(stk);
            return;
        }
    }
    cout << "Khong tim thay so tiet kiem!\n";
}

// Liệt kê các sổ tiết kiệm mở trong một khoảng thời gian
void lietKeSoTheoThoiGian(const vector<SoTietKiem>& ds, int tuNam, int denNam) {
    for (const auto& stk : ds) {
        if (stk.nam >= tuNam && stk.nam <= denNam) {
            xuatSoTietKiem(stk);
        }
    }
}

// Sắp xếp danh sách
bool cmpSoTien(const SoTietKiem &a, const SoTietKiem &b) { return a.soTienGui > b.soTienGui; }
bool cmpNgayMoSo(const SoTietKiem &a, const SoTietKiem &b) {
    if (a.nam != b.nam) return a.nam < b.nam;
    if (a.thang != b.thang) return a.thang < b.thang;
    return a.ngay < b.ngay;
}

int main() {
    vector<SoTietKiem> ds;
    int n, choice;
    
    cout << "Nhap so luong so tiet kiem: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        SoTietKiem stk;
        cout << "\nNhap thong tin so tiet kiem thu " << i + 1 << ":\n";
        nhapSoTietKiem(stk);
        ds.push_back(stk);
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Xem danh sach so tiet kiem\n";
        cout << "2. Tim kiem theo CMND hoac ma so\n";
        cout << "3. Liet ke theo khoang thoi gian\n";
        cout << "4. Sap xep theo so tien giam dan\n";
        cout << "5. Sap xep theo ngay mo so tang dan\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                for (const auto& stk : ds) xuatSoTietKiem(stk);
                break;
            case 2: {
                string key;
                cout << "Nhap CMND hoac ma so: ";
                getline(cin, key);
                timKiemSoTietKiem(ds, key);
                break;
            }
            case 3: {
                int tuNam, denNam;
                cout << "Nhap khoang nam (tu - den): ";
                cin >> tuNam >> denNam;
                lietKeSoTheoThoiGian(ds, tuNam, denNam);
                break;
            }
            case 4:
                sort(ds.begin(), ds.end(), cmpSoTien);
                cout << "\nDanh sach da sap xep theo so tien giam dan:\n";
                for (const auto& stk : ds) xuatSoTietKiem(stk);
                break;
            case 5:
                sort(ds.begin(), ds.end(), cmpNgayMoSo);
                cout << "\nDanh sach da sap xep theo ngay mo so tang dan:\n";
                for (const auto& stk : ds) xuatSoTietKiem(stk);
                break;
        }
    } while (choice != 0);
    return 0;
}
