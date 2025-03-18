#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <iomanip>
using namespace std;

struct Flight {
    string name;
    string dates;
    string time;
    string from;
    string to;
};

// Kiểm tra định dạng tên chuyến bay
bool isValidName(const string &name) {
    return regex_match(name, regex("^[A-Za-z0-9]{1,5}$"));
}

// Kiểm tra định dạng ngày bay (yyyy-mm-dd)
bool isValidDates(const string &dates) {
    return regex_match(dates, regex("^\\d{4}-\\d{2}-\\d{2}$"));
}

// Kiểm tra định dạng giờ bay (HH:MM)
bool isValidTime(const string &time) {
    return regex_match(time, regex("^([01]\\d|2[0-3]):[0-5]\\d$"));
}

// Kiểm tra định dạng nơi đi/nơi đến
bool isValidLocation(const string &location) {
    return regex_match(location, regex("^[A-Za-z ]{1,20}$"));
}

// Hàm nhập thông tin chuyến bay
Flight inputFlight() {
    Flight flight;
    
    do {
        cout << "Nhap ten chuyen bay: ";
        cin >> flight.name;
    } while (!isValidName(flight.name));

    do {
        cout << "Nhap ngay bay (yyyy-mm-dd): ";
        cin >> flight.dates;
    } while (!isValidDates(flight.dates));

    do {
        cout << "Nhap gio bay (HH:MM): ";
        cin >> flight.time;
    } while (!isValidTime(flight.time));

    cin.ignore(); // Xóa bộ nhớ đệm
    do {
        cout << "Nhap noi di: ";
        getline(cin, flight.from);
    } while (!isValidLocation(flight.from));

    do {
        cout << "Nhap noi den: ";
        getline(cin, flight.to);
    } while (!isValidLocation(flight.to));

    return flight;
}

// Xuất thông tin chuyến bay
void displayFlight(const Flight &flight) {
    cout << left << setw(10) << flight.name << setw(15) << flight.dates
         << setw(10) << flight.time << setw(15) << flight.from
         << setw(15) << flight.to << endl;
}

// Tìm kiếm chuyến bay
void searchFlight(const vector<Flight> &flights, const string &key) {
    bool found = false;
    for (const auto &flight : flights) {
        if (flight.name == key || flight.from == key || flight.to == key) {
            displayFlight(flight);
            found = true;
        }
    }
    if (!found) cout << "===== Khong tim thay chuyen bay =====" << endl;
}

// Sắp xếp chuyến bay theo ngày và giờ
void sortFlights(vector<Flight> &flights) {
    sort(flights.begin(), flights.end(), [](const Flight &a, const Flight &b) {
        return a.dates == b.dates ? a.time < b.time : a.dates < b.dates;
    });
}

// Liệt kê chuyến bay theo nơi đi và ngày
void listFlightsByDate(const vector<Flight> &flights, const string &location, const string &date) {
    bool found = false;
    for (const auto &flight : flights) {
        if (flight.from == location && flight.dates == date) {
            displayFlight(flight);
            found = true;
        }
    }
    if (!found) cout << "===== Khong co chuyen bay nao phu hop =====" << endl;
}

// Đếm số chuyến bay giữa hai địa điểm
int countFlights(const vector<Flight> &flights, const string &from, const string &to) {
    return count_if(flights.begin(), flights.end(), [&](const Flight &flight) {
        return flight.from == from && flight.to == to;
    });
}

int main() {
    vector<Flight> flights;
    int n;
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        flights.push_back(inputFlight());
    }

    sortFlights(flights);

    cout << "\nDanh sach chuyen bay sau khi sap xep:\n";
    for (const auto &flight : flights) {
        displayFlight(flight);
    }

    string searchKey;
    cout << "\nNhap ten chuyen bay hoac noi di/noi den can tim: ";
    cin >> searchKey;
    searchFlight(flights, searchKey);

    string location, date;
    cout << "\nNhap noi di va ngay bay de liet ke (yyyy-mm-dd): ";
    cin >> location >> date;
    listFlightsByDate(flights, location, date);

    string from, to;
    cout << "\nNhap noi di va noi den de dem so luong chuyen bay: ";
    cin >> from >> to;
    cout << "So luong chuyen bay: " << countFlights(flights, from, to) << endl;

    return 0;
}
