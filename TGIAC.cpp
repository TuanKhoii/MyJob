/*
Yêu cầu 1:  Xây dựng cấu trúc ĐIỂM gồm tung độ và hoành độ (số nguyên)
- Viết quá tải hàm nhập,xuất điểm
- Viết hàm tính khoảng cách giữa 2 điểm
- Viết quá tải so sánh bằng giữa 2 điểm: kiểm tra 2 điểm có trùng nhau không?
Yêu cầu 2: Xây dựng cấu trúc TAMGIAC gồm 3 điểm (PHẢI dựa vào cấu trúc ĐIỂM ở trên)
- Viết quá tải hàm nhập,xuất (không cần kiểm tra điều kiện của tam giác, giả sư với 3 điểm bất kỳ đều là tam giác)
- Viết hàm tính chu vi tam giác
- Quá tải toán tử + hai tam giác (HD: cộng chu vi tam giác)
- Quá tải toán tử <  dùng để so sánh 2 tam giác (HD: so sánh dựa vào chu vi)
- Quá tải toán tử so sánh bằng dùng kiểm tra 2 TAM GIÁC có trùng nhau hay không?
Yêu cầu 3: nhập dữ liệu tọa độ của 2 tam giác theo cấu trúc
Dòng 1: 3 điểm của tam giác 1
Dòng 2: 3 điểm của tam giác 2
Xuất kết quả theo cấu trúc sau:
Dòng 1: xuất các tọa độ của tam giác 1
Dòng 2: xuất các tọa độ của tam giác 2
Dòng 1: ghi TRUE, nếu tam giác 1 < tam giác 2, ngược lại ghi FALSE
Dòng 2: ghi TRUE, nếu 2 tam giác trùng nhau, ngược lại ghi FALSE
Ví dụ:
Input:
1 2 3 4 5 6
7 8 9 0 1 2
Output:
(1,2)(3,4)(5,6)
(7,8)(9,0)(1,2)
TRUE
FALSE.
*/
#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    int x, y;
    friend istream& operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<<(ostream &os, Point &p) {
        os << "(" << p.x << ',' << p.y << ")";
        return os;
    }
    double Khoang_Cach (Point a, Point b) {
        return sqrt (pow (b.x - a.x, 2) + pow (b.y - a.y, 2));
    }
    friend bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
};

struct TamGiac {
    Point a, b, c;
    friend istream& operator>>(istream &is, TamGiac &t) {
        is >> t.a >> t.b >> t.c;
        return is;
    }
    double Chuvi (TamGiac t) {
        double d1 = t.a.Khoang_Cach (a, b);
        double d2 = t.b.Khoang_Cach (b, c);
        double d3 = t.c.Khoang_Cach (c, a);
        return d1 + d2 + d3;
    }
    friend TamGiac operator+(TamGiac t1, TamGiac t2) {
        TamGiac t3;
        t3.a.x = t1.a.x + t2.a.x;
        t3.a.y = t1.a.y + t2.a.y;
        t3.b.x = t1.b.x + t2.b.x;
        t3.b.y = t1.b.y + t2.b.y;
        t3.c.x = t1.c.x + t2.c.x;
        t3.c.y = t1.c.y + t2.c.y;
        return t3;
    }
    friend bool operator<(TamGiac t1, TamGiac t2) {
        return t1.Chuvi (t1) < t2.Chuvi (t2);
    }
    friend bool operator== (TamGiac t1, TamGiac t2) {
        return  (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c) ||
                (t1.a == t2.b && t1.b == t2.c && t1.c == t2.a) ||
                (t1.a == t2.c && t1.b == t2.a && t1.c == t2.b) ||
                (t1.a == t2.a && t1.b == t2.c && t1.c == t2.b) ||
                (t1.a == t2.b && t1.b == t2.a && t1.c == t2.c) ||
                (t1.a == t2.c && t1.b == t2.b && t1.c == t2.a);
    }
};

int main () {
    TamGiac t1, t2;
    cin >> t1;
    cin >> t2;
    cout << t1.a << t1.b << t1.c << endl;
    cout << t2.a << t2.b << t2.c << endl;
    t1 < t2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    t1 == t2 ? cout << "TRUE" : cout << "FALSE";
    return 0;
}
