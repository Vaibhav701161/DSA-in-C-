#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, curr, res);
            curr.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    auto ans = sol.combinationSum(candidates, target);
    cout << "Combinations:\n";
    for (auto& comb : ans) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
    return 0;
}
