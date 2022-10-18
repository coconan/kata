// There are two subspecies of germs that have very similar
// superficial characteristics, but they have very diffrent
// reproductive abilities. Given n specimen, group them by
// reproductive rate.

#include <stdio.h>

int main() {
	int n, i, j, tempId, partition = 0;
	int id[100];
	double rate[100], before, after, tempRate, maxDiff = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %lf %lf", &id[i], &before, &after);
		rate[i] = after / before;
	}

	for (i = 0; i < n - 1; i++) {           // sort by rate
		for (j = 0; j < n - i - 1; j++) {
			if (rate[j + 1] > rate[j]) {
				tempId = id[j];
				id[j] = id[j + 1];
				id[j + 1] = tempId;
				tempRate = rate[j];
				rate[j] = rate[j + 1];
				rate[j + 1] = tempRate;
			}
		}
	}

	for (i = 0; i < n - 1; i++) {
		if (maxDiff < rate[i] - rate[i + 1]) {
			maxDiff = rate[i] - rate[i + 1];
			partition = i + 1;
		}
	}

	printf("%d\n", partition);
	for (i = partition - 1; i >= 0; i--) {
		printf("%d\n", id[i]);
	}

	printf("%d\n", n - partition);
	for (i = n - 1; i >= partition; i--) {
		printf("%d\n", id[i]);
	}

	return 0;
}