#include <stdio.h>

// 2016-05-24 16:30 自己解析输入数据可以大幅减少程序的耗时，估计那些排在第一的人用的也是这种方法
long long coords[50000];
long long partialSum[50000];
//char inbuffer[1<<23];   // buffer for setvbuf, for solution 1 and 2

// parse int manually
char *buffer = new char[1<<23];
int i = 0;
int parseint() {
	int n = 0;
	while (buffer[i] < '0' || '9' < buffer[i]) {
		i++;
	}
	while ('0' <= buffer[i] && buffer[i] <= '9') {
		n = n * 10 + buffer[i] - '0';
		i++;
	}
	return n;
}


int bi_search(int lo, int hi, long long v) {
	while (lo < hi) {
		/*for (int i = lo; i < hi; ++i) {
			printf("%d: %lld, ", i, partialSum[i]);
		}
		printf("lo=%d hi=%d v=%lld\n", lo, hi, v);*/
		int mi = lo + (hi - lo) / 2;
	    if (v > partialSum[mi]) {
			lo = mi + 1;
		} else {
			hi = mi;
		}
	}
	return lo;
}

int main() {
	// solution 1: using bi_sect
	/*
	setvbuf(stdin, inbuffer, _IOFBF, sizeof(inbuffer));
    int n;
	scanf("%d", &n);
	int ubound = 0;
	for (int i = 0; i < n; ++i) {
	    int x, w;
		scanf("%d%d", &x, &w);
		coords[x] += w;
		if (ubound < x) { ubound = x; }
	}
	for (int i = 0; i <= ubound; ++i) {
	    printf("%d: %lld, ", i, coords[i]);
	}
	printf("\n");
	partialSum[0] = coords[0];
	for (int i = 1; i <= ubound; ++i) {
	    partialSum[i] = partialSum[i-1] + coords[i];
	}
	
	int c = bi_search(0, ubound+1, (partialSum[ubound]+1)/2);
	*/

	// solution 2: finding mean
	/*
	setvbuf(stdin, inbuffer, _IOFBF, sizeof(inbuffer));
	int n;
	scanf("%d", &n);
	int ubound = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int x, w;
		scanf("%d %d", &x, &w);
		coords[x] += w;
		sum += w;
		if (ubound < x) { ubound = x; }
	}
	
	int c = 0;
	partialSum[0] = coords[0];
	for (c = 0; partialSum[c] < (sum + 1) / 2; ++c) {
		partialSum[c + 1] = partialSum[c] + coords[c + 1];
	}

	long long ws = 0;
	for (int i = 0; i <= ubound; ++i) {
		if (i < c) { ws += coords[i] * (c - i); }
		else { ws += coords[i] * (i - c); }
	}

	printf("%d\n%lld", c, ws);
	*/

	// solution 3 parse int manually
	//freopen("test.txt", "r", stdin);
	fseek(stdin, 0, SEEK_END);
	int file_size = ftell(stdin);
	fseek(stdin, 0, SEEK_SET);
	fread(buffer, file_size, sizeof(char), stdin);
	int n = parseint();
	
	
	int ubound = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
	    int x, w;
		x = parseint();
		w = parseint();
		coords[x] += w;
		sum += w;
		if (ubound < x) { ubound = x; }
	}

	int c = 0;
	partialSum[0] = coords[0];
	for (c = 0; partialSum[c] < (sum+1)/2; ++c) {
	    partialSum[c+1] = partialSum[c] + coords[c+1];
	}

	long long ws = 0;
	for (int i = 0; i <= ubound; ++i) {
		if (i < c) { ws += coords[i] * (c - i); }
		else { ws += coords[i] * (i - c); }
	}
	
	printf("%d\n%lld", c, ws);
	
	return 0;
}