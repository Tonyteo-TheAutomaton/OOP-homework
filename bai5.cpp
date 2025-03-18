#include <iostream>

using namespace std;

// Kiểm tra năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Số ngày trong mỗi tháng
int daysInMonth(int month, int year) {
    int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) return 29; // Tháng 2 năm nhuận có 29 ngày
    return daysInMonths[month - 1];
}

// Tìm ngày kế tiếp
void nextDay(int &day, int &month, int &year) {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// Tìm ngày trước đó
void previousDay(int &day, int &month, int &year) {
    day--;
    if (day == 0) {
        month--;
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
}

// Tính ngày thứ bao nhiêu trong năm
int dayOfYear(int day, int month, int year) {
    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += daysInMonth(i, year);
    }
    sum += day;
    return sum;
}

int main() {
    int day, month, year;

    // Nhập ngày, tháng, năm
    cout << "Nhập ngày: ";
    cin >> day;
    cout << "Nhập tháng: ";
    cin >> month;
    cout << "Nhập năm: ";
    cin >> year;

    // Tính ngày kế tiếp
    int next_d = day, next_m = month, next_y = year;
    nextDay(next_d, next_m, next_y);
    cout << "Ngày kế tiếp: " << next_d << "/" << next_m << "/" << next_y << endl;

    // Tính ngày trước đó
    int prev_d = day, prev_m = month, prev_y = year;
    previousDay(prev_d, prev_m, prev_y);
    cout << "Ngày trước đó: " << prev_d << "/" << prev_m << "/" << prev_y << endl;

    // Tính ngày thứ bao nhiêu trong năm
    cout << "Ngày thứ " << dayOfYear(day, month, year) << " trong năm " << year << endl;

    return 0;
}
