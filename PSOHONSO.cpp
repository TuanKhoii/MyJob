/*
Xây dựng Cấu trúc PhanSo gồm tử và mẫu.
Viết các hàm toán tử:
- Nhập và xuất cho PhanSo
- So sánh != khi so sánh 2 phân số (HD: 2 phân số khác nhau khi có thành phần tương ứng khác nhau)
Yêu cầu 2: Xây dựng cấu trúc hỗn số gồm  một phần nguyên a và một phân số b/c, trong đó a, b,c ∈ Z
(yêu cầu PHẢI sử dụng lại cấu trúc PhanSo ở trên)
a)   Viết quá tải nhập và xuất cho cấu trúc trên
b)   Sử dụng tham số mặc định, yêu cầu viết hàm chuyển đổi hỗn số sang hỗn số tối giản hoặc chuyển sang phân số tối giản. (tham số mặc định áp dụng để chuyển sang hỗn số tối giản)
Ví dụ: với hỗn số , rút gọn thành , chuyển sang phân số thành 
c)   Hãy cài đặt quá tải tóan tử khác != khi so sánh 2 Hỗn Số. (HD: 2 hỗn số khác nhau khi có thành phần tương ứng của chúng khác nhau)
d)   Viết hàm tongCacThanhPhan dùng để tính tổng các thành phần của hổn số
ví dụ: hỗn số , kết quả trả về của hàm tongCacThanhPhan là: 6 (=1+2+3)
e)    Dựa vào hàm của câu d), hãy viết quá tải toán tử lớn hơn > để so sánh tổng các thành phần của 2 Hỗn Số.
Ví dụ:  >   (do: 4+ 5 + 6 = 15  > 1 + 2 +3 = 6)
Yêu cầu 3:
Viết chương trình nhập vào theo cấu trúc sau:
- Dòng 1: gồm 3 số của hỗn số 1
- Dòng 2: gồm 3 số của hỗn số 2.
- Dòng 3: nếu là chữ “true” yêu cầu rút gọn 2 hỗn số đó thành hỗn số rút gọn, nếu là "false" yêu cầu rút gọn thành phân số rút gọn.
Dữ liệu xuất:
- Dòng 1: xuất TRUE nếu 2 hỗn số khác nhau, ngược lại xuất FALSE.
- Dòng 2: xuất TRUE nếu hỗn số 1 “lớn hơn” hỗn số 2, ngược lại xuất FALSE (dựa vào câu e)
- Dòng 3: xuất dạng rút gọn của hỗn số 1
- Dòng 4: xuất dạng rút gọn của hỗn số 2.
(lưu ý: dòng 1 và dòng 2 áp dụng cho hỗn số ban đầu chưa rút gọn)
Input
2 8 6
1 2 3
true
Output
TRUE
TRUE
3 1/3
1 2/3
Input
2 8 6
1 2 3
false
Output
TRUE
TRUE
10/3
5/3
*/
#include <iostream>
#include <cmath>
using namespace std;
struct PhanSo {
    int b, c;
    friend istream& operator>> (istream &is, PhanSo &ps) {
        is >> ps.b >> ps.c;
        return is;
    }
    friend ostream& operator<< (ostream &os, PhanSo ps) {
        os << ps.b << '/' << ps.c << endl;
        return os;
    }
    friend bool operator!= (PhanSo p1, PhanSo p2) {
        return p1.b != p2.b && p1.c != p2.c;
    }
};
int UCLN (int a, int b) {
    int x = a, y = b;
    while (y) {
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}
struct HonSo {
    PhanSo ps;
    int a;
    friend istream& operator>>(istream &is, HonSo &hs) {
        is >> hs.a >> hs.ps.b >> hs.ps.c;
        return is;
    }
    friend ostream& operator<< (ostream &os, const HonSo hs) {
        os << hs.a << ' ' << hs.ps;
        return os;
    }
    HonSo toiGian (const HonSo hs) {
        HonSo tmp = hs;
        int ucln = UCLN (tmp.ps.b, tmp.ps.c);
        tmp.ps.b /= ucln;
        tmp.ps.c /= ucln;
        while (tmp.ps.b >= tmp.ps.c) {
            tmp.ps.b -= tmp.ps.c;
            tmp.a++;
        }
        return tmp;
    }
    PhanSo _toiGian (const HonSo &hs) {
        HonSo t = hs;
        PhanSo tg;
        tg.b = t.a * t.ps.c + t.ps.b;
        tg.c = t.ps.c;
        int ucln = UCLN (tg.b, tg.c);
        tg.b /= ucln;
        tg.c /= ucln;
        return tg;
    }
    friend bool operator!= (HonSo h1, HonSo h2) {
        return h1.a != h2.a && h1.ps.b != h2.ps.b && h1.ps.c != h2.ps.c;
    }
    int tongCacThanhPhan () {
        return a + ps.b + ps.c;
    }
    friend bool operator> (HonSo h1, HonSo h2) {
        return h1.tongCacThanhPhan () > h2.tongCacThanhPhan ();
    }
};
int main () {
    HonSo h1, h2;
    cin >> h1 >> h2;
    string Type;
    cin >> Type;
    h1 != h2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    h1 > h2 ? cout << "TRUE" << endl : cout << "FALSE" << endl;
    if (Type == "true") {
        cout << h1.toiGian (h1) << h2.toiGian (h2);
    } else if (Type == "false") {
        cout << h1._toiGian (h1) << h2._toiGian (h2);
    }
    return 0;
}
