/*
Nhập vào 2 số a và b, yêu cầu xuất ra bội chung nhỏ nhất của 2 số đó.
ví dụ:
input:
2 3
output
6
*/
#include <iostream>
using namespace std;
int UCLN(int a, int b){
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int a, b;
    cin >> a >> b;
    int gan = UCLN(a,b);
    cout << (a * b) / gan;
    return 0;
}
