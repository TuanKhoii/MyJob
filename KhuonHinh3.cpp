/*
Xây dựng 1 cấu trúc mảng có sử dụng khuôn hình, áp dụng cho bài sau:
Viết chương trình nhập vào 1 dãy số, yêu cầu xuất ra số nhỏ nhất của từng loại số ra màn hình.
Với các qui ước:
o   Kiểu a: là số nguyên
o   Kiểu b: là số thực
o   Kiểu c: là phân số
Dữ liệu đầu vào:
o   Gồm nhiều dòng còn lại, mỗi dòng chứa kiểu và 1 số thuộc kiểu đó
Dữ liệu đầu ra:
Ghi ra 3 dòng:
o   Dòng 1: số nhỏ nhất của loại số nguyên
o   Dòng 2: số nhỏ nhất của loại số thực.
o   Dòng 3: số nhỏ nhất của loại phân số.
Nếu không tìm thấy số nhỏ nhất của loại nào thì xuất kết quả “khong co” (chữ thường, không dấu) tại vị trí của loại đó
Ví dụ 1:
Input:
a 1
b 1.2
c  1 2
b  2.4
c  2 3
Output:
1
1.2
1/2
Ví dụ 2:
Input:
b 1.2
c  1 2
b  2.4
c  2 3
Output:
khong co
1.2
1/2
*/
#include <iostream>
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
    bool operator < (PhanSo p2) {
        return this->tu * p2.mau < p2.tu * this->mau;
    }
};

template<typename t>
struct Arr {
    int size = 0;
    t arr[100010];
    void in () {
        t c;
        cin >> c; 
        this->arr[this->size++] = c;
    }
    void Min () {
        if (this->size == 0) cout << "khong co" << endl;
        else {
            t min = arr[0];
            for (int i = 1; i < this->size; i++) if (this->arr[i] < min) min = this->arr[i];
            cout << min << endl;
        }
    }
};
int main () {
    char kt;
    Arr<int> a;
    Arr<double> b;
    Arr<PhanSo> c;
    while (cin >> kt) {
        if (kt == 'a') a.in ();
        if (kt == 'b') b.in ();
        if (kt == 'c') c.in ();
    }
    a.Min ();
    b.Min ();
    c.Min ();
    return 0;
}
