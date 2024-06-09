/*
Cho một DSLK đơn. Mỗi phần tử info là một ký tự ('A'..'Z') và liên kết chỉ đến phần tử kế.
Giả sử ta đã có một danh sách đã cho có thứ tự tăng dần (không có phần tử trùng nhau). Viết chương trình bổ sung vào danh sách này sao cho cho danh sách sẽ chứa đầy đủ các ký tự từ 'A' đến 'Z'.
Dữ liệu đầu vào:
Dòng 1:  chứa số n là số lượng phần tử ban đầu của danh sách
Dòng 2:  chứa n ký tự, mỗi ký tự cách nhau 1 khoảng trắng
Dữ liệu đầu ra: 2 dòng
Dòng 1: dãy ký tự ban đầu (không có chứa khoảng trắng)
Dòng 2: dãy ký tự sau khi thêm đầy đủ ký tự từ ‘A’ đến ‘Z’ (không chứa khoảng trắng)
Ví dụ:
Input:
6
D F H K M Q
Output:
DFHKMQ
ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
#include <iostream>
using namespace std;
struct node {
	char data;
	node* link;
};
struct list {
	node* first;
	node* last;
};
void create_null(list &ds) {
	ds.first = ds.last = NULL;
}
node* get_node(char x) {
	node* new_element = new node;
	if (new_element == NULL)
		return NULL;
	new_element->data = x;
	new_element->link = NULL;
	return new_element;
}
void insert_last(list & ds, char x) {
	node* new_element = get_node(x);
	if (ds.first == NULL)
		ds.first = ds.last = get_node(x);
	else
	{
		ds.last->link = new_element;
		ds.last = new_element;
	}
}
void output(list ds) {
	node* p = ds.first;
	while (p != NULL)
	{
		cout << p->data;
		p = p->link;
	}
}

void outFull(list &ds) {
	node* p = ds.first;
	while (p->link != NULL) {
		cout << p->data;
		int a = (int)p->data;
		p = p->link;
		int b = (int)p->data;
		while (a<b - 1)
		{
			a = a + 1;
			char c = (char)a;
			cout << c;
		}
	}
	cout << p->data;
}
void First(list &ds,char x) {
		node* new_element = new node;
		new_element=get_node(x);
		new_element->link = ds.first;
		ds.first = new_element;
}
void Last(list &ds,char x) {
		node* new_element = new node;
		new_element = get_node(x);
		ds.last->link = new_element;
		ds.last = new_element;
}
int main() {
	int n;
	cin >> n;
	char x;
	list ds;
	create_null(ds);
	for (int i = 0; i<n; i++) {
		cin >> x;
		insert_last(ds, x);
	}
	output(ds);
	cout << endl;
	if (ds.first->data != 'A') First(ds, 'A');
	if (ds.last->data != 'Z') Last(ds, 'Z');
	outFull(ds);
	return 0;
}
