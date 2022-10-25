#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

string seg[100005];

bool cmp(const string &s1, const string &s2) {
    return s1+s2 < s2+s1;
}

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seg[i];
    }
    sort(seg, seg+n, cmp);
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (first) {
            int j = 0;
            while(seg[i][j] == '0' && j < seg[i].size()) { j++; }
            if (j != seg[i].size()) {
                first = false;
                cout << seg[i].substr(j);
            }
        } else {
            cout << seg[i];
        }
    }
    if (first) {
        cout << '0';
    }
    cout << endl;
    return 0;
}
