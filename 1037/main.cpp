#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long coupons[100005], products[100005];

int main() {
    int nc, np;
    scanf("%d", &nc);
    for (int i = 0; i < nc; ++i) {
        scanf("%lld", &coupons[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        scanf("%lld", &products[i]);
    }
    sort(coupons, coupons+nc);
    sort(products, products+np);
    long long m = 0;
    int ic = 0, ip = 0;
    while (ic < nc && ip < np && coupons[ic] < 0 && products[ip] < 0) {
        m += coupons[ic] * products[ip];
        ic++; ip++;
    }
    ic = nc-1, ip = np-1;
    while (ic >= 0 && ip >= 0 && coupons[ic] > 0 && products[ip] > 0) {
        m += coupons[ic] * products[ip];
        ic--; ip--;
    }
    printf("%lld\n", m);
    return 0;
}
