// 2013-12-25 (12-26 13:00 AC)
// xuetangX.com 数据结构（上） PA3-2

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef struct E {
	int node;
	struct E * next;
} Edge;

bool visited[100005];
int length[100005];

void DFS(Edge ** graph, int s) {
	length[s] = 1;
	for (Edge * e = graph[s]; e != NULL; e = e->next) {
		int i = e->node;
		if (!visited[i]) {
			DFS(graph, i); 
			visited[i] = true;
		}
		if (length[i] + 1 > length[s]) {
			length[s] = length[i] + 1;
		}
	}
}

void dfs(Edge ** graph, int n) {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) { 
			DFS(graph, i); visited[i] = true;
		}
	}
}


int main() {
	int n, m;

	cin >> n >> m;
	
	Edge ** graph = new Edge*[n];
	for (int i = 0; i < n; i++) {
		graph[i] = NULL;
	}

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	
	int u, v;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);  // cin比scanf耗时更严重
		Edge * e = new Edge;
		e->node = v - 1; e->next = graph[u-1];
		graph[u-1] = e;
		
	}
	
	dfs(graph, n);
	
	int maxLength = 0;
	for (int i = 0; i < n; i++) {
		if (maxLength < length[i]) {
			maxLength = length[i];
		}
	}
	cout << maxLength << endl;

	for (int i = 0; i < n; i++) {
		Edge * cur = graph[i], * temp;
		while (cur != NULL) {
			temp = cur->next;
			delete cur;
			cur = temp;
		}
	}
	delete graph;
	
	return 0;
}