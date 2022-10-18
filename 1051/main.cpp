#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int pops[1005];
int n, m, k;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &pops[j]);
        }
        int last = 0;
        bool valid = true;
        stack<int> s;
        for (int j = 0; j < n && valid; ++j) {
            while (last < pops[j] && s.size() < m) {
                s.push(++last);
            }
            if (pops[j] == s.top()) {
                s.pop();
            } else {
                valid = false;
            }
        }
        if (valid) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
