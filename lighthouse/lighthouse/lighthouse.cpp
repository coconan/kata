// 2013-12-26
// xuetangX.com 数据结构（上） PA1

#include <stdio.h>


int AX[4000010], AY[4000010];
int auxX[4000010], auxY[4000010];
char buffer[40*4000005];

bool lessX(int a, int b) {
	return auxX[a] < AX[b];
}

bool lessY(int a, int b) {
	return auxY[a] < AY[b];
}

long long mergeX(long s, long m, long e) {
	for (long i = s; i < m; i++) {
		auxX[i] = AX[i]; auxY[i] = AY[i];
	}

	long counter = 0;
	long i = s, l = s, r = m;
	while (l < m && r < e) {
		if (auxX[l] < AX[r]) {  // 替换掉函数调用，通过最后一个case, 2014-6-17 3:30, Good Job
			AX[i] = auxX[l]; AY[i] = auxY[l]; l++;
		} else {
			AX[i] = AX[r]; AY[i] = AY[r]; r++;
			counter += m - l;
		}
		i++;
	}

	while (l < m) {
		AX[i] = auxX[l]; AY[i] = auxY[l]; l++; i++;
	}
	/*while (r < e) {
		AX[i] = auxX[r]; AY[i] = auxY[r]; r++; i++;
	}*/

	return counter;
}

long long mergeSortX(long s, long e) {
	if (s + 1 >= e) return 0;
	long mid = (s + e) / 2;
	long l = mergeSortX(s, mid);
	long r = mergeSortX(mid, e);
	return mergeX(s, mid, e) + l + r;
}

long long mergeY(long s, long m, long e) {
	for (long i = s; i < m; i++) {
		auxY[i] = AY[i];
	}

	long counter = 0;
	long i = s, l = s, r = m;
	while (l < m && r < e) {
		if (auxY[l] < AY[r]) {
			AY[i] = auxY[l]; l++;
		} else {
			AY[i] = AY[r]; r++;
			counter += m - l;
		}
		i++;
	}

	while (l < m) {
		AY[i] = auxY[l]; l++; i++;
	}
	/*while (r < e) {
		AY[i] = auxY[r]; r++; i++;
	}*/

	return counter;
}

long long mergeSortY(long s, long e) {
	if (s + 1 >= e) return 0;
	long mid = (s + e) / 2;
	long l = mergeSortY(s, mid);
	long r = mergeSortY(mid, e);
	return mergeY(s, mid, e) + l + r;
}

int main() {
	setvbuf(stdin, buffer, _IOFBF, sizeof(buffer)); // 缓冲区的作用
	setvbuf(stdout, buffer, _IOFBF, sizeof(buffer)); // 缓冲区的作用
	long long n;

	scanf("%lld", &n);

	for (long long i = 0; i < n; i++) {
		scanf("%d %d", &AX[i], &AY[i]);
	}
	

	mergeSortX(0, n);
	long long inversion = mergeSortY(0, n); 
	long long p = n * (n-1) / 2;
	
	//cout << p - inversion << endl;
	printf("%lld\n", p-inversion);
	fflush(stdout);
	return 0;
}