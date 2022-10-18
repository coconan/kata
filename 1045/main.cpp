#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

int stripe[10005];
int favcolor[205];
int n, m, l;
int len[205];

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &favcolor[i]);
    }
    scanf("%d", &l);
    for (int i = 0; i < l; ++i) {
        scanf("%d", &stripe[i]);
    }
    memset(len, 0, sizeof(len));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            if (stripe[i] == favcolor[j]) {
                len[j]++;
            } else if (j > 0 && len[j] < len[j-1]) {
                len[j] = len[j-1];
            }
        }
    }
    printf("%d\n", len[m-1]);
    return 0;
}
