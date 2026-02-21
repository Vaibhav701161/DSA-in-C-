/*
 * DAY 58: Two Sum Using HashMap
 *
 * Problem Statement:
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers that add up to target. Each input has exactly one solution.
 *
 * Approach: Use an unordered_map to store each number and its index.
 * For each element, check if (target - element) already exists in the map.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;  // value -> index
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement))
            return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum(nums, 9);
    cout << "Indices: [" << res[0] << ", " << res[1] << "]" << endl; // [0, 1]
    return 0;
}
