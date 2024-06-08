/*
Input:
Nhap vao 1 mang
Output:
Xuất mảng vừa nhập
Vi du:
Input:
4 5 6
Output
4 5 6
*/
#include <iostream>
using namespace std;
int main() {
    int a[100], n = 0, x;
    while(cin >> x){
        a[n] = x;
        n++;
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    return 0;
}
