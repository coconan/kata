// given a decimal integer with 3 digits,
// output the units digit, tens digit, and
// hundreds digit in separate lines.

#include <stdio.h>

int main() {
	int num, digits = 3, i, d = 100;
	
	scanf("%d", &num);

	for (i = 0; i < 3; i++) {
		printf("%d\n", num / d);
		num = num % d;
		d = d / 10;
	}

	return 0;
}