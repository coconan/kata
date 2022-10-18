#include <iostream>
#include <memory.h>

using namespace std;

int maze[7][7];
bool reached[7][7]; 

struct Direction {
	int dx, dy;
	Direction(int _dx, int _dy): dx(_dx), dy(_dy) {} 
};

struct Pos {
	int x, y;
	int prev;
	Pos(int _x = -1, int _y = -1, int _prev = -1): x(_x), y(_y), prev(_prev) {}
};

Pos path[25];

Pos queue[25];
const Direction directions[4] = {Direction(-1, 0), Direction(1, 0), Direction(0, -1), Direction(0, 1)};

int explore() {
	int head = 0, rear = 0, founded = false;
	Pos p(1, 1, -1);
	queue[rear++] = p;
	while (head < rear && !founded) {
		Pos cur = queue[head++];
		for (int i = 0; i < 4 && !founded; i++) {
			int x, y;
			x = directions[i].dx + cur.x;
			y = directions[i].dy + cur.y;
			if (!reached[x][y] && maze[x][y] == 0) {
				queue[rear++] = Pos(x, y, head-1);
				reached[x][y] = true;
			}
			if (x == 5 && y == 5) {
				founded = true;
			}
		}
	}
	return rear-1;
}

void printPath() {
	int last = explore(), length = 0;
	Pos pos = queue[last];
	while (pos.prev >= 0) {
		path[length++] = pos;
		pos = queue[pos.prev];
	}
	path[length++] = pos;
	for (int i = length-1; i >= 0; i--) {
		cout << "(" << path[i].x - 1 << ", " << path[i].y - 1 << ")" << endl;
	}
}

int main() {
	memset(reached, 0, sizeof(reached));
	int size = 5;
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			cin >> maze[i][j];
		}
	}

	for (int i = 0; i < size + 2; i++) {
		maze[i][0] = 1;
		maze[0][i] = 1;
		maze[6][i] = 1;
		maze[i][6] = 1;
	}
	
	printPath();

	return 0;
}