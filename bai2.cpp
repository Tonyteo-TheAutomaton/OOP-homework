#include <iostream>
using namespace std;

// Hàm tìm ước số chung lớn nhất (USCLN) để rút gọn phân số
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm nhập phân số
void inputFraction(int &num, int &den) {
    cout << "Nhập tử số: ";
    cin >> num;
    do {
        cout << "Nhập mẫu số (khác 0): ";
        cin >> den;
    } while (den == 0);
}

// Hàm so sánh hai phân số
void compareFractions(int num1, int den1, int num2, int den2) {
    int lhs = num1 * den2; // Quy đồng về mẫu chung
    int rhs = num2 * den1;
    
    cout << "Phân số lớn hơn là: ";
    if (lhs > rhs) {
        cout << num1 << "/" << den1 << endl;
    } else if (lhs < rhs) {
        cout << num2 << "/" << den2 << endl;
    } else {
        cout << "Hai phân số bằng nhau" << endl;
    }
}

int main() {
    int num1, den1, num2, den2;
    
    cout << "Nhập phân số thứ nhất:\n";
    inputFraction(num1, den1);
    
    cout << "Nhập phân số thứ hai:\n";
    inputFraction(num2, den2);
    
    compareFractions(num1, den1, num2, den2);
    
    return 0;
}
