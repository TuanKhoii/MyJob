/*
Cho một biểu thức hậu tố với số hạng là các số nguyên dương và ba toán tử +, -, *. Hãy tính giá trị của biểu thức hậu tố.
Ví dụ: biểu thức hậu tố: 2 3 4 + * 5 - 2 2 * + có giá trị là 13.
Dữ liệu input:
Gồm một dòng thể hiện biểu thức hậu tố, mỗi số hạng là một số nguyên dương trong phạm vi từ 1 đến 100. Giữa hai số hạng, hoặc giữa hai toán tử, hoặc giữa số hạng và toán tử, cách nhau một khoảng trắng. 
Chiều dài biểu thức không quá 100 ký tự. Dữ liệu đề bài cho đảm bảo biểu thức hậu tố là hợp lệ. Trong quá trình tính toán đảm bảo trị tuyệt đối các giá trị trung gian không vượt quá 109.
Dữ liệu output:
- Là giá trị của biểu thức hậu tố.
Ví dụ:
input
2 3 4 + * 5 - 2 2 * +
output
13
*/
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
//  1. Stack
// 	2. init
// 	3.  empty
// 	4.  full
using namespace std;

int evaluatePostfix(const string &postfix) {
    stack<int> operands;

    stringstream ss(postfix);
    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            operands.push(stoi(token));
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(operand1 + operand2);
            } else if (token == "-") {
                operands.push(operand1 - operand2);
            } else if (token == "*") {
                operands.push(operand1 * operand2);
            }
        }
    }

    return operands.top();
}

int main() {
    string postfix;
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << result << endl;

    return 0;
}
