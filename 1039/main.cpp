#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> student[300000];
int n, k, nstudent, cindex;
char name[10];

int myhash(char s[]) {
    return 26 * 26 * 10 * (s[0] - 'A') + 26 * 10 * (s[1] - 'A') + 10 * (s[2] - 'A') + s[3] - '0';
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    //printf("%d %d", n, k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &cindex, &nstudent);
        for (int j = 0; j < nstudent; ++j) {
            scanf("%s", name);
            student[myhash(name)].push_back(cindex);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", name);
        int idx = myhash(name);
        printf("%s %d", name, student[idx].size());
        sort(student[idx].begin(), student[idx].end());
        for (int j = 0; j < student[idx].size(); ++j) {
            printf(" %d", student[idx][j]);
        }
        printf("\n");
    }
    return 0;
}
