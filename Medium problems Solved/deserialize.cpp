/*
Binary Tree: Serialize/Deserialize (Level order) + Zigzag Level Order

Problem: Implement serialize and deserialize for a binary tree (level order with null markers), and also implement zigzag level order traversal.
*/

// tree_serialize_zigzag.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Binary tree node, serialization/deserialization (level-order),
  and zigzag level order traversal.
*/

struct Node {
    int val;
    Node *left, *right;
    Node(int v=0): val(v), left(nullptr), right(nullptr) {}
};

// Serialize to string using level order with "null" markers
string serialize(Node* root) {
    if (!root) return "";
    ostringstream out;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        if (!cur) {
            out << "null ";
            continue;
        }
        out << cur->val << ' ';
        q.push(cur->left);
        q.push(cur->right);
    }
    string s = out.str();
    // trim trailing "null " if desired (optional)
    return s;
}

// Deserialize
Node* deserialize(const string &data) {
    if (data.empty()) return nullptr;
    istringstream in(data);
    string tok;
    vector<string> tokens;
    while (in >> tok) tokens.push_back(tok);
    if (tokens.empty() || tokens[0] == "null") return nullptr;
    Node* root = new Node(stoi(tokens[0]));
    queue<Node*> q;
    q.push(root);
    int idx = 1;
    while (!q.empty() && idx < (int)tokens.size()) {
        Node* cur = q.front(); q.pop();
        if (tokens[idx] != "null") {
            cur->left = new Node(stoi(tokens[idx]));
            q.push(cur->left);
        }
        idx++;
        if (idx >= (int)tokens.size()) break;
        if (tokens[idx] != "null") {
            cur->right = new Node(stoi(tokens[idx]));
            q.push(cur->right);
        }
        idx++;
    }
    return root;
}

// Zigzag level order
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front(); q.pop();
            int idx = leftToRight ? i : (sz - 1 - i);
            level[idx] = cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}

// Helper to free tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Build a sample tree:
    //      1
    //     / \
    //    2   3
    //       / \
    //      4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    string s = serialize(root);
    cout << "Serialized tree: " << s << "\n";

    Node* r2 = deserialize(s);
    auto zig = zigzagLevelOrder(r2);
    cout << "Zigzag level order:\n";
    for (auto &lv : zig) {
        for (int v : lv) cout << v << ' ';
        cout << '\n';
    }
    freeTree(root);
    freeTree(r2);
    return 0;
}
