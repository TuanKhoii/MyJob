/*
Viết chương trình in ra màn hình ngôi sao (với chiều cao h nhập từ bàn phím)
Ví dụ:
Input:
3
output
*
**
***
*/
#include <iostream>
using namespace std;
int main() {
    int a;
    cin>>a;
    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= i; ++j) {
            cout << '*';
        } 
        cout << endl;
    }
    return 0;
}
