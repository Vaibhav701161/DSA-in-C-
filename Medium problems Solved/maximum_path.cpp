// 36_max_path_sum.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  For each node, compute max path sum starting at node and going down (max of left/right + node).
  Global answer considers left + node + right as candidate.
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v=0): val(v), left(nullptr), right(nullptr) {}
};

long long dfsMax(TreeNode* node, long long &best) {
    if (!node) return 0;
    long long left = max(0LL, dfsMax(node->left, best));
    long long right = max(0LL, dfsMax(node->right, best));
    best = max(best, left + right + node->val);
    return node->val + max(left, right);
}

long long maxPathSum(TreeNode* root) {
    long long best = LLONG_MIN;
    dfsMax(root, best);
    return best;
}

// helper to free tree
void freeTree(TreeNode* r) {
    if (!r) return;
    freeTree(r->left); freeTree(r->right); delete r;
}

int main() {
    // build tree:
    //     -10
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Max path sum: " << maxPathSum(root) << '\n';

    freeTree(root);
    return 0;
}
