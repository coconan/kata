#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct Mooncake {
     double amount;
     double price;
     double mratio;
};

bool cmp (const Mooncake &a, const Mooncake &b) {
    return a.mratio > b.mratio;
}
Mooncake ms[1005];
int n, d;

int main() {
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &ms[i].amount);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &ms[i].price);
        ms[i].mratio = ms[i].price / ms[i].amount;
    }
    sort(ms, ms+n, cmp);
    double profit = 0;
    for (int i = 0; i < n; ++i) {
        if (d > ms[i].amount) {
            profit += ms[i].price;
            d -= ms[i].amount;
        } else {
            profit += ms[i].price * (1.0 * d / ms[i].amount);
            d = 0;
            break;
        }
    }
    printf("%.2lf\n", profit);
    return 0;
}
