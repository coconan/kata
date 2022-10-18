// 2014-11-22

#include <iostream>
#include <cstdio>

using namespace std;

char buffer[3200000];

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

	inline void push(int v) {
		_arr[cur++] = v;
	}

	inline int pop() {
		return _arr[--cur]; 
	}

	inline int get() {
		return _arr[cur-1];
	}

	inline bool full() {
		return size == cur; 
	}

	inline bool empty() {
		return cur == 0;
	}

	~MyStack() {
		delete [] _arr;
	}
};

int main() {
    setvbuf(stdin, buffer, _IOFBF, sizeof(buffer));
	int m, n, cur = 1;
	scanf("%d%d", &n, &m);

	int * arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &(arr[i]));
	}
	
	MyStack s = MyStack(m);
	bool flag = true; 
	for (int i = 0, j = 0; i < n && flag; i++) {
		while (arr[i] >= cur && !s.full()) {
			s.push(cur++);
		}
		if (s.get() == arr[i]) {
			s.pop();
		}
		else flag = false;
	}

	if (flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	delete [] arr;
	return 0;
}