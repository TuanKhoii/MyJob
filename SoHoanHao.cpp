/*
Số hoàn hảo là số mà tổng ước số của nó (không tính nó) bằng chính nó.
yêu cầu: nhập vào 1 số, xuất là Yes nếu nó là số hoàn hảo, ngược lại xuất No..
Ví dụ:
Input	
6
Output
Yes
*/
#include <iostream>
using namespace std;
int main() {
	int a, i, tonguoc = 0;
	cin >> a;
	for (i=1;i < a; i++) {
		if (a % i == 0) tonguoc = tonguoc + i;
	}
	if (tonguoc == a) cout << "Yes";
	else cout << "No";
  return 0;
}
