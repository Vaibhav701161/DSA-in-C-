/*
Subarray Sum Equals K (prefix sum + hashmap)

Problem: Given array nums and integer k, count subarrays with sum = k.
*/

// subarray_sum_k.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Subarray sum equals K using prefix sums + hashmap.
  Time: O(n).
*/

int subarraySum(vector<int>& nums,int k){
    unordered_map<int,int> mp;
    mp[0]=1;
    int sum=0, count=0;
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
    cout<<"Number of subarrays: "<<subarraySum(nums,k)<<'\n';
}
