/*
 * DAY 42: Lowest Common Ancestor of a Binary Tree
 *
 * Problem Statement:
 * Given a binary tree and two nodes p and q, find their Lowest Common Ancestor (LCA).
 * The LCA is the deepest node that is an ancestor of both p and q.
 *
 * Approach: Recursive post-order DFS.
 * If root is null or equals p or q, return root.
 * Recurse left and right; if both return non-null, current root is LCA.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left   = new TreeNode(6);
    root->left->right  = new TreeNode(2);
    root->right->left  = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* p = root->left;        // node 5
    TreeNode* q = root->right;       // node 1
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "LCA of 5 and 1: " << lca->val << endl; // 3
    return 0;
}
