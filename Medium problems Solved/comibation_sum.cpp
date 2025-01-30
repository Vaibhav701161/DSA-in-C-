// combination_sum.cpp
#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>&c,int target,int start,vector<int>&path,vector<vector<int>>&res){
    if(target==0){ res.push_back(path); return; }
    for(int i=start;i<c.size() && c[i]<=target;i++){
        path.push_back(c[i]);
        backtrack(c,target-c[i],i,path,res);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates,int target){
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res; vector<int> path;
    backtrack(candidates,target,0,path,res);
    return res;
}

int main(){
    vector<int> c={2,3,6,7};
    int target=7;
    auto res=combinationSum(c,target);
    cout<<"Combinations:\n";
    for(auto &v:res){
        for(int x:v) cout<<x<<' '; cout<<'\n';
    }
}
