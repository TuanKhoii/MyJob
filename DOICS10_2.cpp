/*
Nhập vào 1 số nguyên ở hệ 10, yêu cầu xuất ra 1 số ở hệ 2
Ví dụ:
Input
10
Output
1010
*/
#include <iostream>
using namespace std;
int main() {
    int b, a[100], c = 0;
    long n;
    cin >> n;
    if(n == 0) cout << 0;
    while(n) {
        b = n % 2;
        a[c] = b;
        n /= 2;
        c++;
    }
    for(int i = c - 1; i >= 0; i--) {
        cout << a[i];
    }
    return 0;
}
