// 2013-12-7
// xuetangX.com 数据结构 PA2-1

#include <iostream>
#include <cstdio>

using namespace std;

char seq[5*3200000];

class MyStack {
private:
	int * _arr;
    int size;
	int cur;
public:
	MyStack(int m) {
		_arr = new int[m];
		size = m;
		cur = 0;
	}

	void push(int v) {
		_arr[cur++] = v;
	}

	int pop() {
		return _arr[--cur]; 
	}

	int get() {
		return _arr[cur-1];
	}

	bool full() {
		return size == cur; 
	}

	bool empty() {
		return cur == 0;
	}

	~MyStack() {
		delete [] _arr;
	}
};

int main() {
	int m, n, cur = 1;
	cin >> n >> m;

	int * arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	MyStack s = MyStack(m);
	bool flag = true; char * str = seq;
	for (int i = 0, j = 0; i < n && flag; i++) {
		while (arr[i] >= cur && !s.full()) {
			s.push(cur++);
			sprintf(str, "push\n");
			str += 5;
		}
		if (s.get() == arr[i]) {
			s.pop();
			sprintf(str, "pop\n");
			str += 4;
		}
		else flag = false;
	}
	sprintf(str, "\0");

	if (flag) {
		printf("%s", seq);
	} else {
		cout << "No" << endl;
	}
	delete [] arr;
	return 0;
}