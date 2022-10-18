#include <iostream>

using namespace std;

int cache[5][1001];

int value[5] = {0, 10, 20, 50, 100};


int main() {
	for (int i = 0; i < 1001; i++) {
		if (i % 10 == 0) {
		cache[1][i] = 1;
		} else {
			cache[1][i] = 0;
		}
	}
	for (int i = 2; i <= 4; i++) {
		for (int j = 0; j < 1001; j++) {
			if (j == 0) {
				cache[i][j] = 1;
			} else if (j - value[i] >= 0) {
				cache[i][j] = cache[i][j-value[i]] + cache[i-1][j];
			} else {
				cache[i][j] = cache[i-1][j];
			}
		}
	}
	int n;
	cin >> n;
	cout << cache[4][n] << endl;
}