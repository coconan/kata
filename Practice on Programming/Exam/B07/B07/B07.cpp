#include <iostream>
#include <stdio.h>

using namespace std;

int cache[21][21][21];

int maxx(int a, int b) {
	return a > b ? a : b;
}

void build() {
	for (int w = 1; w <= 20; w++) {
		for (int h = 1; h <= 20; h++) {
			cache[w][h][1] = w*h;
		}
	}
	cout << "ok" << endl;
	for (int m = 2; m <= 20; m++) {
		for (int w = 1; w <= 20; w++) {
			for (int h = 1; h <= 20; h++) {
				if (m > w*h) {
					cache[w][h][m] = 1 << 30;
					continue;
				}

				int bound = 1 << 30;
				for (int m1 = 1; m1 < m; m1++) {
					int m2 = m-m1;
					for (int w1 = 1; w1 < w/2+1; w1++) {
						int w2 = w-w1;
						int max = maxx(cache[w1][h][m1], cache[w2][h][m2]);
						if (bound > max) {
							bound = max;
						}
					}
					for (int h1 = 1; h1 < h/2+1; h1++) {
						int h2 = h-h1;
						int max = maxx(cache[w][h1][m1], cache[w][h2][m2]);
						if (bound > max) {
							bound = max;
						}
					}
				}
				cache[w][h][m] = bound;
			}
		}
	}
}

void printM(int m) {
	for (int w = 1; w <= 5; w++) {
		for (int h = 1; h <= 5; h++) {
			printf("%10d ", cache[w][h][m]);
		}
		cout << endl;
	}
}

int main() {
	int w, h, m;
	build();
	printM(2);
	while(true) {
		cin >> w >> h >> m;
		if (w != 0) {
			cout << cache[w][h][m] << endl;
		} else {
			break;
		}
	}
	return 0;
}