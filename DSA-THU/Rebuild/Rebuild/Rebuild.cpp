// 2014-11-22
#include <stdio.h>

const unsigned OneM = 1024*1024;
int preOrder[4000005], postOrder[4000005], inOrder[4000005];
int index = 1;
bool valid = true;
char bufferin[20*OneM];
char bufferout[20*OneM];

int search(int *arr, int e, int lo, int hi) {
	for (int i = lo; i < hi; i++) {
		if (arr[i] == e) return i;
	}
	return -1;
}

void rebuild(int preLo, int preHi, int inLo, int inHi) {
	//printf("preLo=%d preHi=%d inLo=%d inHi=%d\n", preLo, preHi, inLo, inHi);
	if (!valid) return;
	if (preLo >= preHi) return; 
	if (preLo + 1 == preHi) {
		if (preOrder[preLo] == inOrder[inLo]) {
			postOrder[index++] = preOrder[preLo];
		} else {
			valid = false;
		}
		return;
	}
	int rightIndex = search(inOrder, preOrder[preLo], inLo, inHi);
	if (rightIndex == -1) {
		valid = false;
		return; 
	}
	int rightSize = inHi - rightIndex - 1;
	int leftSize = rightIndex - inLo;
	//printf("rightIndex=%d\n", rightIndex);
	//printf("rightChildSize=%d leftChildSize=%d\n", rightSize, leftSize);
	rebuild(preLo+1, preLo+1+leftSize, inLo, rightIndex);
	rebuild(preLo+1+leftSize, preHi, rightIndex+1, inHi);
	postOrder[index++] = preOrder[preLo];
}

int main() {
	setvbuf(stdin, bufferin, _IOFBF, sizeof(bufferin)); 
	setvbuf(stdout, bufferout, _IOFBF, sizeof(bufferout)); 
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &preOrder[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &inOrder[i]);
	}

	rebuild(1, n+1, 1, n+1);
	if (valid) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", postOrder[i]);
		}
		printf("\n");
	} else {
	    printf("-1\n");
	}
	fflush(stdout);   // »º³åÇø
	return 0;
}
