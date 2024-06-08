/*
Nhập:
Dòng 1: nhập vị trí cần xóa
Dòng 2: nhập vào 1 dãy số
Xuất:
mảng sau khi xóa
Ví dụ:
Input:
2
1 2 3 4
Output:
1 2 4
*/
#include <iostream>
using namespace std;
int main() {
    int x, n = 0, a[100], k;
    cin >> k;
    while(cin >> x) {
        a[n] = x;
        n++;
    }
    for(int i = k + 1; i < n; i++) a[i - 1] = a[i];
    for(int i = 0; i < n - 1; i++) cout << a[i] << " ";
    return 0;
}
