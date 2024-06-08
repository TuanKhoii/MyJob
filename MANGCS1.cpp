/*
Nhập:
Dòng 1: nhập vị trí cần thêm và giá trị thêm (có giá trị <=100)
Dòng 2: nhập vào 1 dãy số (dãy số có tối đa 100 phần tử)
Xuất: 
Mảng sau khi thêm
Lưu ý: mảng được đánh chỉ số bắt đầu từ 0
Ví dụ
Input:
2 5
1 2 3 4
Output:
1 2 5 3 4
*/
#include <iostream>
using namespace std;
int main(){
    int a, b, d, dem = 0;
    cin >> a >> b;
    int c[100];
    while(cin >> d) {
        c[dem] = d;
        dem++;
    }
    for(int i = dem; i > a; --i){
        c[i] = c[i-1];
    }
    c[a] = b;
    for(int i = 0; i <= dem; i++){
        cout << c[i] << ' ';
    }
    return 0;
}
