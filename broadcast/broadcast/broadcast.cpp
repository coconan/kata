// 2013-12-24 (23:52 AC)
// xuetangX.com 数据结构 PA3-1

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Queue {
private:
	int size;
	int head, tail;
	int * arr;

public:
	Queue(int n) {
		arr = new int[n+1];
		head = tail = 0;
		size = n+1;
	}

	void enqueue(int e) {
		arr[tail] = e;
		tail = (tail + 1) % size;
	}

	int dequeue() {
		int e = arr[head];
		head = (head + 1) % size;
		return e;
	}

	bool empty() {
		return head == tail;
	}

	~Queue() {
		delete arr;
	}
};

typedef struct Edge {
	int vertex;
	struct Edge * next;
} Edge;

bool deploy(Edge ** graph, int n) {
	int * deployment = new int[n];
	memset(deployment, 0, sizeof(int) * n);
	Queue q = Queue(n);
	for (int i = 0; i < n; i++) {
		if (deployment[i] == 0) {
			q.enqueue(i); deployment[i] = 1;
			while (!q.empty()) {
				int v = q.dequeue();
				for (Edge * e = graph[v]; e != NULL; e = e->next) {
					int j = e->vertex;
					if (deployment[j] == 0) {
						q.enqueue(j); deployment[j] = -deployment[v];
					} else if (deployment[j] == deployment[v]) {
						return false;
					}
				}
			}
		}
	}

	delete deployment;
	return true;
}

int main() {
    short n, m;

	cin >> n >> m;
	
	Edge ** graph = new Edge*[n];
	for (int i = 0; i < n; i++) {
		graph[i] = NULL;
	}
	
	int u, v; Edge * temp;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);  // cin >> u >> v;
		u = u - 1; v = v - 1;   // 不写这行，delete graph; 出现 run time error
		temp = new Edge;
		temp->vertex = v; temp->next = graph[u]; graph[u] = temp;
		temp = new Edge;
		temp->vertex = u; temp->next = graph[v]; graph[v] = temp;
	}
	
	
	if (deploy(graph, n)) { cout << 1 << endl; }
	else { cout << -1 << endl; }
	
	Edge * cur, * next;
	for (int i = 0; i < n; i++) {
		cur = graph[i];
		while (cur != NULL) {
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
	delete [] graph; // run time error, but ok on OJ, 原因已找到
	
	return 0;
}