#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Member {
     char name[10];
     int weight;
     int total;
     int head;
};

struct Gang {
     char head[10];
     int gsize;
};

Member ms[3005];
Gang gs[3005];
int nmem = 0, ngang = 0;
int n, k;
char name1[10], name2[10];
int t;

bool cmp(const Gang &a, const Gang &b) {
    return strcmp(a.head, b.head) <= 0;
}

int findHead(int m) {
    int hidx = m;
    while (ms[hidx].head >= 0) {
        hidx = ms[hidx].head;
    }
    return hidx;
}

int update(char name[], int t) {
    int i;
    for (i =0; i < nmem; ++i) {
        if (strcmp(name, ms[i].name) == 0) {
            break;
        }
    }
    if (i != nmem) {
        ms[i].weight += t;
        int hidx = findHead(i);
        if (ms[hidx].weight < ms[i].weight) {
            ms[i].head = ms[hidx].head;
            ms[hidx].head = i;
        }
    } else {
        ms[i].head = -1;
        ms[i].weight = t;
        ms[i].total = 0;
        strcpy(ms[i].name, name);
        nmem++;
    }
    return i;
}

void mergeMember(int m1, int m2) {
    int h1 = findHead(m1);
    int h2 = findHead(m2);
    if (h1 != h2) {
        if (ms[h1].weight < ms[h2].weight) {
            ms[h2].head += ms[h1].head;
            ms[h1].head = h2;
        } else {
            ms[h1].head += ms[h2].head;
            ms[h2].head = h1;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", name1, name2, &t);
        int m1 = update(name1, t);
        int m2 = update(name2, t);
        mergeMember(m1, m2);
    }

    for (int i = 0; i < nmem; ++i) {
        if (ms[i].head >= 0) {
            int hidx = findHead(i);
            ms[hidx].total += ms[i].weight;
        } else {
            ms[i].total += ms[i].weight;
        }
    }

    for (int i = 0; i < nmem; ++i) {
        if (ms[i].total > 2 * k && ms[i].head < -2) {
            strcpy(gs[ngang].head, ms[i].name);
            gs[ngang++].gsize = -ms[i].head;
        }
    }
    sort(gs, gs+ngang, cmp);
    printf("%d\n", ngang);
    for (int i = 0; i < ngang; ++i) {
        printf("%s %d\n", gs[i].head, gs[i].gsize);
    }
    return 0;
}
