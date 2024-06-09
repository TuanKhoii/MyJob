/*
Xuất nội dung của stack sau mỗi thao tác trong dãy.
Một chữ cái tượng trưng cho thao tác thêm chữ cái đó vào trong stack, dấu * tượng trưng cho thao tác lấy nội dung một phần tử trong stack in lên màn hình (nếu không có thì không in).
Cho biết kết quả xuất ra màn hình sau khi hoàn tất chuỗi input.
Ví dụ:
Input	
AB*
Output
B
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    stack<char> st;
    string input;
    cin >> input;
    for (char c : input) {
        if (c == '*') {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else st.push(c);
    }
    return 0;
}
