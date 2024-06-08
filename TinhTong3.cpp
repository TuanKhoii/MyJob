/*
Nhập vào 2 số nguyên N và M, yêu cầu tính tổng chữ số cuối cùng của  N và của M. (0<= N,M <=12345670)
Ví dụ:
Input:
123
456
Output
9
*/
#include <iostream>
using namespace std;
int main() {
    int n, m, x, y;
    cin >> n >> m;
    x = n % 10;
    y = m % 10;
    cout << x + y;
    return 0;
}
