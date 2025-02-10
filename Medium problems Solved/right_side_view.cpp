// right_side_view.cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val; TreeNode *left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    queue<TreeNode*> q; q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode* node=q.front();q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(i==sz-1) res.push_back(node->val);
        }
    }
    return res;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(4);
    auto res=rightSideView(root);
    cout<<"Right side view: ";
    for(int x:res) cout<<x<<' ';
    cout<<'\n';
}
