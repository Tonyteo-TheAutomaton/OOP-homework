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

// Hàm rút gọn phân số
void simplifyFraction(int &num, int &den) {
    int divisor = gcd(num, den);
    num /= divisor;
    den /= divisor;
}

// Hàm tính tổng hai phân số
void addFractions(int num1, int den1, int num2, int den2, int &numRes, int &denRes) {
    numRes = num1 * den2 + num2 * den1;
    denRes = den1 * den2;
    simplifyFraction(numRes, denRes);
}

// Hàm tính hiệu hai phân số
void subtractFractions(int num1, int den1, int num2, int den2, int &numRes, int &denRes) {
    numRes = num1 * den2 - num2 * den1;
    denRes = den1 * den2;
    simplifyFraction(numRes, denRes);
}

// Hàm tính tích hai phân số
void multiplyFractions(int num1, int den1, int num2, int den2, int &numRes, int &denRes) {
    numRes = num1 * num2;
    denRes = den1 * den2;
    simplifyFraction(numRes, denRes);
}

// Hàm tính thương hai phân số
void divideFractions(int num1, int den1, int num2, int den2, int &numRes, int &denRes) {
    numRes = num1 * den2;
    denRes = den1 * num2;
    simplifyFraction(numRes, denRes);
}

int main() {
    int num1, den1, num2, den2;
    
    cout << "Nhập phân số thứ nhất:\n";
    inputFraction(num1, den1);
    
    cout << "Nhập phân số thứ hai:\n";
    inputFraction(num2, den2);
    
    int numRes, denRes;
    
    // Tính tổng
    addFractions(num1, den1, num2, den2, numRes, denRes);
    cout << "Tổng: " << numRes << "/" << denRes << endl;
    
    // Tính hiệu
    subtractFractions(num1, den1, num2, den2, numRes, denRes);
    cout << "Hiệu: " << numRes << "/" << denRes << endl;
    
    // Tính tích
    multiplyFractions(num1, den1, num2, den2, numRes, denRes);
    cout << "Tích: " << numRes << "/" << denRes << endl;
    
    // Tính thương
    if (num2 != 0) {
        divideFractions(num1, den1, num2, den2, numRes, denRes);
        cout << "Thương: " << numRes << "/" << denRes << endl;
    } else {
        cout << "Không thể chia cho 0!" << endl;
    }
    
    return 0;
}
