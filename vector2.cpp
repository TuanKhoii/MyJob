/*
Nhập:
Dòng 1: nhập vị trí cần xóa hoặc đoạn cần xóa [a,b), hoặc nếu là -1 thì xóa hết dãy
Dòng 2: nhập vào 1 dãy số
Xuất:
mảng sau khi xóa, nếu dãy rỗng xuất ra chữ "empty"
Ví dụ 1:
Input
2
1 2 3 4
Output
1 2 4
Ví dụ 2:
Input
1 3
1 2 3 4
Output
1 4
*/
#include <iostream>
#include <vector>

using namespace std;

int main () {
    string position;
    getline (cin, position);
    int digit;
    vector<int> v;
    while (cin >> digit) v.push_back (digit);
    if (position == "-1") {
        cout << "empty";
        return 0;
    } else if (position[1] == ' ') {
        char x = position[0];
        char y = position[2];
        int begin = x - '0';
        int end = y - '0';
        int i = begin;
        while (i < end) {
            v.erase (v.begin () + begin);
            i++;
        }
        for (vector<int>::iterator it = v.begin (); it != v.end (); it++) {
            cout << *it << " ";
        }
        if (!v.size ()) cout << "empty";
    } else if (position.size () == 1) {
        int pos = stoi (position);
        v.erase (v.begin () + pos);
        for (vector<int>::iterator it = v.begin (); it != v.end (); it++) {
            cout << *it << " ";
        }
        if (!v.size ()) cout << "empty";
    }
    return 0;
}
