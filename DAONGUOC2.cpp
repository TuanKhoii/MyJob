/*
Nhập vào 1 dãy số, tìm số có số đảo ngược của nó là lớn nhất, nếu có nhiều hơn 2 số như vậy hãy xuất tất cả vị trí tìm thấy số đó ở dòng thứ 2
+ Dữ liệu vào từ file: inDaoNguoc2.txt
+ Dữ liệu ra file: outDaoNguoc2.txt
Ví dụ 1:
Input
12
123
341
Output
123
Ví dụ 2:
Input
123
12
123
341
Output
123
0  2
*/
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#define inp freopen("inDaoNguoc2.txt", "r", stdin);
#define out freopen("outDaoNguoc2.txt", "w", stdout);
#define Main_Function int main ()
#define made_by_081 return(0);

using namespace std;

int reverse (const int k) {
    int n = k, rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

Main_Function {
    cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
    inp out
    int n, count = 0, total = INT_MIN;
    vector<int> v;
    while (cin >> n) {
        int k = reverse(n);
        total = max(total, k);
        v.push_back(k);
    }
    vector<int> index;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == total) {
            index.push_back(i);
            count++;
        }
    }
    cout << reverse(total) << '\n';
    if (count > 1) for (auto i : index) cout << i << ' ';
    made_by_081
}
