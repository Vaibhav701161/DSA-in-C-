// lca_bt.cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val; TreeNode *left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
    if(!root || root==p || root==q) return root;
    TreeNode* L=lca(root->left,p,q);
    TreeNode* R=lca(root->right,p,q);
    if(L && R) return root;
    return L?L:R;
}

int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(1);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);
    TreeNode* ans=lca(root,root->left,root->right);
    cout<<"LCA of 5 & 1: "<<ans->val<<'\n';
}
