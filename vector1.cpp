/*
Nhập vào một dãy số dùng vector.
yêu cầu dùng iterator để xuất ra màn hình
- Dòng 1 xuất theo chiều thuận (từ begin() đến end() )
- Dòng 2 xuất theo chiều ngược (từ rbegin() đến rend() )
Ví dụ:
Input
1 2 3
Output
1 2 3
3 2 1
*/
#include <iostream>
#include <vector>
using namespace std;
int main () {
    vector<int> v;
    int k;
    while (cin >> k) {
        cout << k << ' ';
        v.push_back(k);
    }
    cout << '\n';
    for (vector<int>::reverse_iterator it = v.rbegin (); it != v.rend (); it++) {
        cout << *it << ' ';
    }
    return 0;
}
