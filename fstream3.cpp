/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
Dữ liệu vào từ bàn phím (nhập chuẩn) gồm 2 số nguyên
Dữ liệu ra file văn bản out.txt tổng 2 số nguyên đó
Ví dụ:
Input
2 3
Output
5
*/
#include <iostream>
#include <fstream>
using namespace std;
int main () {
    int a, b; 
    cin >> a >> b;
    ofstream ofs; 
    ofs.open("out.txt");
    ofs << a + b; 
    ofs.close();
    return 0;
}
