/*
Bài toán Josephus là một trong những bài toán rất nổi tiếng, ra đời từ rất sớm, khoảng năm 370 sau công nguyên bởi Aurelius Ambrosius, là một Tiến sĩ Hội thánh sống vào khoảng năm 340 đến 397 sau công nguyên. 
Ông cũng được xem là vị thánh bảo trợ của thành phố Milan, nước Ý.
Bài toán đưa ra bởiAmbrôsiô như sau: Titus Flavius Vespasianus là một vị tướng lãnh đạo quân đội tài năng, người về sau đã trở thành hoàng đế La Mã (từ năm 69 đến năm 79), đã cùng với quân đội dưới sự chỉ huy của ông
ta dập tắt cuộc nổi loạn của người Do Thái chống lại đế quốc La Mã. Trong cuộc vây hãm Yodfat, Vespasian đã bắt được Flavius Josephus, một nhà lãnh đạo kháng chiến của người Do Thái.
Sau khi bắt được các tù nhân Do Thái, người La Mã quyết định xử tử tù nhân bằng cách cho toàn bộ xếp thành vòng tròn và bắt đầu đếm từ một, cứ người nào đến 3 là bị giết cho đến khi chỉ còn lại 1 người.
Trước yêu cầu khắc nghiệt như trên, Josephus đã nhanh chóng tìm ra vị trí để mình và người bạn thân không bị giết. Hỏi rằng ông đã chọn vị trí nào cho ông?
Bài toán cần giải:
Cho N người đứng thành vòng tròn và số M (ở đây cho dễ ta sẽ giả sử M < N). Bắt đầu từ người số 1, anh ta sẽ đếm 1, người bên trái anh ta đếm 2, ... cho tới người đếm M sẽ tự động bước ra khỏi vòng tròn đó 
và người bên trái anh ta tiếp tục đếm lại 1 ... Cứ thế cho tới khi vòng không còn người nào. Xuất thứ tự người ra khỏi vòng tròn.
Ví dụ: với N = 9, M=7 thì thứ tự sẽ là: 7  5  4  6  9  3  8  1 2
*/
#include <iostream>
#include <list>
using namespace std;
void josephus(int n, int m) {
    // Khởi tạo một danh sách liên kết chứa số thứ tự của mỗi người
    list<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    // Khởi đầu điểm đếm từ 0
    auto it = people.begin();

    while (people.size() > 1) {
        // Di chuyển vị trí đến người cần loại bỏ
        for (int i = 0; i < m - 1; ++i) {
            ++it;
            if (it == people.end()) {
                it = people.begin();
            }
        }
        // Loại bỏ người đó khỏi vòng tròn
        cout << *it << " ";
        it = people.erase(it);

        if (it == people.end()) {
            it = people.begin();
        }
    }
    // In ra người cuối cùng còn lại trong vòng tròn
    cout << *people.begin() << endl;
}
int main() {
    int n , m;
    cin >> n >> m;
    josephus(n, m);
    return 0;
}
