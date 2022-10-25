#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

#define INF 1000000

bool included[505];
int dist[505], cost[505];
int dmatrix[505][505];
int cmatrix[505][505];
int prevc[505];
int path[505];

void dij(int s, int n) {
    prevc[s] = -1;
    dist[s] = 0; cost[s] = 0;
    for (int i = 0; i < n; ++i) {
        int mindist = INF, w = INF;
        for (int v = 0; v < n; ++v) {
            if (!included[v] && dist[v] < mindist) {
                mindist = dist[v];
                w = v;
            }
        }
        included[w] = true;
        for (int v = 0; v < n; ++v) {
            if (dmatrix[w][v] + dist[w] < dist[v]) {
                dist[v] = dmatrix[w][v] + dist[w];
                cost[v] = cmatrix[w][v] + cost[w];
                prevc[v] = w;
            } else if (dmatrix[w][v] + dist[w] == dist[v]) {
                if (cmatrix[w][v] + cost[w] < cost[v]) {
                    cost[v] = cmatrix[w][v] + cost[w];
                    prevc[v] = w;
                }
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    memset(included, false, sizeof(included));
    int n, m, s, d;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < n; ++i) {
        dist[i] = INF; cost[i] = INF;
        for (int j = 0; j < n; ++j) {
            cmatrix[i][j] = INF;
            dmatrix[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        scanf("%d", &dmatrix[c1][c2]);
        scanf("%d", &cmatrix[c1][c2]);
        dmatrix[c2][c1] = dmatrix[c1][c2];
        cmatrix[c2][c1] = cmatrix[c1][c2];
    }
    for (int i = 0; i < n; ++i) {
        dmatrix[i][i] = 0;
        cmatrix[i][i] = 0;
    }

    dij(s, n);
    int hop = 0;
    path[hop++] = d;
    for (int cur = d; prevc[cur] != -1; hop++) {
        path[hop] = prevc[cur];
        cur = prevc[cur];
    }

    for (int i = hop-1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", dist[d], cost[d]);
    return 0;
}
