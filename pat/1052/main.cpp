#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Node {
    int addr, key;
};

int nextaddr[100005];
int key[100005];
Node l[100005];
int n, head, addr;

bool cmp(const Node &a, const Node &b) {
    return a.key < b.key;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &head);
    for (int i = 0; i < n; ++i) {
         scanf("%d", &addr);
         scanf("%d %d",  &key[addr], &nextaddr[addr]);
    }

    n = 0;
    while (head != -1) {
        l[n].addr = head;
        l[n++].key = key[head];
        head = nextaddr[head];
    }
    if (n == 0) { printf("0 -1\n"); }
    else {
        sort(l, l+n, cmp);
        head = l[0].addr;
        printf("%d %05d\n", n, head);
        for (int i = 0; i < n-1; ++i) {
            printf("%05d %d %05d\n", l[i].addr, l[i].key, l[i+1].addr);
        }
        printf("%05d %d -1\n", l[n-1].addr, l[n-1].key);
    }
    return 0;
}
