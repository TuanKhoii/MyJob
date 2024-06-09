/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
Dữ liệu vào từ file văn bản: input.txt gồm 2 số nguyên
Dữ liệu ra màn hình tổng 2 số nguyên đó
Ví dụ:
Input
2 3
Output
5
*/
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream ifs;
    ifs.open("input.txt");
    int a, b; ifs >> a >> b;
    cout << a + b;
    return 0;
}
