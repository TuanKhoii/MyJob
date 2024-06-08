/*
Cho cấu trúc mảng 1 chiều.
yêu cầu xây dựng các hàm quá tải sau:
1. Nhập
2. Xuất.
3. Cộng
Viết một chương trình nhập vào 2 mảng 1 chiều, xuất tổng của 2 mảng ra màn hình
Hướng dẫn nhập:
Dòng 1: nhập số lượng phần tử mảng thứ 1
Dòng 2: Nhập các phần tử của mảng thứ 1
Dòng 3: nhập số lượng phần tử mảng thứ 2
Dòng 4: nhập số lượng phần tử mảng thứ 2
Hướng dẫn xuất: xuất ra  các phần tử của mảng mỗi phần tử cách nhau 1 khoảng trắng.
Ví dụ:
Input:
3
1 2 3
4
1 2 5 7
Output:
2 4 8 7
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
    friend Arr operator + (Arr a1, Arr a2) {
        Arr a3;
        int max = (a1.arr.size () > a2.arr.size ()) ? a1.arr.size () : a2.arr.size ();
        a3.arr.resize (max);
        for (int i = 0; i < max; i++) a3.arr[i] = a1.arr[i] + a2.arr[i];
        return a3;
    }
};

int main () {
    Arr a, b; cin >> a >> b;
    cout << a + b;
    return 0;
}
