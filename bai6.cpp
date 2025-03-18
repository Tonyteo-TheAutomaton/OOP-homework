#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm số lần xuất hiện của A trong B và trả về danh sách vị trí bắt đầu
vector<int> timViTriXuatHien(const vector<int>& A, const vector<int>& B) {
    vector<int> viTriBatDau; // Lưu danh sách vị trí bắt đầu của A trong B
    int n = B.size(), m = A.size();

    // Duyệt qua mảng B để tìm vị trí A xuất hiện
    for (int i = 0; i <= n - m; i++) { 
        bool trungKhop = true;
        for (int j = 0; j < m; j++) {
            if (B[i + j] != A[j]) { 
                trungKhop = false;
                break;
            }
        }
        if (trungKhop) viTriBatDau.push_back(i); // Lưu vị trí nếu tìm thấy A trong B
    }
    
    return viTriBatDau; 
}

int main() {
    int m, n;
    cout << "Nhập số phần tử của mảng A và B: ";
    cin >> m >> n; // Nhập số phần tử của A và B

    vector<int> A(m), B(n);
    
    cout << "Nhập các phần tử của mảng A: ";
    for (int i = 0; i < m; i++) cin >> A[i]; // Nhập mảng A
    
    cout << "Nhập các phần tử của mảng B: ";
    for (int i = 0; i < n; i++) cin >> B[i]; // Nhập mảng B

    vector<int> viTri = timViTriXuatHien(A, B);
    
    // Xuất kết quả
    cout << "Số lần mảng A xuất hiện trong B: " << viTri.size() << endl;  
    cout << "Các vị trí bắt đầu: ";
    for (int viTriBatDau : viTri) cout << viTriBatDau << " ";  
    cout << endl;

    return 0;
}
