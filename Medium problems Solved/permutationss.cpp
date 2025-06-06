#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start+1);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    auto result = sol.permute(nums);
    cout << "Permutations:\n";
    for (auto &perm : result) {
        for (int x : perm) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
