// 2015-11-23 18:50

#include <stdio.h>
#include <cmath>

int M[401][401];
int FS[401][401];

void print() {
	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= 16; j++) {
			printf("%2d ", M[i][j]);
		}
		printf("\n");
	}
	printf("-------\n");
}

void println(int nth) {
	for (int i = 1; i <= 400; i++) {
		printf("%3i: %2d, ", i, M[nth][i]);
		if (i % 10 == 0) {
			printf("\n");
		}
	}
	printf("--------\n");
}

int main() {
	int N, P, K;
	scanf("%d %d %d", &N, &K, &P);
	//printf("%d %d %d\n", N, K, P);
	for (int factor = 1; factor <= 20; factor++) {
		int interval = pow((double) factor, P);
		if (interval > 400) { break; }
		M[1][interval] = factor;
		FS[1][interval] = factor;
		for (int order = 1; order <= 400-1; order++) {
			for (int sum = 1; sum <= 400; sum++) {
				if (M[order][sum] != 0) {
					int fs = FS[order][sum] + factor;
					int nsum = sum + interval;
					if (nsum > 400) { break; }
					if (FS[order+1][nsum] <= fs) {
						M[order+1][nsum] = factor;
						FS[order+1][nsum] = fs;
					}
				}
			}
		}
	}

	//for (int nth = 1; nth <= 5; nth++) {
	//	println(nth);
	//}
	
	if (M[K][N] != 0) {
		printf("%d = %d^%d", N, M[K][N], P);
		for (int nth = K-1, sum = N - pow((double) M[K][N], P); nth >= 1; nth--) {
			printf(" + %d^%d", M[nth][sum], P);
			sum = sum - pow((double) M[nth][sum], P);
		}
	} else {
		printf("Impossible");
	}
	return 0;
}

// 2015-11-23 20:00