#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

int maxDepth = 0;
set<int> deepRoots;
int dist[10010];
bool visited[10010];

int P[10010];


void dfs(vector< vector<int> > &adjlist, int node, int depth) {
    if (depth > maxDepth) {
        maxDepth = depth;
        deepRoots.clear();
        deepRoots.insert(node);
    } else if (depth == maxDepth) {
        deepRoots.insert(node);
    }
    dist[node] = depth;
    visited[node] = true;
    for (int i = 0; i < adjlist[node].size(); ++i) {
        if (!visited[adjlist[node][i]]) {
            dfs(adjlist, adjlist[node][i], depth+1);
        }
    }
}

int bfs(vector< vector<int> > &adjlist, int node) {
    memset(dist, 0, sizeof(dist));
    visited[node] = true;
    queue<int> q;
    q.push(node);
    dist[node] = 0;
    int maxDepth = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for(int i = 0; i < adjlist[n].size(); ++i) {
            if (!visited[adjlist[n][i]]) {
                visited[adjlist[n][i]] = true;
                q.push(adjlist[n][i]);
                dist[adjlist[n][i]] = dist[n] + 1;
                if (dist[n] + 1 > maxDepth) {
                    maxDepth = dist[n] + 1;
                }
            }
        }
    }
    return maxDepth;
}

int main() {
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector< vector<int> > adjlist(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        adjlist[n1-1].push_back(n2-1);
        adjlist[n2-1].push_back(n1-1);
    }
    memset(visited, false, sizeof(visited));
    int counter = 0;
    for (int i = 0; i < n; ++i) {
       if (!visited[i]) {
            counter++;
            visited[i] = true;
            dfs(adjlist, i, 0);
        }
    }
    if (counter != 1) {
        cout << "Error: " << counter << " components" << endl;
    } else {
        // dfs
        memset(visited, false, sizeof(visited)); //visited.assign(n, false);
        int node = *deepRoots.begin();
        set<int> allDeepRoots(deepRoots);
        dfs(adjlist, node, 0);
        for (set<int>::iterator it = deepRoots.begin(); it != deepRoots.end(); ++it) {
            allDeepRoots.insert(*it);
        }
        for (set<int>::iterator it = allDeepRoots.begin(); it != allDeepRoots.end(); ++it) {
            cout << *it + 1 << endl;
        }

//        // bfs
//        memset(visited, false, sizeof(visited));
//        int maxDepth = bfs(adjlist, 0);
//        int node;
//
//        for (int i = 0; i < n; ++i) {
//            if (dist[i] == maxDepth) {
//                node = i;
//                deepRoots.insert(i);
//            }
//        }
//        memset(visited, false, sizeof(visited));
//        maxDepth = bfs(adjlist, node);
//        dist[node] = maxDepth;
//        for (int i = 0; i < n; ++i) {
//            if (dist[i] == maxDepth)
//                deepRoots.insert(i);
//        }
//        for (set<int>::iterator it = deepRoots.begin(); it != deepRoots.end(); ++it) {
//           cout << *it+1 << endl;
//        }
    }
    return 0;
}
