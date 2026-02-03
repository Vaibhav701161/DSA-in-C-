/*
 * DAY 40: Binary Tree Level Order Traversal (BFS)
 *
 * Problem Statement:
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values (i.e., from left to right, level by level).
 *
 * Approach:
 * Use a queue (BFS). Process all nodes at each level before moving to the next.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto res = levelOrder(root);
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    return 0;
}
