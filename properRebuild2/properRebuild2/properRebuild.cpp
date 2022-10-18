#include <stdio.h>

int preOrder[4000005], postOrder[4000005], inOrder[4000005];
int index = 1;
char buffer[20*4000005];
//int verifyInOrder[10000][100];

int search(int *arr, int e, int lo, int hi) {
	for (int i = lo; i < hi; i++) {
		if (arr[i] == e) return i;
	}
	return -1;
}

void rebuild(int preLo, int preHi, int postLo, int postHi) {
	//if (preLo < 0  || preHi < 0 || postLo < 0 || postHi < 0) return; 
	//printf("preLo=%d preHi=%d postLo=%d postHi=%d\n", preLo, preHi, postLo, postHi);
	if (preLo >= preHi - 1) {
		inOrder[index++] = preOrder[preLo];
		return;
	}
	int rightIndex = search(preOrder, postOrder[postHi-2], preLo, preHi);
	int rightSize = preHi - rightIndex;
	int leftSize = rightIndex - preLo - 1;
	//printf("rightIndex=%d\n", rightIndex);
	//printf("rightChildSize=%d leftChildSize=%d\n", rightSize, leftSize);
	rebuild(preLo+1, rightIndex, postLo, postHi-rightSize-1);
	inOrder[index++] = preOrder[preLo]; // 替换为postOrder[postHi-1]，case 5不能通过，也许是case错了
	rebuild(rightIndex, preHi, postHi-rightSize-1, postHi-1);
}

//bool verify(int t, int n) {
//	for (int i = 0; i < n; i++) {
//		if (verifyInOrder[t][i] != inOrder[i+1]) { 
//			return false;
//		}
//	}
//
//	return true;
//}

int main() {
	setvbuf(stdin, buffer, _IOFBF, sizeof(buffer)); // 缓冲区的作用
	setvbuf(stdout, buffer, _IOFBF, sizeof(buffer)); // 缓冲区的作用
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &preOrder[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &postOrder[i]);
	}

	rebuild(1, n+1, 1, n+1);

	for (int i = 1; i <= n; i++) {
		printf("%d ", inOrder[i]);
	}
	printf("\n");
	fflush(stdout);   // 缓冲区
	return 0;
}
