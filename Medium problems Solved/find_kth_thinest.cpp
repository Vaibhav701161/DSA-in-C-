#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << "Kth Largest Element: " << sol.findKthLargest(nums, 4);
    return 0;
}
