/*
Viết hàm khuôn hình so sánh 2 số
Nhập vào 2 số, xuất true nếu 2 số bằng nhau, ngược lại xuất false
qui ước:
kiểu a là số nguyên
kiểu b là số thực
kiểu c là phân số
Ví dụ
Input:
a
1
2
Output:
false
*/
#include <iostream>
using namespace std;
struct PhanSo {
    int numberator, denominator;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.numberator >> p.denominator;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo p) {
        os << p.numberator << '/' << p.denominator;
        return os;
    }
    friend bool operator== (PhanSo p1, PhanSo p2) {
        return p1.numberator * p2.denominator == p2.numberator * p1.denominator;
    }
};

template <typename t>
bool ktBangNhau (t a, t b) {
    return a == b;
}

int main () {
    char c; cin >> c;
    switch (c) {
        case 'a':
        int a1, b1; cin >> a1 >> b1;
        ktBangNhau (a1, b1) ? cout << "true" : cout << "false"; break;
        case 'b':
        double a2, b2; cin >> a2 >> b2;
        ktBangNhau (a2, b2) ? cout << "true" : cout << "false"; break;
        case 'c':
        PhanSo a3, b3; cin >> a3 >> b3;
        ktBangNhau (a3, b3) ? cout << "true" : cout << "false"; break;
    }
    return 0;
}
