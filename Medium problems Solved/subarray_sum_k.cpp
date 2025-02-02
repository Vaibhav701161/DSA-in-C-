// subarray_sum_k.cpp
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums,int k){
    unordered_map<int,int> mp; mp[0]=1;
    int sum=0,count=0;
    for(int x:nums){
        sum+=x;
        if(mp.count(sum-k)) count+=mp[sum-k];
        mp[sum]++;
    }
    return count;
}

int main(){
    vector<int> nums={1,2,3};
    int k=3;
    cout<<"Subarrays with sum k: "<<subarraySum(nums,k)<<'\n';
}
void printSolution(const vector<vector<string>>& solutions) {
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            cout << row << '\n';
        }
        cout << "----\n";
    }
}