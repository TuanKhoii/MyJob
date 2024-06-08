/*
Nhập vào 1 số.
Kiểm tra số đó có phải là số chính phương không?
Xuất: yes, nếu đó là số chính phương, ngược lại xuất no
ví dụ:
Input: 4
Output: yes
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int kq = sqrt(a);
    if (kq * kq == a) {
        cout << "yes";
    }
    else cout << "no";
    return 0;
}
