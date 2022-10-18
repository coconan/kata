#include <iostream>
#include <memory.h>
#include <cstdio>

using namespace std;

int A[10005];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, s, a, b;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &s);

		memset(A, 0, sizeof(A));
		scanf("%d", &a);
		int e;
		for (int j = 0; j < a; j++) {
			scanf("%d", &e);
			A[e]++;
		}

		int counter = 0, tmp;
		scanf("%d", &b);
		for (int j = 0; j < b; j++) {
			scanf("%d", &tmp);
			if (s-tmp >= 0) {
				counter += A[s-tmp];
			}
		}

		cout << counter << endl;
	}

	return 0;
}