/*
Viết một chương trình đệ quy tính tổng các chữ số của số N cho trước (N<= 123456789)
Ví dụ: 
Input: 123 
Ouput: 6 
(vì : 1+2+3 =6)
*/
#include<iostream>
using namespace std;
int main() {
    int n, i, sum;
    sum = 0;
    cin >> n;
    while(n) {
        i = n % 10;
        sum += i;
        n /= 10;
    }
    cout << sum;
    return 0;
}
