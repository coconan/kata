// Get the highest score in a list of scores

#include <stdio.h>

int main() {
	int highest = 0, score, n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &score);
		if (score > highest) {
			highest = score;
		}
	}

	printf("%d\n", highest);

	return 0;
}