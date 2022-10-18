// given 6 positive integers with a least one odd and one even,
// all 6 integers are less than 100
// return the absolute difference of max odd and min even

#include <stdio.h>

int main() {
	int n = 6, max_odd = 0, min_even = 100, i, temp, diff;

	for (i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp % 2 == 0 && temp < min_even) {
			min_even = temp;
		} else if (temp % 2 == 1 && temp > max_odd) {
			max_odd = temp;
		}
	}
	diff = max_odd - min_even;
	diff = diff > 0 ? diff : -diff;
	printf("%d\n", diff);

	return 0;
}