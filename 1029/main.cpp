#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;
long a[1000010], b[1000000];

int main() {
    int len1, len2;
    scanf("%d", &len1);
    for (int i = 0; i < len1; ++i) {
        scanf("%ld", &a[i]);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; ++i) {
        scanf("%ld", &b[i]);
    }

    int i = 0, i1 = 0, i2 = 0;
    for (i = 0; i < (len1 + len2 - 1) / 2 && i1 < len1 && i2 < len2; ++i) {
        if (a[i1] < b[i2]) { ++i1; }
        else { ++i2; }
    }
    while (i < (len1 + len2 - 1) / 2 && i1 < len1) { ++i1; ++i; }
    while (i < (len1 + len2 - 1) / 2 && i2 < len2) { ++i2; ++i; }
    if (i1 < len1 && i2 < len2) {
        if (a[i1] < b[i2])  { printf("%ld\n", a[i1]); }
        else { printf("%ld\n", b[i2]); }
    } else if (i1 >= len1) {
        printf("%ld\n", b[i2]);
    } else {
        printf("%ld\n", a[i1]);
    }
    return 0;
}
