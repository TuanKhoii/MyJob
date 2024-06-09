/*
Xuất tất cả dãy nhị phân có độ dài là n.
input gồm 1 số tự nhiên n, n>=1
Ouput: xuất tất cả dãy số nhị phân có độ dài n, theo thứ tự tăng dần (mỗi dãy là 1 một dòng)
Ví dụ:
Input:
3
output:
000
001
010
011
100
101
110
111
*/
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    int totalSequences = 1 << N;  
    for (int i = 0; i < totalSequences; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            cout << ((i >> j) & 1);
        }
        cout << endl;
    }
    return 0;
}
