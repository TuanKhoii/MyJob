/*
Số "CHỮ SỐ CHẴN" của một số được định nghĩa là số được tạo bởi các chữ số ở vị trí chẵn của một số nào đó (vị trí được đếm từ 0, tính từ trái sang phải)
(tương tự cho định nghĩa "CHỮ SỐ LẼ")
Ví dụ: số 1234, thì số "CHỮ SỐ CHẴN" của nó là 13.
Yêu cầu 1: viết các hàm sau:
1. quá tải toán tử >> (nhập vào 1 số nguyên)
2. quá tải toán tử << (xuất "CHỮ SỐ CHẴN" của số đó)
ví dụ: với số a=1234, cout << a; kết quả sẽ là: 13.
3. Quá tải toán tử so sánh < (dựa vào "CHỮ SỐ CHẴN" của nó)
ví dụ: 1434 < 1254 (vi 13<15)
4. viết hàm tính tổng thành phần (có sử dụng tham số mặc định)
+ Tham số mặc định có giá trị 0: là tổng các chữ số tại vị trí chẵn của số ban đầu
+ Tham số có giá trị 1 là tổng các chữ số tại vị trí lẽ của số ban đầu
ví dụ: với a=1234
cout << tongThanhPhan(a,0); // ket quả là: 4 (vì 1+3 = 4)
cout << tongThanhPhan(a); // ket quả là: 4 (vì 1+3 = 4)
cout << tongThanhPhan(a,1); // ket quả là: 6 (vì 2 + 4  = 6)
Yêu cầu 2: viết chương trình nhập theo thứ tự sau:
Dòng 1: nhập 2 số nguyên a và b (10 <= a,b <= 35000)
Dòng 2: nhập cách tính tổng thành phần
Yêu cầu xuất ra theo thứ tự sau:
- Dòng 1: xuất số "CHỮ SỐ CHẴN" của số a
- Dòng 2: xuất số "CHỮ SỐ CHẴN" của số b
- Dòng 3: ghi true nếu a < b, ngược lại ghi false (dựa vào phép so sánh < ở trên)
- Dòng 4: xuất tổng thành phần của a
- Dòng 5: xuất tổng thành phần của b
ví dụ:
input:
1234 5678
0
output:
13
57
true
4
12
*/
#include <iostream>
#include <string>

using namespace std;

struct So_ChuSoChan{
	string s;
};

istream& operator>>(istream& is, So_ChuSoChan& so);
ostream& operator<<(ostream& os, So_ChuSoChan so);

int toInt(So_ChuSoChan so);
bool operator<(So_ChuSoChan so1, So_ChuSoChan so2);
int tongThanhPhan(So_ChuSoChan so, int flag = 0);


int main(){
	So_ChuSoChan s1,s2;
	int x;
	cin >> s1>>s2>>x;
	cout << s1 << endl;
	cout << s2 << endl;

	if (s1 < s2)
		cout << "true"<<endl;
	else
		cout << "false"<<endl
		;

	cout << tongThanhPhan(s1, x)<<endl;
	cout << tongThanhPhan(s2, x) << endl;

	return 0;
}

istream& operator>>(istream& is, So_ChuSoChan& so){
	is >> so.s;
	return is;
}
ostream& operator<<(ostream& os, So_ChuSoChan so){	
	os << toInt(so);
	return os;
}

int toInt(So_ChuSoChan so){
	int tmp = 0;
	
	for (int i = 0; i < so.s.size(); i++)
		if (i % 2 == 0)
			tmp = tmp * 10 + (int)so.s[i] - 48;

	return tmp;
}

bool operator<(So_ChuSoChan so1, So_ChuSoChan so2){
	return toInt(so1) < toInt(so2);
}

int tongThanhPhan(So_ChuSoChan so, int flag){
	int tmp = 0;
	if (flag == 0) {
		for (int i = 0; i < so.s.size(); i++)
			if (i % 2 == 0)
				tmp = tmp  + (int)so.s[i] - 48;
	}
	else {
		for (int i = 0; i < so.s.size(); i++)
			if (i % 2 != 0)
				tmp = tmp + (int)so.s[i] - 48;
	}
	return tmp;
}
