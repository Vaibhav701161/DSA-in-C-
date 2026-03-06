/*
 * DAY 71: Three Sum (Two Pointers)
 *
 * Problem Statement:
 * Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
 * such that i != j != k and nums[i] + nums[j] + nums[k] == 0.
 *
 * Approach: Sort array, then for each element use two pointers (left, right) to
 * find pairs that sum to the negation of the current element. Skip duplicates.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1) excluding output
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left]  == nums[left+1])  left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if (sum < 0) left++;
            else right--;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    for (auto& t : res)
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "]" << endl;
    return 0;
}
