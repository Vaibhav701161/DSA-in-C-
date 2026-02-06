/*
 * DAY 43: Validate Binary Search Tree
 *
 * Problem Statement:
 * Given the root of a binary tree, determine if it is a valid BST.
 * A valid BST: left subtree contains only nodes with keys < node's key,
 * right subtree contains only nodes with keys > node's key.
 *
 * Approach: Recursive with min/max bounds. Pass valid range for each node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool validate(TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return validate(node->left,  minVal,    node->val) &&
           validate(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left  = new TreeNode(2);
    root->left->right = new TreeNode(4);
    cout << "Valid BST: " << isValidBST(root) << endl; // 1

    TreeNode* invalid = new TreeNode(5);
    invalid->left  = new TreeNode(1);
    invalid->right = new TreeNode(4);
    invalid->right->left  = new TreeNode(3);
    invalid->right->right = new TreeNode(6);
    cout << "Valid BST: " << isValidBST(invalid) << endl; // 0
    return 0;
}
