/*
Xây dựng cấu trúc BacNhat biểu diễn một đa thức bậc 1 có dạng ax+b, trong đó a,b là số nguyên
Yêu cầu 1:
a) Xây dựng cấu trúc trên.
b) Viết quả tải toán tử nhập và xuất cho cấu trúc trên (nhập hệ số a,b)
c) Viết hàm tính giá trị của BacNhat với giá trị x cụ thể
Ví dụ: với F(x) =  2x + 3 và x = 2;
           F(2) =   2*2 + 3 =  4 +3 =7
d) Hãy cài đặt hàm quá tải toán tử cộng 2 BacNhat bằng cách cộng từng hệ số với nhau, kết quả trả về 1 BacNhat.
Ví dụ: 
F1(x) = 2x + 3
F2(x) = 5x + 6
=> Tong(x) = 7x + 9
e) hãy cài đặt quá tải toán tử so sánh bằng, so sánh 2 BacNhat bằng xét tổng 2 hệ số a+b
ví dụ:
F1(x) = 2x + 3
F2(x) = 5x + 6
F1 không bằng F2, vì 2 + 3 != 5+6
Yêu cầu 2:
Viết chương trình nhập vào theo cấu trúc sau
Dòng 1 là 2 hệ số của 1 BacNhat  F1
Dòng 2 là 2 hệ số của 1 BacNhat F2
Dòng 3 là 1 số nguyên x0
Xuất kết quả theo cấu trúc sau:
Dòng 1: xuất F1 (dạng đầy đủ ax+b)
Dòng 2: xuất F2 (dạng đầy đủ ax+b)
Dòng 3: xuất tổng F1 và F2 (xem cách xuất ở ví dụ bên dưới)
Dòng 4: giá trị F1(x0)
Dòng 5: giá trị F2(x0)
Dòng 6: xuất TRUE nếu 2 BacNhat bằng nhau, ngược lại xuất FALSE
Ví dụ:
Input:
2 3
5 6
2
Output:
2x+3
5x+6
2x+3+5x+6=7x+9
7
16
FALSE
*/
#include <iostream>
using namespace std;
struct BacNhat {
    int a, b;
    friend istream& operator >> (istream& in, BacNhat &other) {
        in >> other.a >> other.b;
        return in;
    }
    friend ostream& operator << (ostream& out, BacNhat other) {
        out << other.a << "x+" << other.b;
        return out;
    }
    int giaTri (int x) {
        return this->a*x + this->b;
    }
    BacNhat operator + (BacNhat other) {
        BacNhat res;
        res.a = this->a + other.a;
        res.b = this->b + other.b;
        return res;
    }
    bool operator == (BacNhat other) {
        return this->a + this->b == other.a + other.b;
    }
};
int main () {
    BacNhat f1, f2;
    int x;
    cin >> f1 >> f2 >> x;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f1 << "+" << f2 << "=" << f1 + f2 << endl;
    cout << f1.giaTri(x) << endl;
    cout << f2.giaTri(x) << endl;
    if (f1 == f2) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}
