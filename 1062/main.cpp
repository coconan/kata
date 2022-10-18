#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct Person {
    int id;
    int virtue;
    int talent;
    int total;
};

Person ps[100005];
int n, l, h, np = 0;

bool cmp(const Person &a, const Person &b) {
    if (a.virtue >= h && a.talent >= h && b.virtue >=h && b.talent >= h) {
        if (a.total == b.total) {
            if (a.virtue == b.virtue) {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    } else if (a.virtue >= h && a.talent >= h) {
        return true;
    } else if (b.virtue >= h && b.talent >= h) {
        return false;
    } else if (a.virtue >= h && a.talent < h && b.virtue >= h && b.talent < h) {
        if (a.total == b.total) {
            if (a.virtue == b.virtue) {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    } else if (a.virtue >= h && a.talent < h) {
        return true;
    } else if (b.virtue >= h && b.talent < h) {
        return false;
    } else if (a.virtue < h && a.talent < h && a.virtue >= a.talent
               && b.virtue < h && b.talent < h && b.virtue >= b.talent) {
        if (a.total == b.total) {
            if (a.virtue == b.virtue) {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    } else if (a.virtue < h && a.talent < h && a.virtue >= a.talent) {
        return true;
    } else if (b.virtue < h && b.virtue < h && b.virtue >= b.talent) {
        return false;
    } else {
        if (a.total == b.total) {
            if (a.virtue == b.virtue) {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.total > b.total;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &l, &h);
    for (int i = 0; i < n; ++i) {
        Person p;
        scanf("%d %d %d", &p.id, &p.virtue, &p.talent);
        if (p.virtue >= l && p.talent >= l) {
            ps[np].id = p.id;
            ps[np].virtue = p.virtue;
            ps[np].talent = p.talent;
            ps[np].total = p.virtue + p.talent;
            np++;
        }
    }
    printf("%d\n", np);
    sort(ps, ps+np, cmp);
    for (int i = 0; i < np; ++i) {
        printf("%08d %d %d\n", ps[i].id, ps[i].virtue, ps[i].talent);
    }
    return 0;
}
