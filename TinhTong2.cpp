/*
Nhập vào 1 dãy số, yêu cầu tính tổng các chữ số nguyên tố của dãy đó.
Ví dụ:
Input:
1
12
23
Output:
0
2
5
*/
#include<iostream>
using namespace std;
bool isPrime(int a){
    if(a < 2) return false;
    for(int i = 2; i < a; ++i){
        if(a % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    while(cin >> n){
        int s = 0;
        while(n) {
            int m = n % 10;
            if(isPrime(m)) s += m;
            n /= 10;
        }
      cout << s << endl;  
    }
    return 0;
}
