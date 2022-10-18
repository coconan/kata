#include <stdio.h>

#define PARENT(i) ((i-1)>>1)
#define INHEAP(n, i) (((-1) < (i)) && (i) < (n))
#define LCHILD(i) (1 + ((i) << 1))
#define RCHILD(i) ((1 + (i)) << 1)
#define LCHILDVALID(n, i) INHEAP(n, LCHILD(i))
#define RCHILDVALID(n, i) INHEAP(n, RCHILD(i))

unsigned priority[4000005];
char name[4000005][10];
int index[40000005], n = 0, m = 0;
char buffer[8000000];

void percolateUp(int i) {
	int v = index[i];
	while (i > 0) {
		int j = PARENT(i);
		if (priority[v] > priority[index[j]]) break;
		else if (priority[v] == priority[index[j]]) {
			char *s1 = name[v], *s2 = name[index[j]];
			for (;*s1 == *s2; s1++, s2++);
			if (*s1 > *s2) {  // 题目确定不会重名
				break;
			}
		}
		index[i] = index[j]; i = j;
	}
	index[i] = v;
}

void percolateDown(int i) {
	int v = index[i], proper = LCHILD(i);
	while (INHEAP(n, proper)) {
		if (RCHILDVALID(n, i)) {
			int rc = RCHILD(i);
			if (priority[index[proper]] > priority[index[rc]]) {
				proper = rc;
			} else if (priority[index[proper]] == priority[index[rc]]) {
				char *s1 = name[index[proper]], *s2 = name[index[rc]];
				for ( ; *s1 == *s2; s1++, s2++);
				if (*s1 > *s2) {
					proper = rc;
				}
			}
		}
		if (priority[index[proper]] > priority[v]) {
			break;
		} else if (priority[index[proper]] == priority[v]) {
			char *s1 = name[index[proper]], *s2 = name[v];
			for ( ; *s1 == *s2; s1++, s2++);
			if (*s1 > *s2) {
				break;
			}
		}
		index[i] = index[proper]; i = proper; proper = LCHILD(i);
	}
	index[i] = v;
}

void deleteMin() {
	index[0] = index[--n];
	percolateDown(0);
}

void heapify() {
	for (int i = PARENT(n-1); INHEAP(n, i); i--) {
		percolateDown(i);
	}
}

int main() {
	setvbuf(stdin, buffer, _IOFBF, sizeof(buffer));
	setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &priority[i]);
		scanf("%s", name[i]);
		index[i] = i;
	}
	heapify();
	for (int i = 0; i < m && n > 0; i++) {
		printf("%s\n", name[index[0]]);
		if (priority[index[0]]>>31 == 1) {
			deleteMin();
		} else {
			priority[index[0]] *= 2;
			percolateDown(0);
		}
	}
	fflush(stdout);
	return 0;
}