#include <bits/stdc++.h>
using namespace std;

// Problem: Upper Bound

class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) res = max(res, nums[i]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3,1,4,1,5,9,2,6};
    cout << sol.solve(v) << "\n";
}
