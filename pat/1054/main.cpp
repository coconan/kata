#include <iostream>
#include <stdio.h>

using namespace std;

int matrix[1000][1000];

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
        scanf("%d", &matrix[i][j]);
    }

    int counter = 0, color;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (counter == 0) {
                color = matrix[i][j];
                counter = 1;
            } else {
                if (matrix[i][j] == color) { counter++; }
                else { counter--; }
            }
        }
    }
    printf("%d\n", color);
    return 0;
}
