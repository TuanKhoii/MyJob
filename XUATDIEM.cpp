/*
Yêu cầu 1:
Xây dựng cấu trúc Điểm gồm hoành độ và tung độ là 2 số nguyên,yêu cầu viết các quá tải
·    >> nhập điểm
·    << xuất điểm – cách xuất theo dạng (x,y)
·    Viết quá tải == (kiểm tra 2 điểm có trùng nhau không? )
·    Viết quá tải < (so sánh theo kiểu “từ điển” - so sánh theo thứ tự ưu tiên hoành độ -> tung độ)
·    Quá tải toán tử + cộng 2 điểm trả về 1 Điểm có tung độ bằng tổng 2 tung độ và hoành độ bằng tổng 2 hoành độ.
Xây dựng cấu trúc Mảng 1 chiều dùng để lưu 1 dãy Điểm thuộc cấu trúc trên, yêu cầu viết các quá tải: >>, <<, +
Yêu cầu 2:
Viết chương trình nhập vào 1 dãy điểm, yêu cầu tìm điểm “lớn nhất” và xuất tổng điểm ra màn hình.
Ví dụ:
Input	
1 2
3 4
5 6
Output
(5,6)
(9,12)
*/
#include <iostream>

using namespace std;

// 1. operator>>
// 2. operator<<
// 3. operator==
// 4. operator<
// 5. operator+

struct Point
{
    int x, y;
};

void Xuat_diem_lon_nhat (Point a[], int n) {
    int max1 = a[0].x;
    int max2 = a[0].y;
    for (int j = 1; j < n; j++) {
        if (a[j].x > max1) {
            max1 = a[j].x;
            max2 = a[j].y;
        } else if (a[j].x == max1) {
            if (a[j].y > max2) {
                max1 = a[j].x;
                max2 = a[j].y;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        if (a[j].x == max1 && a[j].y == max2) {
            cout << "(" << a[j].x << "," << a[j].y << ")";
            break;
        }
    }
}

int main () {
    Point arr[1000];
    int i = 0, sum_x = 0, sum_y = 0;
    while (cin >> arr[i].x) {
        sum_x += arr[i].x;
        cin >> arr[i].y;
        sum_y += arr[i].y;
        i++;
    }
    Xuat_diem_lon_nhat (arr, i);
    cout << endl << "(" << sum_x << "," << sum_y << ")";
    return 0;
}
