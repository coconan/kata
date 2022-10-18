#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int large, small;
    cin >> large;
    int digits[4];
    do {
        digits[0] = large / 1000;
        digits[1] = (large % 1000) / 100;
        digits[2] = (large % 100) / 10;
        digits[3] = large % 10;
        sort(digits, digits+4);
        small = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
        large = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
        printf("%04d - %04d = ", large, small);
        large = large - small;
        printf("%04d\n", large);
    } while (large != 0 && large != 6174);
    return 0;
}
