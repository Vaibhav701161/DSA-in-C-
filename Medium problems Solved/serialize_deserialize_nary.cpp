// serialize_deserialize_nary.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int v): val(v) {}
};

string serialize(Node* root) {
    // Preorder: val [child_count] <children...>
    if (!root) return "# ";
    ostringstream out;
    out << root->val << ' ' << root->children.size() << ' ';
    for (auto ch : root->children) out << serialize(ch);
    return out.str();
}

Node* deserializeHelper(istringstream& in) {
    string token;
    if (!(in >> token)) return nullptr;
    if (token == "#") return nullptr;
    int val = stoi(token);
    int cnt; in >> cnt;
    Node* node = new Node(val);
    for (int i = 0; i < cnt; ++i) node->children.push_back(deserializeHelper(in));
    return node;
}

Node* deserialize(const string& data) {
    istringstream in(data);
    return deserializeHelper(in);
}

// helpers to build small tree and print
void printNary(Node* root, int depth=0) {
    if (!root) return;
    cout << string(depth*2, ' ') << root->val << '\n';
    for (auto c : root->children) printNary(c, depth+1);
}
void freeTree(Node* root) {
    if (!root) return;
    for (auto c : root->children) freeTree(c);
    delete root;
}

int main() {
    // build sample tree:
    //      1
    //    / | \
    //   2  3  4
    //     / \
    //    5   6
    Node* root = new Node(1);
    root->children.push_back(new Node(2));
    Node* n3 = new Node(3);
    n3->children.push_back(new Node(5));
    n3->children.push_back(new Node(6));
    root->children.push_back(n3);
    root->children.push_back(new Node(4));

    string s = serialize(root);
    cout << "Serialized: " << s << '\n';
    Node* d = deserialize(s);
    cout << "Deserialized tree:\n";
    printNary(d);
    freeTree(root); freeTree(d);
    return 0;
}
