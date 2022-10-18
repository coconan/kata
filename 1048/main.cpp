#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> coins;
    for (int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);
        coins.push_back(value);
    }

    sort(coins.begin(), coins.end());
    int i = 0;
    bool found = false;
    for (vector<int>::iterator it = coins.begin(); it != coins.end() && 2 * (*it) <= m; ++it) {
        vector<int>:: iterator hit = upper_bound(coins.begin(), coins.end(), m - *it) - 1;
        if (*hit + *it == m && hit != it) {
            printf("%d %d\n", *it, *hit);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("No Solution\n");
    }
    return 0;
}
