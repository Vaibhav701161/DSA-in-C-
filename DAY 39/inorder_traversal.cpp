/*
 * DAY 39: Binary Tree Inorder Traversal
 *
 * Problem Statement:
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values (left -> root -> right).
 *
 * Approach:
 * Iterative approach using a stack to simulate the recursion.
 * Push left children until null, then process node, then go right.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}

int main() {
    // Tree: 1 -> right: 2 -> left: 3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = inorderTraversal(root);
    cout << "Inorder: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
