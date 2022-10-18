#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

bool board[26][26];
int p, q, cur;
struct Pos {
	int row, col;
};

Pos path[26];

int allSteps[8][2] = {-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1};

bool isValidStep(int i, int row, int col) {
	int nextRow = allSteps[i][0] + row;
	int nextCol = allSteps[i][1] + col;
	return nextRow < q && nextRow >= 0 &&
		nextCol < p && nextCol >= 0 &&
		!board[nextRow][nextCol];
}

void printPath() {
	for (int i = 0; i < cur; i++) {
		cout << char(path[i].row + 'A') << path[i].col + 1;
	}
	cout << endl;
}

bool explore(int row, int col) {
	board[row][col] = true;
	path[cur].row = row;
	path[cur].col = col;
	cur++;
	if (cur < p*q) {
		for (int i = 0; i < 8; i++) {
			/*if (row == 1 && col == 2) {
				cout << "step: " << allSteps[i][0] << " " << allSteps[i][1];
				cout << (isValidStep(i, row, col) ? " true " : " false ");
				cout << "nextRow: " << allSteps[i][0] + row << " nextCol: " << allSteps[i][1] + col;
				cout << "board[nextRow][nextCol]: " << board[allSteps[i][0] + row][allSteps[i][1] + col] << endl;
			}*/
			if (isValidStep(i, row, col)) {
				if (explore(row+allSteps[i][0], col+allSteps[i][1])) {
					return true;
				}
			}
		}
	} else if (cur == p*q) {
		return true;
	}
	board[row][col] = false;
	cur--;
	return false;
}


int main() {
	int numCases;
	cin >> numCases;
	for (int t = 1; t <= numCases; t++) {
		cin >> p >> q;
		int flag = false;
		for (int i = 0; i < q && !flag; i++) {
			for (int j = 0; j < p && !flag; j++) {
				memset(board, 0, sizeof(board));
				cur = 0;
				if (explore(i, j)) {
					flag = true;
				}
			}
		}
		cout << "Scenario #" << t << ":" << endl;
		if (!flag) {
			cout << "impossible" << endl;
		} else {
			printPath();
		}
		cout << endl;
	}
}