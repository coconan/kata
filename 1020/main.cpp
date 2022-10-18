#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

int counter = 0;

Node *buildTree(vector<int> &postOrder, vector<int> &inOrder,
                int postLo, int postHi, int inLo, int inHi) {
    if (inHi - inLo <= 0) {
        return NULL;
    }
    int data = postOrder[postHi-1];
    int leftSize = 0;;
    for (int i = inLo; i < inHi; ++i, ++leftSize) {
        if (inOrder[i] == data) { break; }
    }
    Node *root = new Node;
    root->data = data;
    root->left = buildTree(postOrder, inOrder, postLo, postLo+leftSize, inLo, inLo+leftSize);
    root->right = buildTree(postOrder, inOrder, postLo+leftSize, postHi-1, inLo+leftSize+1, inHi);
    return root;
}

void inTraverse(Node *tree) {
    if (tree) {
        inTraverse(tree->left);
        cout << tree->data << " ";
        inTraverse(tree->right);
    }
}

void postTraverse(Node *tree) {
    if (tree) {
        postTraverse(tree->left);
        postTraverse(tree->right);
        cout << tree->data << " ";
    }
}

void levelTraverse(Node *tree) {
    queue<Node *> q;
    vector<int> levelOrder;
    if (tree) {
        q.push(tree);
        while (!q.empty()) {
            Node *root = q.front();
            levelOrder.push_back(root->data);
            q.pop();
            if (root->left) { q.push(root->left); }
            if (root->right) { q.push(root->right); }
        }
        cout << levelOrder[0];
        for (int i = 1; i < levelOrder.size(); ++i) {
            cout << " " << levelOrder[i];
        }
        cout << endl;
    }
}

int main() {
    //ifstream in("in.txt");
    //cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    vector<int> postOrder(n, 0), inOrder(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> postOrder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> inOrder[i];
    }
    Node *tree = buildTree(postOrder, inOrder, 0, n, 0, n);
    levelTraverse(tree);
    return 0;
}
