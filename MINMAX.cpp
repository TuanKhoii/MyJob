/*
Bạn hãy nhập vào 1 dãy số, yêu cầu tìm số nhỏ nhất và số lớn nhất, sau đó tính tổng 2 số đó ra màn hình.
input:
Nhập vào 1 dãy số, mỗi số cách nhau 1 khoảng trắng
output:
- dòng 1: xuất số nhỏ nhất
- dòng 2: xuất số lớn nhất
- dòng 3: xuất tổng số nhỏ và số lớn nhất
ví dụ:
input:
1 2 3 4 5
output
1
5
6
*/
#include<iostream>
using namespace std;
int main() {
    int n = 0, x, min, max;
    int a[100];
    while(cin >> x) {
        a[n] = x;
        n++;
    }
    max = a[0];
    min = a[0];
    for(int i = 1;i < n; i++) {
        if(max < a[i]) max = a[i];
        if(min > a[i]) min = a[i];
    }
    cout << min << endl;
    cout << max << endl;
    cout << min + max;
    return 0;
}
