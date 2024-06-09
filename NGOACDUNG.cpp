/*
Gọi xâu chỉ chứa các kí tự ngoặc tròn (, ), ngoặc vuông [, ] và ngoặc nhọn {, } là xâu ngoặc. Xâu ngoặc đúng được định nghĩa như sau:
- Xâu rỗng được coi là xâu ngoặc đúng
- Nếu a là xâu ngoặc đúng thì (a), {a}, [a] cũng là xâu ngoặc đúng
- Nếu a và b là các xâu ngoặc đúng thì ab cũng là xâu ngoặc đúng
Viết chương trình xác định xâu đầu vào có phải xâu ngoặc đúng hay không?
input:
Chứa một xâu cần xác định
output
Nếu xâu ngoặc đúng thì xuất  “yes” ngược lại xuất ra “no”
Ví dụ:
Input
[()]
Output
yes
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValidParentheses(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (!stk.empty() &&
                   ((c == ')' && stk.top() == '(') ||
                    (c == ']' && stk.top() == '[') ||
                    (c == '}' && stk.top() == '{'))) {
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}
int main() {
    string input;
    getline(cin, input);
    if (isValidParentheses(input)) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
