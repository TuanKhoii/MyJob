/*
Viết chương trình kiểm tra 1 số có 4 chữ số abcd có thỏa mãn tính chất sau không: a + b= c * d
Nếu thỏa xuất : "yes", ngược lại xuất "no"
ví dụ:
input:
1523
output:
yes
*/
#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e, f, g;
    cin >> e;
    a = e / 1000;
    b = (e / 100) % 10;
    c = (e % 100) / 10;
    d = e % 10;
    f = a + b;
    g = c * d;
    if (f == g) cout << "yes";
    else cout << "no";
    return 0;
}
