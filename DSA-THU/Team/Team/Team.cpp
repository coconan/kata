#include <stdio.h>

int A[500005], B[500005], C[500005];
bool isAllocated[500005];
char inbuffer[4*1000000];
char outbuffer[4*1000000];

int main() {
	setvbuf(stdin, inbuffer, _IOFBF, sizeof(inbuffer));
	setvbuf(stdout, outbuffer, _IOFBF, sizeof(outbuffer));

    int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
	    scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; ++i) {
	    scanf("%d", &B[i]);
	}
	for (int i = 0; i < n; ++i) {
	    scanf("%d", &C[i]);
	}

	scanf("%d", &k);
	int i=0, j=0, l=0;
	while (!isAllocated[k]) {
		while (isAllocated[A[i]]) i++;
		isAllocated[A[i]] = true;
		if (A[i] == k) {
			printf("A\n");
			break;
		}
		while (isAllocated[B[j]]) j++;
		isAllocated[B[j]] = true;
		if (B[j] == k) {
			printf("B\n");
			break;
		}
		while (isAllocated[C[l]]) l++;
		isAllocated[C[l]] = true;
		if (C[l] == k) {
			printf("C\n");
			break;
		}
	}
	fflush(stdout);
	return 0;
}