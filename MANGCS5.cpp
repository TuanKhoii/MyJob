/*
Nhập vào 1 mảng, yêu cầu tính tổng các số chính phương ra màn hình.
Ví dụ
Input:
4 5 6 7 9
Output:
13
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isPerfect(int n) {
    int a = sqrt(n);
    return a * a == n;
}
int main() {
    int n, total = 0;
    while(cin >> n) {
        if(isPerfect(n)) total += n;
    }
    cout << total;
    return 0;
}
