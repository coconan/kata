// 2012-12-27
// xuetangX.com 数据结构（上） PA1-2

#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Node {
	int ID;
	struct Node * pre, * next;
} Node;

int main() {
	int n, m;
	cin >> n >> m;

	int ID; cin >> ID;
	Node * cur = new Node;
	cur->ID = ID; cur->pre = cur->next = cur;
    
	int counter; Node * temp;
	for (int i = 1; i < n; i++) {
		cin >> ID;
		temp = new Node; temp->ID = ID;
		counter = m;
		while (--counter > 0) {
			cur = cur->next; 
		}
		temp->next = cur->next; temp->pre = cur;
		cur->next->pre = temp; cur->next = temp;
		cur = temp;
	}

	cout << cur->ID; cur = cur->pre;
	for (int i = 1; i < n; i++) {
		cout << " " << cur->ID;
		cur = cur->pre;
	}

	for (int i = 0; i < n; i++) {
		temp = cur->next;
		delete cur;
		cur = temp;
	}

	return 0;
}