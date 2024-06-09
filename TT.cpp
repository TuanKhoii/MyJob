/*
Một người mẹ muốn chia đều cho hai đứa con số tiền trong túi của mình. Khi rút tiền trong túi ra, bà thấy có n đồng tiền (n ≤ 20) với các loại mệnh giá khác nhau. 
Bà cảm thấy lo lắng chia cho hai người con có được không.
Yêu cầu: Bạn hãy giúp bà ấy chia tiền cho hai người con. Nếu chia được thì nêu rõ số cách chia.
Dữ liệu vào: Gồm 02 dòng:
+Dòng đầu ghi số n là số đồng tiền (1≤  n ≤ 20)
+Dòng sau ghi mệnh giá các đồng tiền là các số nguyên dương có cùng đơn vị tính (0≤t[i]≤500).
Dữ liệu ra: Dòng thứ nhất ghi số cách chia, nếu không thể chia được thì ghi “ khong chia duoc”. Các dòng sau trong trường hợp chia được
Mỗi dòng là 01 cách chia với quy ước người thứ nhất có tên là “A”, người thứ hai có tên là “B” và phải tương ứng với thứ tự của các đồng tiền mà bà đưa ra. 
Ví dụ
input
6
1 2 2 5 10 10
output
4
A A A B A B
A A A B B A
B B B A A B
B B B A B A
input
6
1 2 2 5 10 1
output
khong chia duoc
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> coins;
vector<char> solution;
vector<string> arr;
int countWays = 0;
void Print() {
    for(int i = 0; i < countWays; ++i) {
        cout << arr[i] << endl;
    }
}
void splitCoins(int idx, int sumA, int sumB) {
    if (idx == n) {
        if (sumA == sumB) {
            string temp = "";
            for (char ch : solution) {
                temp += ch;
                temp += ' ';
            }
            arr.push_back(temp);
            countWays++;
        }
        return;
    }
    solution[idx] = 'A';
    splitCoins(idx + 1, sumA + coins[idx], sumB);
    solution[idx] = 'B';
    splitCoins(idx + 1, sumA, sumB + coins[idx]);
}
int main() {
    cin >> n;
    coins.resize(n);
    solution.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    splitCoins(0, 0, 0);
    if (countWays == 0) {
        cout << "khong chia duoc" << endl;
    } 
    else {
        cout << countWays << endl;
        Print();
    }
    return 0;
}
