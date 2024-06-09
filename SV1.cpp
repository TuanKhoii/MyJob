/*
Xây dựng 1 cấu trúc SV, gồm họtên và điểm của 3 môn học, yêu cầu viết các quá tải:
- Nhập >>, xuất << và bé hơn < (dựa vào điểm trung bình 3 môn).
- Viết chương trình nhập vào 1 danh sách gồm nhiều Sinh viên theo cấu trúc
Mỗi sinh viên nhập vào gồm: dòng đầu là họ và tên, dòng thứ 2 là điểm 3 môn (mỗi môn cách nhau 1 dấu cách).
Yêu cầu tìm sinh viên có điểm trung bình cao nhất và xuất ho tên sinh viên đó ra màn hình, nếu có nhiều SV thì chỉ cần xuất SV có số thứ tự nhỏ nhất (gặp đầu tiên trong danh sách)
(Lưu ý: Họ tên là một chuỗi không có dấu)
Ví dụ:
Input:
Nguyen Van A
1 2 3
Tran Van Teo
4 5 6
Output:
Tran Van Teo
Hướng dẫn nhập chuỗi:
string s;
getline(cin,s);
Khi nhập một số, sau đó nhập 1 chuỗi thì nhớ gọi lệnh sau, trước khi nhập chuỗi: cin.ignore ();
ví dụ:
int a;
cin>>a;
cin.ignore ();
string s;
getline(cin,s);
*/
#include <iostream>
using namespace std;
struct SinhVien {
    string hoten;
    float diem1 , diem2 , diem3 , dtb;
};
void SoSanh(SinhVien arr[] , int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(arr[i].dtb < arr[j].dtb) swap(arr[i] , arr[j]);
        }
    }
}
int main() {
    SinhVien arr[100] , a;
    int x = 0;
    while(getline(cin , a.hoten) && cin >> a.diem1 >> a.diem2 >> a.diem3) {
        a.dtb = (a.diem1 + a.diem2 + a.diem3) / 3;
        arr[x] = a;
        x++;
        cin.ignore();
    }
    SoSanh(arr , x);
    cout << arr[0].hoten;
    return 0;
} 
