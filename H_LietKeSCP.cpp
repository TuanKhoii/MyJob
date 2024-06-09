/*
Hãy tìm tất cả các số chính phương trong đoạn [A,B] .
Input
Gồm 2 số nguyên A và B cách nhau bởi 1 dấu cách ( 1 ≤ A ≤ B ≤ 200000).
Output
Ghi ra tất cả các số chính phương trong khoảng [A,B]. Mỗi số trên 1 dòng.
Ví dụ
Input:
1 100
Output:
1
4
9
16
25
36
49
64
81
100
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a, b, kq;
    cin >> a >> b;
    for(int i = a ; i <= b; i++) {
        kq = sqrt(i);
        if(kq * kq == i) {
            cout << i << endl;
        }
    }
    return 0;
}
