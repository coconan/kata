#include <iostream>
#include <cstdio>

using namespace std;

int A[10005];

int main() {
	int n, k;
	cin >> n >> k;
	
	int sum = 0;
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}

	if (sum / k < 1) {
		cout << 0 << endl;
	} else {
		int lo = 1, hi = 10000;
		while (lo < hi) {
			int mi = (lo + hi) >> 1;
			int counter = 0;
			for (int i = 0; i < n; i++) {
				counter += A[i]/mi;
			}
			if (counter < k) {
				hi = mi;
			} else {
				lo = mi + 1;
			}
		}
		cout << lo-1 << endl;
	}
	return 0;
}