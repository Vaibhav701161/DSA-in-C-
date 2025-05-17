#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << "Kth largest element: " << sol.findKthLargest(nums, k);
    return 0;
}
