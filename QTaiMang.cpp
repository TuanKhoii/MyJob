/*
Cho cấu trúc mảng 1 chiều. Yêu cầu xây dựng các hàm quá tải sau:
1. Nhập
2. Xuất.
3. Gán
4. Cộng
5. So sánh bằng
6. So sánh khác
7. Toán tử []
Viết một chương trình nhập vào 2 mảng 1 chiều, xuất "yes" nếu 2 mảng giống nhau, ngược lại xuất "no" nếu 2 mảng khác nhau.
Hướng dẫn nhập:
Dòng 1: nhập số lượng phần tử mảng thứ 1 (<=10)
Dòng 2: Nhập các phần tử của mảng thứ 1 (mỗi phần tử có giá trị <=100)
Dòng 3: nhập số lượng phần tử mảng thứ 2 (<=10)
Dòng 4: Nhập các phần tử của mảng thứ 2 (mỗi phần tử có giá trị <=100)
Ví dụ:
Input
3
1 2 3
4
1 2 5 7
Output
no
*/
#include <iostream>
#include <vector>

using namespace std;

struct Arr {
    int size;
    vector<int> arr;
    friend istream& operator >> (istream &is, Arr &a) {
        is >> a.size;
        a.arr.resize (a.size);
        for (int &i : a.arr) is >> i;
        return is;
    }
    friend ostream& operator << (ostream &os, Arr a) {
        for (int i : a.arr) os << i << ' ';
        return os << "\n";
    }
    Arr& operator = (const Arr a) {
        this->size = a.size;
        for (int i : a.arr) this->arr.push_back (i);
        return *this;
    }
    int& operator [] (int index) {
        return this->arr[index];
    }
    friend Arr operator + (Arr a1, Arr a2) {
        Arr a3;
        int max = (a1.arr.size () > a2.arr.size ()) ? a1.arr.size () : a2.arr.size ();
        a3.arr.resize (max);
        for (int i = 0; i < max; i++) a3.arr[i] = a1.arr[i] + a2.arr[i];
        return a3;
    }
    friend bool operator == (Arr a1, Arr a2) {
        if (a1.arr.size () != a2.arr.size ()) return false;
        for (int i = 0; i < a1.arr.size (); i++) if (a1.arr[i] != a2.arr[i]) return false;
        return true;
    }
    friend bool operator != (Arr a1, Arr a2) {
        if (a1.arr.size () != a2.arr.size ()) return true;
        for (int i = 0; i < a1.arr.size (); i++) if (a1.arr[i] != a2.arr[i]) return true;
        return false;
    }
};

int main () {
    Arr a, b; cin >> a >> b;
    cout << ((a == b) ? "yes" : "no");
    return 0;
}
