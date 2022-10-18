#include <iostream>

using namespace std;

int main() {
	unsigned int t, n, i, j, k;
	cin >> t;
	while (t > 0) {
		cin >> n >> i >> j;
		k = 0;
		k += (((n>>i) & 1) <<i) + ((((n>>j) & 1) ^ 1) << j);
		cout << k << endl;
		t--;
	}
	return 0;
}