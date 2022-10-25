#include <iostream>
#include <queue>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > members;
    members.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int child;
            cin >> child;
            members[id].push_back(child);
        }
    }

    queue<int> q;
    q.push(1);
    int last = 1, counter = 0;
    vector<int> numLeaves;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (members[curr].empty()) { counter++; }
        //cout << curr << " " << last << " " << counter << endl;
        for (vector<int>::iterator it = members[curr].begin(); it != members[curr].end(); ++it) {
            q.push(*it);
        }
        if (curr == last) {
            numLeaves.push_back(counter);
            last = q.back();
            counter = 0;
        }
        //cout << curr << " " << last << " " << q.size() << endl;
    }

    cout << numLeaves[0];
    for (vector<int>::iterator it = numLeaves.begin() + 1; it != numLeaves.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    return 0;
}
