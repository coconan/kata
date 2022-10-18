// 2014-11-22
#include <stdio.h>

char bufferin[8000000];
char bufferout[8000000];

struct Line {
	long long a;
	long long b;
};

Line ls[100005];

inline
long long crossProd(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - x2 * y1;
}

int bisect(int lo, int hi, long long x, long long y) {
	while (lo < hi) {
		int mi = (hi - lo) / 2 + lo;
		if (crossProd(x, y-ls[mi].b, ls[mi].a, -ls[mi].b) > 0) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}
	return lo;
}

int main() {
	setvbuf(stdin, bufferin, _IOFBF, sizeof(bufferin));
	setvbuf(stdout, bufferout, _IOFBF, sizeof(bufferout));
	//freopen("in.txt", "r", stdin);
    int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &ls[i].a, &ls[i].b);
	}

	for (int i = 0; i < m; ++i) {
	    long long x, y;
	    scanf("%lld%lld", &x, &y);
		printf("%d\n", bisect(0, n, x, y));
	}
    
	return 0;
}