#include <iostream>

using namespace std;

int wall[20][20], penpoint[20][20];

int pow(int x, int y) {
	int result = 1;
	for (int i = 0; i < y; i++) {
		result *= x;
	}
	return result;
}

void fill(int n) {
	for (int r = 1; r < n; r++) {
		for (int c = 1; c <= n; c++) {
			penpoint[r+1][c] = (wall[r][c] + penpoint[r][c] + penpoint[r-1][c]
								+ penpoint[r][c+1] + penpoint[r][c-1] + 1) % 2;
		}
	}
}

bool check(int n) {
	for (int c=1; c <= n; c++) {
		int state = (wall[n][c] + penpoint[n-1][c] + penpoint[n][c-1] 
					+ penpoint[n][c+1] + penpoint[n][c]) % 2;
		if (state != 1) {
			return false;
		}
	}
	return true;
}

bool enumerate(int n) {
	for (int i = 0; i < pow(2, n); i++) {
		fill(n);
		if (check(n)) {
			return true;
		}
		penpoint[1][1]++;
		int c = 1;
		while(penpoint[1][c] > 1) {
			penpoint[1][c] = 0;
			c++;
			penpoint[1][c]++;
		}
	}
	return false;
}

int count(int n) {
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (penpoint[i][j] == 1) {
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	int t, n;
	char brickColor;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j <= n+1; j++) {
			wall[0][j] = 0;
			wall[j][0] = 0;
			wall[j][n+1] = 0;
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> brickColor;
				wall[j][k] = brickColor=='y';
			}
		}
		for (int k = 0; k < n+2; k++) {
			for (int l = 0; l < n+2; l++) {
				penpoint[k][l] = 0;
			}
		}
		if (enumerate(n)) {
			cout << count(n) << endl;
		} else {
			cout << "inf" << endl;
		}
	}
}