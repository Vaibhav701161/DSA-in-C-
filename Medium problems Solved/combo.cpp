#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int>& candidates, int start, int target, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            backtrack(candidates, i+1, target - candidates[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(candidates, 0, target, temp);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = sol.combinationSum2(nums, target);
    cout << "Combinations:\n";
    for (auto &comb : ans) {
        for (auto x : comb) cout << x << " ";
        cout << endl;
    }
    return 0;
}
