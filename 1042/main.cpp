#include <iostream>
#include <stdio.h>

using namespace std;

int slots1[60];
int slots2[60];
int order[60];
int k;
char mapx[] = {'\0', 'S', 'H', 'C', 'D', 'J'};

void myshuffle(int *src, int *dest) {
    for (int i = 1; i <= 54; ++i) {
        dest[order[i]] = src[i];
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    for (int i = 1; i <= 13; ++i) {
        slots1[i] = 100+i;
        slots1[i+13] = 200+i;
        slots1[i+26] = 300+i;
        slots1[i+39] = 400+i;
    }
    slots1[53] = 501;
    slots1[54] = 502;
    //for (int i = 1; i <= 54; ++i) {
    //    printf("%c%d ", mapx[slots1[i]/100], slots1[i]%100);
    //}
    //printf("\n");
    scanf("%d", &k);
    for (int i = 1; i <= 54; ++i) {
        scanf("%d", &order[i]);
    }
    int *src = slots1;
    int *dest = slots2;
    int *temp;
    for (int i = 0; i < k; ++i) {
        myshuffle(src, dest);
        temp = src;
        src = dest;
        dest = temp;
    }
    for (int i = 1; i <= 53; ++i) {
        printf("%c%d ", mapx[src[i]/100], src[i]%100);
    }
    printf("%c%d\n", mapx[src[54]/100], src[54]%100);
    return 0;
}
