/*
Xây dựng chương trình có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số gồm nhiều loại số, yêu cầu xuất ra tổng của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số phân số
Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó
Dữ liệu đầu ra: Ghi ra 2 dòng:
o   Dòng 1: tổng của loại số nguyên
o   Dòng 2: tổng của loại phân số (kết quả đã được rút gọn)
Nếu không tìm thấy tổng của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó
Ví dụ 1:
Input:
a 1
b  1 2
b  2 3
Output:
1
7/6
Input:
b  1 2
b  2 3
Output:
khong co
7/6
*/
#include <iostream>
#include <vector>

using namespace std;

struct PhanSo {
    int tu, mau;
    friend istream& operator>> (istream &is, PhanSo &p) {
        is >> p.tu >> p.mau;
        return is;
    }
    static int gcd (PhanSo p) {
        int x = p.tu, y = p.mau;
        while (y) {
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    friend ostream& operator<< (ostream &os, PhanSo p) {
        os << p.tu / gcd (p) << '/' << p.mau / gcd (p);
        return os;
    }
    friend PhanSo operator+ (PhanSo p1, PhanSo p2) {
        PhanSo p3;
        p3.tu = p1.tu * p2.mau + p2.tu * p1.mau;
        p3.mau = p1.mau * p2.mau;
        return p3;
    }
};

template<typename t>
t Tong (vector<t> vt) {
    if (vt.empty ()) cout << "khong co" << endl;
    else {
        t sum = vt[0];
        for (int i = 1; i < vt.size (); i++) sum = sum + vt[i];
        cout << sum << endl;
    }
}

int main () {
    char c[1000];
    int i = 0;
    vector<int> a;
    vector<PhanSo> b;
    while (cin >> c[i]) {
        if (c[i] == 'a') {
            int digit; cin >> digit; a.push_back (digit);
        } else if (c[i] == 'b') {
            PhanSo temp; cin >> temp; b.push_back (temp);
        } i++;
    }
    Tong (a);
    Tong (b);
    return 0;
}
