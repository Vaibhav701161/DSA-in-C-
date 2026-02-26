/*
 * DAY 63: Generate All Subsets (Power Set)
 *
 * Problem Statement:
 * Given an integer array nums with unique elements, return all possible subsets.
 * The solution set must not contain duplicate subsets.
 *
 * Approach: Recursive backtracking. At each index, choose to include or exclude
 * the element and recurse for remaining elements.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n * 2^n)
 */
#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto result = subsets(nums);
    cout << "All subsets:" << endl;
    for (auto& subset : result) {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < (int)subset.size()) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
