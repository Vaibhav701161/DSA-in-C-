#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start, vector<int>& temp) {
        res.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums, i+1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        backtrack(nums, 0, temp);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    auto result = sol.subsetsWithDup(nums);
    cout << "Unique Subsets:\n";
    for (auto &subset : result) {
        cout << "[";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
