#include <iostream>
#include <stdio.h>

using namespace std;

int order[1005];
int postorder[1005];
int cur = 0;
int n;
int m = 0;

bool isbst(int lo, int hi) {

    if (hi - lo <= 1) { return true; }

    int root = order[lo];
    int lobound, hibound;
    for (lobound = lo+1; lobound < hi; ++lobound) {
        if (order[lobound] >= root) { break; }
    }

    for (hibound = lobound; hibound < hi; ++hibound) {
        if (order[hibound] < root) { break; }
    }

    if (hibound != hi) { return false; }

    return isbst(lo+1, lobound) && isbst(lobound, hibound);
}

bool ismbst(int lo, int hi) {
    if (hi - lo <= 1) { return true; }
    int root = order[lo];
    int lobound, hibound;
    for (lobound = lo+1; lobound < hi; ++lobound) {
        if (order[lobound] < root) { break; }
    }

    for (hibound = lobound; hibound < hi; ++hibound) {
        if (order[hibound] >= root) { break; }
    }

    if (hibound != hi) { return false; }

    return ismbst(lo+1, lobound) && ismbst(lobound, hibound);
}

void bst_postorder(int lo, int hi) {
    if (hi - lo <= 0) { return; }
    if (hi - lo == 1) {
        postorder[cur++] = order[lo];
        return;
    }
    int lobound;
    for (lobound = lo+1; lobound < hi; ++lobound) {
        if (order[lobound] >= order[lo]) { break; }
    }
    bst_postorder(lo+1, lobound);
    bst_postorder(lobound, hi);
    postorder[cur++] = order[lo];
}

void mbst_postorder(int lo, int hi) {
    if (hi - lo <= 0) { return; }
    if (hi - lo == 1) {
        postorder[cur++] = order[lo];
        return;
    }
    int lobound;
    for (lobound = lo+1; lobound < hi; ++lobound) {
        if (order[lobound] < order[lo]) { break; }
    }
    mbst_postorder(lo+1, lobound);
    mbst_postorder(lobound, hi);
    postorder[cur++] = order[lo];
}

int main() {
    freopen("in1.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &order[i]);
    }
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", order[i]);
//    }
    bool ans = false;
    if (isbst(0, n)) {
        bst_postorder(0, n);
        ans = true;
    } else if (ismbst(0, n)) {
        mbst_postorder(0, n);
        ans = true;
    }
    if (ans) {
        printf("YES\n");
        for (int i = 0; i < n - 1; ++i) {
            printf("%d ", postorder[i]);
        }
        printf("%d\n", postorder[cur-1]);
    } else {
        printf("NO\n");
    }
    return 0;
}
