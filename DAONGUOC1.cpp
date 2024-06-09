/*
Nhập vào 1 dãy số, tìm số có số đảo ngược của nó là lớn nhất    
Ví dụ:
Input
123
12
1
341
Output
123
*/
#include <iostream>
using namespace std;
int reverse (int n) {
    int temp = 0;
    while (n != 0) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

int main () {
    int n;
    int max = -9999;
    while (cin >> n) {
        int temp = reverse (n);
        if (temp > max) max = temp;
    }
    cout << reverse (max);
    return 0;
}
