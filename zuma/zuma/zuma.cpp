#include <iostream>
#include <cstdio>

using namespace std;

typedef struct Node {
	char c;
	Node* next;
	Node* prev;
	Node(char _c): c(_c){}
};

int size = 0, cur = 0;
char seq[100005];
char buffer[200000000];   // 2014-6-17 2:32 100% Good Job

Node* find(Node* head, Node *tail, int index) {
	Node *cur;
	if (index < size / 2) {
		cur = head;
		while (index > 0) {
			cur = cur->next;
			index--;
		}
	} else {
		cur = tail->prev;
		int i = 0;
		while (i+index < size) {
			cur = cur->prev;
			i++;
		}
	}
	
	return cur;
}

bool isErasible(Node* cur) {
	return (cur->next && cur->prev && cur->next->c == cur->c && cur->prev->c == cur->c) 
		|| (cur->next && cur->next->next && cur->next->c == cur->c && cur->next->next->c == cur->c)
		|| (cur->prev && cur->prev->prev && cur->prev->c == cur->c && cur->prev->prev->c == cur->c);
}

void erase(Node* cur, Node *head, Node *tail) {
	Node *lo = cur, *hi = cur;
	while (lo->c == cur->c) {
		lo = lo->prev;
	}

	while (hi->c == cur->c) {
		hi = hi->next;
	}
	
	Node *node = lo->next;
	while (node != hi) {
		Node *temp = node;
		node = node->next;
		delete temp;
		size--;
	}

	lo->next = hi;
	hi->prev = lo;

	if (lo != head && hi != tail && hi->c == lo->c && isErasible(lo)) {
		erase(lo, head, tail);
	}
}

void print(const Node *head, const Node *tail) {
	if (head->next == tail) {
		sprintf(buffer+cur, "-\n");
		cur = cur + 2;
	} else {
		Node* node = head->next;
		int i = 0;
		while (node != tail) {
			seq[i++] = node->c;
			node = node->next;
		}
		seq[i] = '\n';
		sprintf(buffer + cur, "%s", seq);
		cur = cur + i + 1;
	}
}



int main() {
	Node* head = new Node('\0');
	Node *tail = new Node('\0');
	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;

	gets(seq);

	int i = 0;
	while (seq[i] != '\0') {
		Node* node = new Node(seq[i]);
		tail->prev->next = node;
		node->prev = tail->prev;
		node->next = tail;
		tail->prev = node;
		i++; size++;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int index;
		char c;
		scanf("%d %c", &index, &c);
		Node *cur = find(head, tail, index);
		Node *node = new Node(c);
		cur->next->prev = node;
		node->next = cur->next;
		cur->next = node;
		node->prev = cur;
		size++;
		if (isErasible(node)) {
			erase(node, head, tail);
		}
		print(head, tail);
	}
	buffer[cur] = '\0';
	printf("%s", buffer);
	return 0;
}