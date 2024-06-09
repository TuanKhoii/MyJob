/*
Cho một tệp văn bản có tên CNMAX.INP gồm các dòng dài bằng nhau, mỗi dòng có đúng mký tự và không chứa dấu cách. Dòng đầu tiên của tệp chứa số m.
Tìm hình chữnhật chứa cùng một loại ký tự và có diện tích lớn nhất. Biết 3 <= m <=78 và diê.n tích lớn nhất có thê đạt tới chữ số hàng tỷ.
Kết quả cần được hiển thị theo dạng sau:
 Dòng đầu tiên: Diện tích của hình chữ nhật tối đại đầu tiên ABCD tìm được,
- Dòng thứ hai: Toạ độ dòng và cột của đỉnh A,
- Dòng thứ ba: Toạ độ dòng và cột của đỉnh C.
(tọa độ được tính bắt đầu từ 1)
Dữ liệu xuất ra tập tin văn bản CNMAX.OUT
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("CNMAX.INP","r",stdin);
    freopen("CNMAX.OUT","w",stdout);
    int m, a[101][101], f[101][101], x_a, y_a, x_c, y_c;
    cin >> m ;
    long long hb = 0;
    int n = 0;
    string s;
    while (cin >> s){
        n++;
        for (int i = 0; i < s.size(); i++) a[n][i+1] = s[i] - '0';
    }
    for (int i = 0; i <= m; i++) f[0][i] = 0;
    for (int i = 0; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            for (int u = i; u <= n; u++)
                for (int v = j; v <= m; v++){
                    long long sum = f[u][v] + f[i-1][j-1] - f[u][j-1] - f[i-1][v];
                    if (sum != a[i][j]*(u-i + 1)*(v-j + 1)) break;
                    else{
                        if (sum > hb) {
                            hb = sum;
                            x_a = i, y_a = j, x_c = u, y_c = v;
                        }
                    }
                }
        }
    cout << hb/a[x_a][y_a] << endl;
    cout << x_a <<" " << y_a << endl;
    cout << x_c <<" " << y_c << endl;
    return 0;
}
