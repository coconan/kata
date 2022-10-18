#include <iostream>
#include <stdio.h>

using namespace std;

struct Node {
    int next;
    char c;
};

Node mem[100005];

int main() {
    freopen("in1.txt", "r", stdin);
    int h1, h2, n, addr;
    scanf("%d %d %d", &h1, &h2, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &addr);
        scanf(" %c %d", &mem[addr].c, &mem[addr].next);
        //printf("%06d %c %06d\n", addr, mem[addr].c, mem[addr].next);
    }

    int p1 = h1, p2 = h2, len1 = 0, len2 = 0;
    while (p1 != -1) {
        p1 = mem[p1].next;
        len1++;
    }

    while (p2 != -1) {
        p2 = mem[p2].next;
        len2++;
    }

    int d;
    if (len1 < len2) {
        p1 = h2;
        p2 = h1;
        d = len2 - len1;
    } else {
        p1 = h1;
        p2 = h2;
        d = len1 - len2;
    }

    int c = 0;

    while (c++ < d) {
        p1 = mem[p1].next;
    }

    while(p1 != -1 && p1 != p2) {
        p1 = mem[p1].next;
        p2 = mem[p2].next;
    }
    if (p1 != -1) {
        printf("%05d\n", p1);
    } else {
        printf("-1\n");
    }
    return 0;
}
