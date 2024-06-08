/*
Viết 1 hàm template tìm phần tử lớn nhất trong 3 số.
Yêu cầu xuất phần tử lớn nhất trong 3 số.
Qui ước: a là số nguyên, b là số thực, c là phân số (các số nhập <= 100)
ví dụ: a 1 2 3 tức là nhập 3 số nguyên
Dữ liệu vào:
Dòng 1: là nhập vào loại số
3 dòng tiếp theo: mỗi dòng chứa 1 số thuộc kiểu của dòng 1
Dữ liệu ra: gồm 1 dòng là số lớn nhất tìm thấy
Ví dụ 1:
Input
Output
a
1
2
3
3
Ví dụ 2:
Input
Output
c
1 2
1 1
2 3
1/1
*/
#include <iostream>
using namespace std;
template<typename T>
T Max(T digit1, T digit2, T digit3) {
    T max = digit1;
    if (digit2 > max) max = digit2;
    if (digit3 > max) max = digit3;
    return max;
}
struct PhanSo {
    int on, un;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.on >> p.un;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo p) {
        os << p.on << '/' << p.un;
        return os;
    }
    friend bool operator > (PhanSo p1, PhanSo p2) {
        return p1.on / p1.un > p2.on / p2.un;
    }
};
int main () {
    char c; cin >> c;
    switch (c) {
        case 'a':
        int a, b, c; cin >> a >> b >> c;
        cout << Max (a, b, c); break;
        case 'b':
        double x, y, z; cin >> x >> y >> z;
        cout << Max (x, y, z); break;
        case 'c':
        PhanSo arr[3];
        for (PhanSo &p : arr) cin >> p;
        cout << Max (arr[0], arr[1], arr[2]);
    }
    return 0;
}
