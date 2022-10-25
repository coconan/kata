#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct TNode {
     int data;
     TNode *left;
     TNode *right;
     int height;
};

int getHeight(TNode *root) {
     if (root) return root->height;
     return 0;
}

TNode *rebalance(TNode *root) {
    int lh, rh;
    lh = getHeight(root->left);
    rh = getHeight(root->right);
    if (lh > rh) {
        TNode *lc = root->left;
        //cout << "lh: " << lh << " rh: " << rh << endl;
        int lclh, lcrh;
        lclh = getHeight(lc->left);
        lcrh = getHeight(lc->right);
        //cout << "lclh: " << lclh << " lcrh: " << lcrh << endl;
        if (lclh > lcrh) {
            //cout << "lc: " << lc->data << endl;
            root->left = lc->right;
            lc->right = root;
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
            lc->height = max(getHeight(lc->left), getHeight(lc->right)) + 1;
            return lc;
        } else {
            TNode *newroot = lc->right;
            root->left = newroot->right;
            lc->right = newroot->left;
            newroot->left = lc;
            newroot->right = root;
            lc->height = max(getHeight(lc->left), getHeight(lc->right)) + 1;
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
            newroot->height = max(getHeight(newroot->left), getHeight(newroot->right)) + 1;
            return newroot;
        }
    } else {
        TNode *rc = root->right;
        int rclh = getHeight(rc->left);
        int rcrh = getHeight(rc->right);
        if (rcrh > rclh) {
            root->right = rc->left;
            rc->left = root;
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
            rc->height = max(getHeight(rc->left), getHeight(rc->right)) + 1;
            return rc;
        } else {
           TNode *newroot = rc->left;
           root->right = newroot->left;
           rc->left = newroot->right;
           newroot->left = root;
           newroot->right = rc;
           rc->height = max(getHeight(rc->left), getHeight(rc->right)) + 1;
           root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
           newroot->height = max(getHeight(newroot->left), getHeight(newroot->right)) + 1;
           return newroot;
        }
    }
}

TNode *treeInsert(TNode *root, int data) {
     if (root == NULL) {
        root = new TNode;
        root->data = data;
        root->height = 1;
        root->left = NULL;
        root->right = NULL;
        return root;
     }
     if (data < root->data) {
        root->left = treeInsert(root->left, data);
     } else {
        root->right = treeInsert(root->right, data);
     }
     root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
     //cout << "root " << root->data << " h: " << root->height << endl;
     int lh = getHeight(root->left);
     int rh = getHeight(root->right);
     if (lh - rh < -1 || lh - rh > 1) {
        return rebalance(root);
     } else {
        return root;
     }
}


int main() {
    TNode *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = treeInsert(root, data);
        //cout << root->data << endl;
    }
    cout << root->data << endl;
    return 0;
}
