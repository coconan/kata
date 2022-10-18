#include <stdio.h>

int preOrder[4000005], postOrder[4000005], inverted[4000005], inOrder[4000005];
char buffer[sizeof(int)*4000005];
int verifyInOrder[10000][100];
int index = 1;

//void rebuild(int preLo, int preHi, int postLo, int postHi) {
//	//if (index > 4) return;
//	//printf("preLo=%d preHi=%d postLo=%d postHi=%d\n", preLo, preHi, postLo, postHi);
//	if (preHi-preLo  < 2) {
//		inOrder[index++] = preOrder[preLo];
//		return;
//	}
//	//int root = postOrder[postHi-1];
//	int rightIndex = inverted[postOrder[postHi-2]];
//	int rightChildSize = preHi-rightIndex;
//	int leftChildSize = rightIndex-1-preLo;
//	//printf("rightChildSize=%d leftChildSize=%d\n", rightChildSize, leftChildSize);
//	rebuild(preLo+1, rightIndex, postLo, postLo+leftChildSize);
//	inOrder[index++] = preOrder[preLo];
//	rebuild(rightIndex, preHi, postHi-1-rightChildSize, postHi-1);
//}

void rebuild(int preLo, int preHi, int postLo, int postHi) {
	//if (index > 4) return;
	//printf("preLo=%d preHi=%d postLo=%d postHi=%d\n", preLo, preHi, postLo, postHi);
	if (preHi-preLo == 1) {
		inOrder[index++] = preOrder[preLo];
		return;
	}
	// int root = postOrder[postHi-1]; 也许是测试案例错了
	int rightIndex = inverted[postOrder[postHi-2]];
	int rightChildSize = preHi-rightIndex;
	int leftChildSize = rightIndex-1-preLo;
	//printf("rightChildSize=%d leftChildSize=%d\n", rightChildSize, leftChildSize);
	rebuild(preLo+1, rightIndex, postLo, postLo+leftChildSize);
	inOrder[index++] = preOrder[preLo];
	rebuild(rightIndex, preHi, postHi-1-rightChildSize, postHi-1);
}

bool verify(int t, int n) {
	for (int i = 0; i < n; i++) {
		if (verifyInOrder[t][i] != inOrder[i+1]) { 
			return false;
		}
	}

	return true;
}

int parseInt() {
	int number = 0, i = 0; 
	while (buffer[i] != '\0') {
		number = number*10 + buffer[i] - '0';
		i++;
	}
	
	return number;
}

void parse(int *arr, bool inv) {
	int number = 0, i = 0, counter = 1;
	while (buffer[i] != '\0') {
		if (buffer[i] != ' ') {
			number = number * 10 + buffer[i] - '0';
		} else {
			if (inv) {
				inverted[number] = counter;
			}
			arr[counter++] = number;
			number = 0;	
		}
		i++;
	}
	arr[counter] = number;
}

int main() {
	freopen("out.txt", "r", stdin);
	for (int t = 0; t < 10000; t++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &verifyInOrder[t][i]);
		}
	}
	fclose(stdin);

	freopen("in.txt", "r", stdin);
	for (int t = 0; t < 10000; t++) {
		index = 1;
		gets(buffer);
		int n = parseInt();

		gets(buffer);
		parse(preOrder, true);
		/*printf("preOrder: ");
		for (int i = 1; i <= n; i++) {
			printf("%d ", preOrder[i]);
		}
		printf("\n");*/
		gets(buffer);
		parse(postOrder, false);
		/*printf("postOrder: ");
		for (int i = 1; i <= n; i++) {
			printf("%d ", postOrder[i]);
		}
		printf("\n");*/

		/*int tmp;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			preOrder[i] = tmp;
			inverted[tmp] = i;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d", &postOrder[i]);
			
		}*/

	
		rebuild(1, n+1, 1, n+1);
		
		for (int i = 1; i <= n; i++) {
			printf("%d ", inOrder[i]);
		}
		printf("\n");
	
		if (!verify(t, n)) {
			printf("inOrder: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", inOrder[i+1]);
			}
			printf("\n");
			printf("verifyInOrder: ");
			for (int i = 0; i < n; i++) {
				printf("%d ", verifyInOrder[t][i]);
			}
			printf("\n");
		}

	}
	fclose(stdin);
	return 0;
}