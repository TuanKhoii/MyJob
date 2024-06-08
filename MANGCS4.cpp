/*
Nhập vào một mảng 2 chiều => xuất ma trận zic zac
Input:
Dòng 1: nhập chiều nxm
Dòng 2: n dòng tiếp theo, mỗi dòng m số nguyên
Output:
Xuất ma trận ziczac
ví dụ:
Input:
3 3
7 8 9
1 2 3
6 5 4
Output:
1 2 3
6 5 4
7 8 9
*/
#include <iostream>
using namespace std;
int main() {
    int a[100][100];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < m; i++){
        cout << a[0][i] << ' ';
    }
    return 0;
}
