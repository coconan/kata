#include <stdio.h>

struct Interviewee {
	Interviewee* next;
	Interviewee* prev;
	int id;
	Interviewee(): next(NULL), prev(NULL), id(-1) {}
};

Interviewee A[1005];

int main() {
    int n, m;
	scanf("%d%d", &n, &m);

	Interviewee* cur = &A[0];
	scanf("%d", &((*cur).id));
	cur->prev = cur;
	cur->next = cur;
	for (int i = 1; i < n; ++i) {
	    for (int j = 1; j < m; ++j) {
		    cur = cur->prev;
		}
		scanf("%d", &A[i].id);
		A[i].prev = cur->prev;
		A[i].next = cur;
		cur->prev->next = &A[i];
		cur->prev = &A[i];
		cur = &A[i];
	}
	for (int i = 0; i < n; ++i) {
	    printf("%d ", cur->id);
		cur = cur->next;
	}

	return 0;
}