#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <assert.h>

using namespace std;

#define INF (24*3600)

struct Player {
     int arvt;
     int pt;
     int vip;
};

struct Table {
    int time;
    int counter;
    Table(): time(8*3600), counter(0) {}
};

int cmp(const Player &a, const Player &b) {
    return a.arvt < b.arvt;
}

void printTime(int t) {
    int h = t / 3600;
    int m = (t % 3600) / 60;
    int s = t % 60;
    printf("%02d:%02d:%02d", h, m, s);
}

Player ps[10010];
int vp[10010];
bool played[10010];
Table ts[110];
bool vt[110];

void getTable(int pi, int ti) {
    if (ts[ti].time <= ps[pi].arvt) {
        ts[ti].time = ps[pi].arvt;
    }
    if (ts[ti].time >= 21 * 3600) {
        return;
    }
    played[pi] = true;
    printTime(ps[pi].arvt);
    printf(" ");
    printTime(ts[ti].time);
    int wt = ((ts[ti].time - ps[pi].arvt) + 30 ) / 60;
    printf(" %d\n", wt);
    ts[ti].time += ps[pi].pt;
    ts[ti].counter++;
}

int main() {
    freopen("in.txt", "r", stdin);
    memset(played, false, sizeof(played));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        ps[i].arvt = h*3600 + m * 60 + s;
        scanf("%d %d", &ps[i].pt, &ps[i].vip);
        if (ps[i].pt > 120) { ps[i].pt = 120; }
        ps[i].pt *= 60;
    }
    sort(ps, ps+n, cmp);

    memset(vp, -1, sizeof(vp));
    int nvp = 0;
    for (int i = 0; i < n; ++i) {
        if (ps[i].vip) {
            vp[nvp++] = i;
        }
    }

    int nt, nvt;
    scanf("%d %d", &nt, &nvt);
    for (int i = 0; i < nvt; ++i) {
        int index;
        scanf("%d", &index);
        vt[index-1] = true;
    }
    int vpidx = 0;
    for (int i = 0; i < n; ) {
        if (played[i]) {
            ++i;
            continue;
        }

        bool full = true;
        int firstt = -1, firstvt = -1, mint = INF, nextt = -1;
        for (int j = 0; j < nt; ++j) {
            if (ts[j].time <= ps[i].arvt) {
                full = false;
                if (firstt == -1) {
                    firstt = j;
                }
                if (vt[j]) {
                    firstvt = j;
                    break;
                }
            }
            if (full && ts[j].time < mint) {
                nextt = j;
                mint = ts[j].time;
            }
        }
        //printf("full: %s\n", full ? "true" : "false");
        if (full) {
            if (vpidx < nvp && vt[nextt]
                && ps[vp[vpidx]].arvt < ts[nextt].time) {
                    getTable(vp[vpidx++], nextt);
                    continue;
            } else {
                if (ps[i].vip) { vpidx++; }
                getTable(i++, nextt);
            }
        } else {
            if (ps[i].vip) {
               assert(vp[vpidx] == i);
                if (firstvt != -1) {
                    getTable(i++, firstvt);
                } else {
                    getTable(i++, firstt);
                }
                vpidx++;
            } else {
                getTable(i++, firstt);
            }
        }
    }

    for (int i = 0; i < nt - 1; ++i) {
        printf("%d ", ts[i].counter);
    }
    printf("%d\n", ts[nt-1].counter);
    return 0;
}
