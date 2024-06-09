/*
Cho một DSLK đơn. Mỗi phần tử info là một ký tự ('A'..'Z') và liên kết chỉ đến phần tử kế.
Tạo một danh sách liên kết đơn, chứa các ký tự đầu vào
Viết chương trình loại khỏi danh sách đã cho các phần tử vi phạm điều kiện tăng dần của danh sách. Biết rằng phần tử đầu tiên được giữ lại trong danh sách. (không có phần tử trùng nhau).
Dữ liệu đầu vào: chứa 1 dãy ký tự, mỗi ký tự cách nhau 1 khoảng trắng
Dữ liệu đầu ra: chứa 1 dòng gồm các phần tử của danh sách thỏa điều kiện (mỗi ký tự cách nhau 1 khoảng trắng)
Ví dụ:
Input:
D F H G K M A B Q
Output:
D F H K M Q
*/
#include <iostream>
using namespace std ;
struct Node {
    char data ;
    Node * next ;
};
typedef struct Node *node ;
node create(char k) {
    node temp =  new Node ;
    temp -> data = k ;
    temp -> next = nullptr ;
    return temp ;
}
void  chen (node& head , char k){
    if(head== nullptr) {
        head = create(k);
    }
    else {
        node temp = head ;
        while (temp->next != nullptr) {
            temp = temp ->next ;
        }
        temp -> next = create (k);
    }
}
void xuly(node& head) {
    node current = head ;
    while (current!=nullptr && current -> next !=nullptr) {
        if (current->data > current ->next ->data) {
            node temp = current -> next ;
            current ->next = current -> next -> next ;
        }
        else current = current -> next ;
    }
}
void xuat(node& head) {
    node temp = head ;
    while(temp != nullptr) {
        cout<<temp -> data <<" ";
        temp = temp -> next ;
    }
}
int main() {
    node head = nullptr ;
    char c ;
    while(cin >> c){
        chen (head, c);
    }
    xuly(head);
    xuat(head);
    return 0 ;
}
