/*
 * DAY 44: Kth Smallest Element in BST
 *
 * Problem Statement:
 * Given the root of a BST and an integer k, return the kth smallest value
 * among all the values of the nodes in the tree.
 *
 * Approach: Inorder traversal of BST yields elements in sorted order.
 * Use iterative inorder traversal and count until the kth element.
 *
 * Time Complexity: O(H + k) where H is tree height
 * Space Complexity: O(H)
 */
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    int count = 0;
    while (curr || !st.empty()) {
        while (curr) { st.push(curr); curr = curr->left; }
        curr = st.top(); st.pop();
        if (++count == k) return curr->val;
        curr = curr->right;
    }
    return -1;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left  = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left  = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    cout << "3rd smallest: " << kthSmallest(root, 3) << endl; // 3
    return 0;
}
