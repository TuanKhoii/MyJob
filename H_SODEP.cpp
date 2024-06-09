/*
Số tự nhiên N được gọi là số đẹp nếu tổng các chữ số của N tận cùng bằng 9. Ví dụ một số số đẹp là 18 (1+8=9), 234 (2+3+4=9), 658 (6+5+8=19). Cho một số N, hãy kiểm tra xem N có phải là số đẹp hay không.
Dữ liệu nhập:
- Là số nguyên N (0 ≤ n ≤ 109)
Dữ liệu xuất:
- Nếu N là số đẹp, in ra "TRUE", nếu không in ra "FALSE"
Ví dụ
input: 27 --> output: TRUE
input: 2727 --> output: FALSE
input: 888333777 --> output: FALSE
*/
#include <iostream>
using namespace std;
int main() {
    long n, i, total, temp;
    total = 0;
    cin >> n;
    while(n) {
        i = n % 10;
        total += i;
        n /= 10;
    }
    temp = total % 10;
    if(temp == 9) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}
