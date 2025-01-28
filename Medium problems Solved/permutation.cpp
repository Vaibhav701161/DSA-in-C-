// permutations.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Backtracking permutations generator.
*/

void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& used){
    if(path.size()==nums.size()){ res.push_back(path); return; }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue;
        used[i]=true; path.push_back(nums[i]);
        backtrack(nums,res,path,used);
        path.pop_back(); used[i]=false;
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(),false);
    backtrack(nums,res,path,used);
    return res;
}

int main(){
    vector<int> nums={1,2,3};
    auto res=permute(nums);
    cout<<"Permutations:\n";
    for(auto &v:res){
        for(int x:v) cout<<x<<' '; cout<<'\n';
    }
}
