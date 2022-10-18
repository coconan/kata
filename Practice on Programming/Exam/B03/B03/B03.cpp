#include <iostream>
#include <memory.h>

using namespace std;

int digits[10];

void deleteDigit(int n) {
	int i;
	for (i = n-1; i > 0; i--) {
		if (digits[i] > digits[i-1]) {
			break;
		}
	}
	for (int j = i; i < n-1; i++) {
		digits[i] = digits[i+1];
	}
}

int main() {
	unsigned n, t, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(digits, 0, sizeof(digits));
		cin >> n >> k;
		int j = 0;
		while (n > 0) {
			digits[j++] = n % 10;
			n = n / 10;
		}
		for (int l = 0; l < k; l++) {
			deleteDigit(j-l);
			/*for (int m = 0; m < j-l-1; m++) {
				cout << digits[m];
			}
			cout << endl;*/
		}
		int result = 0;
		for (int l = j-k-1; l >= 0; l--) {
			result = result * 10 + digits[l];
		}
		cout << result << endl;
	}
}