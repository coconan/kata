#include <iostream>
#include <memory.h>
#include <stdio.h>

using namespace std;
int n;
int bets[100005];
int counts[10005];

int main() {
    memset(counts, 0, sizeof(counts));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &bets[i]);
        counts[bets[i]]++;
    }
    int thenum = -1;
    for (int i = 0; i < n; ++i) {
        if (counts[bets[i]] == 1) {
            thenum = bets[i];
            break;
        }
    }
    if (thenum != -1) {
        printf("%d\n", thenum);
    } else {
        printf("None\n");
    }
    return 0;
}
