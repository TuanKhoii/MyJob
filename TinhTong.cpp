/*
Nhập vào 1 dãy số, yêu cầu tính tổng các chữ số của dãy đó.
Ví dụ:
Input:
1
12
23
Output:
1
3
5
*/
#include <iostream>
using namespace std;
int main(){
    int x;
    while (cin >> x){
        int s=0;
        while(x) {
            s += x % 10;
            x /= 10;
        }
        cout << s << endl;
    }
}
