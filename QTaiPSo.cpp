/*
Cho cấu trúc Phân số gồm tử và mẫu.
yêu cầu xây dựng các hàm quá tải sau:
1. Nhập
2. Xuất.
3. Cộng
4. So sánh bằng
5. So sánh khác
Viết một chương trình nhập vào 2 phân số, yêu cầu xuất như sau
    xuất tổng 2 phân số (sau khi rút gọn)
Input
1 2
2 4
Output
1/1 
*/
#include <iostream>
using namespace std;
struct PhanSo {
    int tu, mau;
    friend istream& operator >> (istream &is, PhanSo &ps) {
        is >> ps.tu >> ps.mau;
        return is;
    }
    static int gcd (int tu, int mau) {
        int x = tu, y = mau;
        while (y) {
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
    friend ostream& operator << (ostream &os, PhanSo ps) {
        int ucln = gcd (ps.tu, ps.mau);
        os << ps.tu / ucln << '/' << ps.mau / ucln << endl;
        return os;
    }
    friend PhanSo operator + (PhanSo p1, PhanSo p2) {
        PhanSo p3;
        p3.tu = p1.tu * p2.mau + p2.tu * p1.mau;
        p3.mau = p1.mau * p2.mau;
        return p3;
    }
    friend bool operator == (PhanSo p1, PhanSo p2) {
        return p1.tu * p2.mau == p1.mau * p2.tu;
    }
    friend bool operator != (PhanSo p1, PhanSo p2) {
        return p1.tu * p2.mau != p1.mau * p2.tu;
    }
};

int main () {
    PhanSo arr[2];
    for (PhanSo &i : arr) cin >> i;
    cout << arr[0] + arr[1];
    return 0;
}
