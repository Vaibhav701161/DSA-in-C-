/*
 * DAY 76: Serialize and Deserialize Binary Tree
 *
 * Problem Statement:
 * Design an algorithm to serialize a binary tree to a string and deserialize
 * that string back to the original tree.
 *
 * Approach: BFS (level-order) serialization. Use "null" for missing nodes.
 * Deserialization rebuilds the tree level by level using a queue.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    if (!root) return "";
    string result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        } else result += "null,";
    }
    return result;
}

TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;
    stringstream ss(data);
    string token;
    getline(ss, token, ',');
    TreeNode* root = new TreeNode(stoi(token));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (getline(ss, token, ',') && token != "null") {
            node->left = new TreeNode(stoi(token));
            q.push(node->left);
        }
        if (getline(ss, token, ',') && token != "null") {
            node->right = new TreeNode(stoi(token));
            q.push(node->right);
        }
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left  = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* restored = deserialize(serialized);
    cout << "Root after deserialize: " << restored->val << endl; // 1
    cout << "Left child: "             << restored->left->val  << endl; // 2
    cout << "Right child: "            << restored->right->val << endl; // 3
    return 0;
}
