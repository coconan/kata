// 2014-11-22
#include <stdio.h>

char bufferin[4000000];
char bufferout[4000000];

inline int MIN(int a, int b) {
	return a > b ? b : a;
}

class Stack {
public:
	//注意：你不能添加更多的public函数或变量,如有需要可添加析构函数
	Stack(): size(1000000), cur(0) {
		arr = new int[1000000];
	}

	~Stack() { delete[] arr; }

	inline bool empty() { return cur == 0; }

	inline void push(int value) { 
		arr[cur++] = value;
	}

	inline int pop() { return arr[--cur]; }

	inline int top() { return arr[cur-1]; }

	void print() {
		for (int i = 0; i < cur; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	
private:
	//此处可以扩展
	int size;
	int cur;
	int* arr;
};

class Queap
{
public:
	Queap() {}
	void enqueap(int value) {
		//printf("value: %d", value);
		in.push(value);
		//printf("in.top: %d", in.top());
		if (pin.empty()) {
			pin.push(value);
		} else {
			pin.push(MIN(pin.top(), value));
		}
		//printf("in: ");
		//in.print();
		//printf("pin: ");
		//pin.print();
	}

	int dequeap() {
		if (pout.empty()) {
	        out.push(in.top());
			pout.push(in.top());
			in.pop();
			pin.pop();
			while (!pin.empty()) {
				int value = in.top();
				out.push(value);
				pout.push(MIN(pout.top(), value));
				in.pop();
				pin.pop();
			}
		}
		//printf("out: ");
		//out.print();
		//printf("pout: ");
		//pout.print();
		pout.pop();
		return out.pop();
	}

	int min() {
		if (pout.empty()) {
			return pin.top();
		} else if (pin.empty()) {
			return pout.top();
		} else {
			return MIN(pout.top(), pin.top());
		}
	}
private:
	Stack in;
	Stack out;
	Stack pin;
	Stack pout;
};

int main() {
	setvbuf(stdin, bufferin, _IOFBF, sizeof(bufferin));
	setvbuf(stdout, bufferout, _IOFBF, sizeof(bufferout));
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	Queap q;
	for (int i = 0; i < n; ++i) {
		char op[10];
	    scanf("%s", &op);
		int value;
		switch (op[0]) {
		case 'E': 
			scanf("%d", &value);
			q.enqueap(value);
			break;
		case 'D':
			printf("%d\n", q.dequeap());
			break;
		case 'M':
			printf("%d\n", q.min());
			break;
		}
	}
    return 0;
}