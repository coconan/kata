#include <iostream>

using namespace std;

const int moves[9][9] = {1, 1, 0, 1, 1, 0, 0, 0, 0,
						 1, 1, 1, 0, 0, 0, 0, 0, 0,
						 0, 1, 1, 0, 1, 1, 0, 0, 0,
						 1, 0, 0, 1, 0, 0, 1, 0, 0,
						 0, 1, 0, 1, 1, 1, 0, 1, 0,
						 0, 0, 1, 0, 0, 1, 0, 0, 1,
						 0, 0, 0, 1, 1, 0, 1, 1, 0,
						 0, 0, 0, 0, 0, 0, 1, 1, 1,
						 0, 0, 0, 0, 1, 1, 0, 1, 1 };
int clocks[9];
int minSteps = 27;
int minSeq[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
int sequence[9];
int steps = 0;

bool check() {
	for (int i = 0; i < 9; i++) {
		if (clocks[i] != 0) {
			return false;
		}
	}
	return true;
}

void enumerate(int n) {
	for (int i = 0; i < 4; i++) {
		if (steps + i > minSteps) return;
		sequence[n] = i;
		steps += i;
		for (int j = 0; j < 9; j++) {
			clocks[j] = (clocks[j] + moves[n][j] * i) % 4;
		}

		if (check()) {
			if (steps < minSteps) {
				for (int k = 0; k <= n; k++) {
					minSeq[k] = sequence[k];
				}
				minSteps = steps;
			}
		} else {
			if (n < 8) {
				enumerate(n+1);
			}
		}

		for (int j = 0; j < 9; j++) {
			clocks[j] = (clocks[j] - moves[n][j] * i + 4) % 4;
		}
		steps -= i;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> clocks[i];
	}
	enumerate(0);
	int output[27];
	for (int i = 0, m = 0; i < 9 && m < minSteps; i++) {
		for (int j = 0; j < minSeq[i]; j++) {
			output[m] = i+1;
			m++;
		}
	}
	cout << output[0];
	for (int i = 1; i < minSteps; i++) {
		cout << " " << output[i];
	}
	cout << endl;
}