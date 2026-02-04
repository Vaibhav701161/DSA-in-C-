/*
 * DAY 41: Height of Binary Tree
 *
 * Problem Statement:
 * Given the root of a binary tree, return its maximum depth (height).
 * The maximum depth is the number of nodes along the longest path from root
 * to the farthest leaf node.
 *
 * Approach: Recursive DFS. Height = 1 + max(leftHeight, rightHeight).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h) where h is tree height
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Height: " << maxDepth(root) << endl; // 3
    return 0;
}
