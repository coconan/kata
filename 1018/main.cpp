#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const int INF = 1000000;

void shortestPath(vector< vector<int> > matrix, vector<int> state, int dest, int perfect) {
     int n = matrix.size();
     vector<bool> included(n, false);
     vector<int> dist(n, INF), surplus(n, 0), demand(n, INF), prev(n, 0);
     dist[0] = 0;
     demand[0] = 0;
     for (int i = 1; i < n; ++i) {
        dist[i] = matrix[0][i];
     }
     for(int i = 0; i < n; ++i) {
        int minDist = INF;
        int next = 0;
        for (int j = 0; j < n; ++j) {
            if (!included[j] && dist[j] < minDist) {
                minDist = dist[j];
                next = j;
            }
        }
        included[next] = true;
        for (int j = 1; j < n; ++j) {
            if (dist[next] + matrix[next][j] < dist[j]) {
                dist[j] = dist[next] + matrix[next][j];
                prev[j] = next;
                surplus[j] = surplus[next] + state[j] - perfect;
                if (surplus[j] < 0) {
                    demand[j] = -surplus[j] + demand[next];
                    surplus[j] = 0;
                } else {
                    demand[j] = demand[next];
                }
            } else if (matrix[next][j] != INF && dist[next] + matrix[next][j] == dist[j]) {
                int sur = surplus[next] + state[j] - perfect;
                if (sur < 0) {
                    if (demand[next] - sur < demand[j]) {
                        demand[j] = -sur + demand[next];
                        surplus[j] = 0;
                        prev[j] = next;
                    }
                } else {
                    if (demand[next] < demand[j]) {
                        demand[j] = demand[next];
                        prev[j] = next;
                        surplus[j] = sur;
//                    } else if (demand[next] == demand[j]) {
//                        if (sur > surplus[j]) {
//                            demand[j] = demand[next];
//                            prev[j] = next;
//                            surplus[j] = sur;
//                        }
                    }
                }
            }
        }
//        cout << "next: " << next << endl;
//        cout << "dist: ";
//        for (int j = 0; j < n; ++j) {
//            cout << dist[j] << " ";
//        }
//        cout << endl;
//        cout << "demand: ";
//        for (int j = 0; j < n; ++j) {
//            cout << demand[j] << " ";
//        }
//        cout << endl;
//        cout << "surplus: ";
//        for (int j = 0; j < n; ++j) {
//            cout << surplus[j] << " ";
//        }
//        cout << endl;
//        cout << "prev: ";
//        for (int j = 0; j < n; ++j) {
//            cout << prev[j] << " ";
//        }
//        cout << endl;
     }
     vector<int> path;
     for (int cur = dest; cur != 0; cur = prev[cur]) {
        path.push_back(cur);
     }
     cout << demand[dest] << " 0";
     for (int i = path.size() - 1; i >= 0; --i) {
        cout << "->" << path[i];
     }
     cout << " " << surplus[dest] << endl;
}

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());

    int cmax, n, sp, m;
    cin >> cmax >> n >> sp >> m;
    vector<int> bikesAtStation(n+1, 0);
    vector< vector<int> > matrix(n+1, vector<int>(n+1, INF));
    for (int i = 1; i <= n; ++i) {
        cin >> bikesAtStation[i];
    }
    for (int i = 0; i < m; ++i) {
        int s1, s2, cost;
        cin >> s1 >> s2 >> cost;
        matrix[s1][s2] = cost;
        matrix[s2][s1] = cost;
    }

    shortestPath(matrix, bikesAtStation, sp, cmax/2);
    return 0;
}
