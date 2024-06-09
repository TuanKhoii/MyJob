/*
(Hình chữ nhật tối đại trong ma trận 0/1) Cho một ma trận biểu diễn bằng một mảng 2 chiều kích thước n xm ô và chỉ chứa các ký tự 0 và 1. 
Tìm hình chữ nhật đầu tiên chứa toàn ký tự 1 và có diện tích lớn nhất (gọi là hình chữ nhật tối đại).
Yêu cầu xuất ra diện tích lớn nhất.
ví dụ:
input:
5 9
1 0 0 0 1 0 0 0 0
1 1 1 1 1 1 1 0 0
0 0 1 1 1 1 1 0 0
0 0 1 1 1 1 1 0 0
0 0 0 1 1 0 0 0 0
output:
15
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int maximalRectangle(vector<string>& matrix) {
    if(matrix.empty()) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> left(m, 0), right(m, m), height(m, 0);
    int maxArea = 0;
    
    for(int i = 0; i < n; ++i) {
        int curLeft = 0, curRight = m;
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        for(int j = 0; j < m; ++j) {
            if(matrix[i][j] == '1')
                left[j] = max(left[j], curLeft);
            else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }
        for(int j = m - 1; j >= 0; --j) {
            if(matrix[i][j] == '1')
                right[j] = min(right[j], curRight);
            else {
                right[j] = m;
                curRight = j;
            }
        }
        for(int j = 0; j < m; ++j) {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }
    return maxArea;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            matrix[i] += c;
        }
    }
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
