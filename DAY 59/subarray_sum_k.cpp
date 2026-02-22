/*
 * DAY 59: Subarray Sum Equals K
 *
 * Problem Statement:
 * Given an array of integers nums and an integer k, return the total number
 * of subarrays whose sum equals k.
 *
 * Approach: Prefix sum + hashmap. For each index, check if (prefixSum - k)
 * has been seen before. If yes, those subarrays sum to k.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixCount.count(sum - k))
            count += prefixCount[sum - k];
        prefixCount[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << "Count (k=2): " << subarraySum(nums, 2) << endl; // 2

    vector<int> nums2 = {1, 2, 3};
    cout << "Count (k=3): " << subarraySum(nums2, 3) << endl; // 2
    return 0;
}
