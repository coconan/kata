#include <stdio.h>
#include <memory.h>

#define MAXN 505
#define INF  1000000

int numShortestPath[MAXN];
int distance[MAXN];
int numTeams[MAXN];
int maxTeams[MAXN];
int matrix[MAXN][MAXN];
bool included[MAXN];

void shortestPath(int src, int dim) {
    maxTeams[src] = numTeams[src];
    numShortestPath[src] = 1;
    for (int i = 0; i < dim; ++i) {
        distance[i] = matrix[src][i];
    }
    for (int i = 0; i < dim-1; ++i) {
        int minDist = INF, c;
        for (int j = 0; j < dim; j++) {
            if (distance[j] < minDist && !included[j]) {
                minDist = distance[j];
                c = j;
            }
        }
        included[c] = true;
        for (int j = 0; j < dim; j++) {
            if (!included[j]) {
                if (matrix[c][j] + distance[c] < distance[j]) {
                    distance[j] = matrix[c][j] + distance[c];
                    numShortestPath[j] = numShortestPath[c];
                    maxTeams[j] = numTeams[j] + maxTeams[c];
                } else if(matrix[c][j] + distance[c] == distance[j]) {
                    numShortestPath[j] += numShortestPath[c];
                    if (maxTeams[j] < numTeams[j] + maxTeams[c]) {
                        maxTeams[j] = numTeams[j] + maxTeams[c];
                    }
                }
            }
        }
    }
}

int main() {
    memset(numShortestPath, 0, sizeof(numShortestPath));
    memset(numTeams, 0, sizeof(numTeams));
    memset(maxTeams, 0, sizeof(maxTeams));
    memset(included, 0, sizeof(included));
    int n, m, c1, c2;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = 0;
        for (int j = i + 1; j < n; ++j) {
            matrix[i][j] = matrix[j][i] = INF;
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numTeams[i]);
    }
    for (int i = 0; i < m; ++i) {
        int h, t, l;
        scanf("%d %d %d", &h, &t, &l);
        matrix[h][t] = matrix[t][h] = l;
    }
    shortestPath(c1, n);
    printf("%d %d\n", numShortestPath[c2], maxTeams[c2]);
    return 0;
}
