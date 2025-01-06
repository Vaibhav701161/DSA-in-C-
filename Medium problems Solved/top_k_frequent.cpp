/*
Top K Frequent Elements (heap)

Problem: Given nums, return k most frequent elements.
*/

// top_k_frequent.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Top K Frequent Elements:
  - Count freq, use min-heap of size k.
  - Time: O(n log k).
*/

vector<int> topKFrequent(vector<int>& nums,int k) {
    unordered_map<int,int> freq;
    for(int x:nums) freq[x]++;
    using pii=pair<int,int>;
    auto cmp=[](pii&a,pii&b){return a.second>b.second;};
    priority_queue<pii,vector<pii>,decltype(cmp)> pq(cmp);
    for(auto&kv:freq) {
        pq.push(kv);
        if((int)pq.size()>k) pq.pop();
    }
    vector<int> res;
    while(!pq.empty()) {res.push_back(pq.top().first);pq.pop();}
    return res;
}

int main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    auto ans=topKFrequent(nums,k);
    cout<<"Top "<<k<<" frequent: ";
    for(int x:ans) cout<<x<<' ';
    cout<<'\n';
}
