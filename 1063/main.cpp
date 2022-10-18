#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;
set<int> allset[50];
int n, m, k, s1, s2, nc, nt;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int e;
            scanf("%d", &e);
            allset[i].insert(e);
        }
    }

//    for (int i = 0; i < n; ++i) {
//        printf("%d ", allset[i].size());
//        for (set<int>::iterator it = allset[i].begin();
//             it != allset[i].end(); ++it) {
//             printf("%d ", *it);
//        }
//        printf("\n");
//    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        nc = nt = 0;
        scanf("%d %d", &s1, &s2);
        set<int>::iterator sit1 = allset[s1-1].begin();
        set<int>::iterator sit2 = allset[s2-1].begin();
        while (sit1 != allset[s1-1].end() && sit2 != allset[s2-1].end()) {
            if (*sit1 == *sit2) {
                nc++;
                sit1++;
                sit2++;
            } else if (*sit1 < *sit2) {
                sit1++;
            } else {
                sit2++;
            }
        }
        nt = allset[s1-1].size() + allset[s2-1].size() - nc;
        printf("%.1f%%\n", (1.0 * nc) / nt * 100);
    }

    return 0;
}
