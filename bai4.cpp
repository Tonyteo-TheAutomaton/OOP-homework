#include <iostream>
#include <cmath>
using namespace std;

// Hàm tính giai thừa
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Hàm tính sin(x) theo chuỗi Taylor
double calculateSin(double x) {
    double term = x; // Phần tử đầu tiên x^1 / 1!
    double sum = term;
    int n = 1;
    
    while (fabs(term) > 0.00001) { // Độ chính xác 0.00001
        term *= -1 * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    
    return sum;
}

int main() {
    double x;
    cout << "Nhập giá trị x (radian): ";
    cin >> x;
    
    double result = calculateSin(x);
    cout << "Giá trị sin(" << x << ") = " << result << endl;
    
    return 0;
}
