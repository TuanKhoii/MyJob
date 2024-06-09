/*
Nhập vào 2 số nguyên a và b.
Yêu cầu tìm UCLN của 2 số đó.
ví dụ
input:
10 8
output
2
*/
#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}
