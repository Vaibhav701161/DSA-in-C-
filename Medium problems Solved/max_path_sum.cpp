// max_path_sum.cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val; TreeNode*left,*right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};

int dfs(TreeNode* root,int &maxSum){
    if(!root) return 0;
    int l=max(0,dfs(root->left,maxSum));
    int r=max(0,dfs(root->right,maxSum));
    maxSum=max(maxSum,l+r+root->val);
    return root->val+max(l,r);
}

int maxPathSum(TreeNode* root){
    int maxSum=INT_MIN;
    dfs(root,maxSum);
    return maxSum;
}

int main(){
    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<"Max Path Sum: "<<maxPathSum(root)<<'\n';
}
