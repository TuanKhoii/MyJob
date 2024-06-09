/*
Nhập vào 1 dãy số nguyên, yêu cầu tìm phần tử lớn nhất trong mảng
ví dụ:
input:
1 2 3 4 5
output:
5
*/
#include <iostream>
using namespace std;
int main() {
    int n = 0, x, max;
    int a[100];
    while(cin >> x) {
        a[n] = x;
        n++;
    }
    max = a[0];
    for(int i = 1; i < n; i++) {
        if(max < a[i]) max = a[i];
    }
    cout << max;
    return 0;
}
