/*
Nhập vào 2 số nguyên a và b.
yêu cầu xuất ra tổng của 2 số a và b
Dữ liệu vào từ file văn bản: input.txt gồm 2 số nguyên
Dữ liệu ra file văn bản output.txt tổng 2 số nguyên đó
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
    ifstream ifs;
    ifs.open("input.txt");
    int a, b; ifs >> a >> b; ifs.close();
    ofstream ofs;
    ofs.open("output.txt"); ofs << a + b;
    ofs.close();
    return 0;
}
