/*
Xây dựng cấu trúc PhanSo:
Viết quá tải toán tử: >>, <<, ==,!=,+
Xây dựng cấu trúc mảng Phân số
viết quá tải toán tử: >>,<<,[].
Viết cấu trúc nhập vào dãy phân số, yêu cầu xuất tổng phân số sau khi rút gọn
Ví dụ:
Input:
1 2
2 3
3 4
Output:
23/12
*/
#include <iostream>
using namespace std;
struct phanso {
    int tu, mau;
};
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main() {
    phanso a[1000];
    int i = 0;
    int top = 0, bottom = 1;
    while (cin >> a[i].tu >> a[i].mau) {
        top = (a[i].tu * bottom + top * a[i].mau);
        bottom *= a[i].mau;
    }
    cout << top / UCLN(top, bottom) << "/" << bottom / UCLN(top, bottom);
    return 0;
}
