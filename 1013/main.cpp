#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

int bfs(vector< vector<int> > matrix) {
    queue<int> q;
    vector<bool> visited(matrix.size(), false);
    int counter = 0;
    for (unsigned i = 0; i < matrix.size(); ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;
            ++counter;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (unsigned j = 0; j < matrix.size(); ++j) {
                    if (matrix[cur][j] && !visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }
    return counter;
}

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    vector< vector<int> > matrix;
    int n, m, k;
    cin >> n >> m >> k;
    matrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        matrix[c1-1][c2-1] = 1;
        matrix[c2-1][c1-1] = 1;
    }
    for (int i = 0; i < k; ++i) {
        int city;
        cin >> city;
        vector< vector<int> > matrixCopy(matrix);
        for (int j = 0; j < n; ++j) {
            matrixCopy[city-1][j] = 0;
            matrixCopy[j][city-1] = 0;
        }
        cout << bfs(matrixCopy) - 2 << endl;
    }
    return 0;
}
