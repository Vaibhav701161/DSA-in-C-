/*
 * DAY 53: Longest Increasing Subsequence (LIS)
 *
 * Problem Statement:
 * Given an integer array nums, return the length of the longest strictly
 * increasing subsequence.
 *
 * Approach: Binary search + patience sorting. Maintain a tails array where
 * tails[i] is the smallest tail element of all IS of length i+1.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) tails.push_back(num);
        else *it = num;
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lengthOfLIS(nums) << endl; // 4
    return 0;
}
