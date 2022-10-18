#include <cstdio>
#include <cstdlib>
#include <cstring>

const int mod = 41023;

struct Node {
	int state;
	int step;
	Node *next;
};

int next = 0;
Node nodepool[41000];

// 用hash实现的map，用41023这个质数作为mod
class Map {
private:
	Node *arr[42000];
public:
	Map() {
		memset(arr, 0, sizeof(arr));
	}
	int get(int state) {
		int idx = state % mod;
		for (Node *node = arr[idx]; node != NULL; node = node->next) {
			if (node->state == state) {
				return node->step;
			}
		}
		return -2;
	}
	void put(int state, int step) {
		int idx = state % mod;
		for (Node *node = arr[idx]; node != NULL; node = node->next) {
			if (node->state == state) {
				node->step = step;
				return;
			}
		}
		//Node *inode = new Node;
		Node *inode = &nodepool[next++];
		inode->state = state;
		inode->step = step;
		inode->next = arr[idx];
		arr[idx] = inode;
	}
};

class Queue {
private:
	int capacity, size;
	int head, tail;
	//int *arr;
	int arr[8192];
public:
	Queue() : capacity(8192), size(0), head(0), tail(0) {
		//arr = new int[capacity];
	}
	void enqueue(int state) {
		/*
		if (size == capacity) {
			int *copy = new int[capacity * 2];
			for (int i = 0; i < size; i++) {
				copy[i] = arr[(tail + i) % capacity];
			}
			delete[] arr;
			arr = copy;
			capacity = capacity * 2;
			tail = 0;
			head = size;
		}
		*/
		arr[head] = state;
		head = (head + 1) % capacity;
		size += 1;
	}
	int dequeue() {
		int state = arr[tail];
		tail = (tail + 1) % capacity;
		size -= 1;
		return state;
	}
	bool empty() {
		return size == 0;
	}
};

int swap(int state) {
	return state % 10000 * 10000 + state / 10000;
}

int shift(int state) {  // 循环右移的逆操作循环左移
	int low4 = state % 10000;
	int high4 = state / 10000;
	return low4 / 1000 + low4 % 1000 * 10 + (high4 / 1000 + high4 % 1000 * 10) * 10000 ;
}

int rotate(int state) { // 中心顺时针旋转的逆操作逆时针旋转
	return state / 10000000 * 10000000 +
		state % 1000000 / 100000 * 1000000 + 
		state % 100 / 10 * 100000 +
		state % 100000 / 1000 * 1000 +
		state % 10000000 / 1000000 * 100 +
		state % 1000 / 100 * 10 +
		state % 10;
}

Map m;
Queue q;
int solved = 0;

void process(int curs, int nexts) {
	short step = m.get(nexts);
	if (step == -1) {
		solved += 1;
		m.put(nexts, m.get(curs) + 1);
	} else if (step == -2) {
		m.put(nexts, m.get(curs) + 1);
	}

	if (step < 0) {
		q.enqueue(nexts);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	//N = 40320;
	int *arr = new int[N];
	
	for (int i = 0; i < N; i++) {
		int state = 0;
		for (int j = 0; j < 4; j++) {
			int digit;
			scanf("%d", &digit);
			state = state * 10 + digit;
		}
		state *= 10000;
		for (int j = 0, p = 1; j < 4; j++, p *= 10) {
			int digit;
			scanf("%d", &digit);
			state += digit * p;
		}
		arr[i] = state;
		m.put(state, -1);
		//printf("%d\n", swap(state));
		//printf("%d\n", shift(state));
		//printf("%d\n", rotate(state));
	}
	
	/*freopen("output.txt", "r", stdin);
	for (int i = 0; i < N; i++) {
		int s, step;
		scanf("%d: %d", &s, &step);
		arr[i] = s;
		m.put(s, -1);
	}
	if (m.get(12348765) == -1) {
		solved++;
	}
	*/
	
	q.enqueue(12348765);
	m.put(12348765, 0);
	while (!q.empty() && solved < N) {
		int curs = q.dequeue();
		//printf("curs=%d\n", curs);
		int nexts = swap(curs);
		process(curs, nexts);
		nexts = shift(curs);
		process(curs, nexts);
		nexts = rotate(curs);
		process(curs, nexts);
	}
	
	//freopen("o.txt", "w", stdout);
	for (int i = 0; i < N; i++) {
		printf("%d\n", m.get(arr[i]));
	}
	
	return 0;
} 