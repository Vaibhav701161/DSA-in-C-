// rotated_array_search.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Binary search with rotation pivot logic.
  Time: O(log n).
*/

int search(vector<int>& nums,int t){
    int l=0,r=nums.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==t) return mid;
        if(nums[l]<=nums[mid]){
            if(t>=nums[l] && t<nums[mid]) r=mid-1;
            else l=mid+1;
        }else{
            if(t>nums[mid] && t<=nums[r]) l=mid+1;
            else r=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    cout<<"Target found at index: "<<search(nums,0)<<'\n';
}
