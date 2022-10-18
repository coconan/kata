#include <iostream>
#include <memory.h>

using namespace std;

int value[1000][1000];
int boys[1000];
int girls[1000];

int findMax(int* arr, int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > arr[max]) max = i;
	}
	return max+1;
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(value, 0, sizeof(value));
		memset(boys, 0, sizeof(boys));
		memset(girls, 0, sizeof(girls));
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> value[j][k];
				boys[j] += value[j][k];
				girls[k] += value[j][k];
			}
		}

		cout << findMax(boys, n) << " " << findMax(girls, n) << endl;
	}
}