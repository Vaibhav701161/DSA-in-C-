/*
Kth Largest in Stream (min-heap)

Problem: Design class to add numbers and return kth largest element.
*/

// kth_largest_stream.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Kth Largest in Stream using min-heap of size k.
*/

class KthLargest{
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums):k(k){
        for(int x:nums) add(x);
    }
    int add(int val){
        pq.push(val);
        if((int)pq.size()>k) pq.pop();
        return pq.top();
    }
};

int main(){
    vector<int> nums={4,5,8,2};
    KthLargest kth(3,nums);
    cout<<kth.add(3)<<'\n'; //4
    cout<<kth.add(5)<<'\n'; //5
}
