// An elephant drinks 20 liters of water when it is thirsty
// suppose every barrel with shape of a right cylinder has a
// base radius of r cm and a height of h cm (both r and h 
// are integers). How many barrels of water does an elephant
// drink?

#include <stdio.h>

#define PI 3.14159
#define EPSILON 0.000001
int main() {
	int h, r, N, amount = 20;
	double v;

	scanf("%d %d", &h, &r);

	v = PI * r * r * h / 1000.0;
	N = amount / v;
	if (N * v > amount - EPSILON && N * v < amount + EPSILON) {
		printf("%d\n", N);
	} else {
		printf("%d\n", N + 1);
	}

	return 0;
}