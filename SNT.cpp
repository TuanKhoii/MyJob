/*
Nhập vào 1 số.
Kiểm tra số đó có phải là số nguyên tố không? Xuất: true, nếu đó là số nguyên tố, ngược lại xuất false
Ví dụ:
Input
4
Output
false
*/
#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if (isPrime(n)) cout << "true";
    else cout << "false";
    return 0;
}
