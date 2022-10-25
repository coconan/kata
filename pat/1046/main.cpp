#include <iostream>
#include <stdio.h>

using namespace std;

int dist[100005];
int clockwise[100005];
int count_clockwise[100005];
int n, m;
int s, d;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dist[i]);
    }
    clockwise[1] = 0;
    count_clockwise[1] = 0;
    count_clockwise[n] = dist[n];
    for (int i = 2; i <= n; ++i) {
        clockwise[i] = clockwise[i-1] + dist[i-1];
    }
    for (int i = n-1; i > 1; --i) {
        count_clockwise[i] = count_clockwise[i+1] + dist[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &s, &d);
        int c = clockwise[d] < clockwise[s] ? clockwise[s] - clockwise[d]
                                            : clockwise[d] - clockwise[s];
        int uc = clockwise[d] < clockwise[s] ? clockwise[d] + count_clockwise[s]
                                             : clockwise[s] + count_clockwise[d];
        if (c < uc)  { printf("%d\n", c); }
        else { printf("%d\n", uc); }
    }
    return 0;
}
