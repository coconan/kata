#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct TNode {
     TNode *left;
     TNode *right;
     int data;
};

int power2[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
int v[1050];
int level[1050];

int log2bottom(int n) {
    int i, p;
    for (i = 0, p = 1; p <= n; ++i, p *= 2);
    return i-1;
}

TNode *buildtree(int lo, int hi) {
     //printf("lo=%d hi=%d\n", lo, hi);
     if (hi <= lo) return NULL;
     if (hi - lo == 1) {
        TNode *root = new TNode;
        root->data =  v[lo];
        root->left = NULL;
        root->right = NULL;
        return root;
     }
     TNode *root = new TNode;
     int subn = hi-lo;
     int log2n = log2bottom(subn);
     int split;
     if (subn - (power2[log2n]-1) >= power2[log2n-1]) {
        split = power2[log2n] - 1;
     } else {
        split = subn - power2[log2n-1];
     }
     //printf("split=%d\n", split); //return NULL;
     root->data = v[lo+split];
     root->left = buildtree(lo, lo+split);
     root->right = buildtree(lo+split+1, hi);
     return root;
}

void inorder(TNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void levelorder(TNode *root) {
     queue<TNode *> q;
     q.push(root);
     int cur = 0;
     while (!q.empty()) {
        TNode *ptr = q.front();
        q.pop();
        //printf("%d ", ptr->data);
        level[cur++] = ptr->data;
        if (ptr->left) {
            q.push(ptr->left);
        }
        if (ptr->right) {
            q.push(ptr->right);
        }
     }
}

int n;
int main() {
    scanf("%d", &n);
    //printf("%d\n", log2bottom(n));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    TNode *root = buildtree(0, n);
    //inorder(root);
    //printf("\n");
    levelorder(root);
    printf("%d", level[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", level[i]);
    }
    printf("\n");
    //buildtree(0, n);
    return 0;
}
