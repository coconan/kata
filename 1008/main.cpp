#include<iostream>
#include<vector>

using namespace std;

int main() {
	int totalTime = 0, n;
	cin >> n;
	int prevFloor = 0;
	for (int i = 0; i < n; ++i) {
        int currFloor;
        cin >> currFloor;
        if (currFloor > prevFloor) {
            totalTime += (currFloor - prevFloor) * 6 + 5;
        } else {
            totalTime += (prevFloor - currFloor) * 4 + 5;
        }
        prevFloor = currFloor;
	}
	cout << totalTime << endl;
}
