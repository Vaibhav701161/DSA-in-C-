/*
Kth Smallest Element in a BST (augmented with node counts)

Problem: Given a BST, find k-th smallest element. Implement iterative solution using subtree sizes stored in nodes.
*/

// kth_smallest_bst.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Kth smallest in BST using node counts stored in each node.
  This file includes utilities to build BST and add counts.
*/

struct Node {
    int val;
    Node *left, *right;
    int cnt; // size of subtree rooted at this node
    Node(int v): val(v), left(nullptr), right(nullptr), cnt(1) {}
};

int sizeOf(Node* t) { return t ? t->cnt : 0; }

Node* insertNode(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    root->cnt = 1 + sizeOf(root->left) + sizeOf(root->right);
    return root;
}

int kthSmallest(Node* root, int k) {
    if (!root) return -1; // invalid
    Node* cur = root;
    while (cur) {
        int leftSize = sizeOf(cur->left);
        if (k == leftSize + 1) return cur->val;
        else if (k <= leftSize) cur = cur->left;
        else {
            k -= leftSize + 1;
            cur = cur->right;
        }
    }
    return -1; // not found
}

void freeTree(Node* t) {
    if (!t) return;
    freeTree(t->left); freeTree(t->right); delete t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vals = {20,8,22,4,12,10,14};
    Node* root = nullptr;
    for (int v : vals) root = insertNode(root, v);
    for (int k = 1; k <= (int)vals.size(); ++k) {
        cout << k << "th smallest: " << kthSmallest(root, k) << '\n';
    }
    freeTree(root);
    return 0;
}
