#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
int children[105][105];
int weight[105];
int nchildren[105];
int path[105];
int n, m, s;
int cur = 0, sum = 0, npath = 0;
char strpath[3000];

void dfs(int id) {
    if (nchildren[id] == 0) {
        if (sum == s) {
            printf("%d", path[0]);
            for (int i = 1; i < cur; ++i) {
                printf(" %d", path[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 0; i < nchildren[id]; ++i) {
        path[cur++] = weight[children[id][i]];
        sum += weight[children[id][i]];
        dfs(children[id][i]);
        cur--;
        sum -= weight[children[id][i]];
    }
}

bool cmp(int id1, int id2) {
    return weight[id1] > weight[id2];
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; ++i) {
        int id, k;
        scanf("%d %d", &id, &k);
        nchildren[id] = k;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &children[id][j]);
        }
        sort(children[id], children[id]+k, cmp);
    }

    path[cur++] = weight[0];
    sum += weight[0];
    dfs(0);
    cur--;
    sum -= weight[0];
}
