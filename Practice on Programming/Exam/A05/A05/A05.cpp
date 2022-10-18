#include <iostream>
using namespace std;

bool matrix[40][45];

int step[3][2] = {-1, 0, 0, 1, 0, -1};

int result = 0, n, counter = 0;
bool isValid(int i, int row, int col) {
	int nextRow = step[i][0] + row;
	int nextCol = step[i][1] + col;
	
	return !matrix[nextRow][nextCol];
}

void explore(int row, int col) {
	if (counter == n) {
		result++;
		return;
	}
	matrix[row][col] = true;
	for (int i = 0; i < 3; i++) {
		if (isValid(i, row, col)) {
			counter++;
			explore(row+step[i][0], col+step[i][1]);
			counter--;
		}
	}
	matrix[row][col] = false;
}
int main() {
	cin >> n;
	explore(39, 22);
	cout << result << endl;
}