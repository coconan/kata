#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

struct Pos {
	int row, col;
};

Pos allPos[64];
bool rowOccupied[8], colOccupied[8];
int numPos = 0, result = 0;

void explore(int start, int left) {
	if (numPos - start < left) return;
	if (left == 0) {
		result++;
		return;
	}
	explore(start+1, left);
	int row = allPos[start].row;
	int col = allPos[start].col;
	if (!rowOccupied[row] && !colOccupied[col]) {
		rowOccupied[row] = true;
		colOccupied[col] = true;
		explore(start+1, left-1);
		rowOccupied[row] = false;
		colOccupied[col] = false;
	}
}

int main() {
	int n, k;
	while (true) {
		memset(rowOccupied, 0, sizeof(rowOccupied));
		memset(colOccupied, 0, sizeof(colOccupied));
		result = 0;
		numPos = 0;
		cin >> n >> k;
		if (n == -1 || k == -1) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char sign;
				cin >> sign;
				if (sign == '#') {
					allPos[numPos].row = i;
					allPos[numPos].col = j;
					numPos++;
				}
			}
		}
		explore(0, k);
		cout << result << endl;
	}
	return 0;
}