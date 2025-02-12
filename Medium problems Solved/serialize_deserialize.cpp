// serialize_deserialize.cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val; TreeNode*left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

string serialize(TreeNode* root){
    if(!root) return "#";
    return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
}

TreeNode* deserializeHelper(queue<string>&q){
    string s=q.front();q.pop();
    if(s=="#") return NULL;
    TreeNode* node=new TreeNode(stoi(s));
    node->left=deserializeHelper(q);
    node->right=deserializeHelper(q);
    return node;
}

TreeNode* deserialize(string data){
    stringstream ss(data);
    string token;
    queue<string> q;
    while(getline(ss,token,',')) q.push(token);
    return deserializeHelper(q);
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    string s=serialize(root);
    cout<<"Serialized: "<<s<<'\n';
    TreeNode* d=deserialize(s);
    cout<<"Root after deserialization: "<<d->val<<'\n';
}
