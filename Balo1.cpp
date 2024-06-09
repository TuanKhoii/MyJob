/*
Cho n món hàng có khối lượng lần lượt là a[0], a[1], ... ,a[n-1] (đơn vị là kg) và 1 balô có khả năng chứa là w (kg).
yêu cầu chọn những món hàng nào bỏ vào balô sao cho tổng khối lượng là lớn nhất và không vượt quá w
dữ liệu vào: gồm 2 dòng
- dòng 1: chứa 2 số n và w
- dòng 2: chứa n số nguyên a[0], a[1], ... ,a[n-1]
dữ liêu ra : gồm 2 dòng
- dòng 1: khối lượng tối ưu của balo sau khi chọn các món hàng
- dòng 2: thứ tự các món hàng được chọn (số nhỏ ghi trước số lớn ghi sau)
ví dụ
input:
3 10
3 5 7
output:
10
0 2
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + weights[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int maxWeight = dp[n][w];
    cout << maxWeight << endl;
    vector<int> chosenItems;
    int i = n, j = w;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            chosenItems.push_back(i - 1);
            j -= weights[i - 1];
        }
        i--;
    }
    for (int k = chosenItems.size() - 1; k >= 0; k--) {
        cout << chosenItems[k] << " ";
    }
    return 0;
}
