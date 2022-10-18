// There are n apples and 1 pest in a box, the pest
// take x hours to eat an apple, how many apples left
// y hours later?

#include <stdio.h>

int main() {
	int n, x, y, eaten;
	
	scanf("%d %d %d", &n, &x, &y);
	
	eaten = y / x;
	if (eaten >= n) {      // have enough time to eat up all n apples
		eaten = n;
	} else if (y % x != 0) {
		eaten++;
	}

	printf("%d", n - eaten);

	return 0;
}