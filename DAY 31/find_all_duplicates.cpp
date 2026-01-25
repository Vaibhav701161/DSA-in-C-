/*
 * DAY 31: Find All Duplicates in an Array
 *
 * Problem Statement:
 * Given an integer array nums of length n where all integers are in range [1, n]
 * and each integer appears once or twice, return an array of all integers that
 * appear twice.
 *
 * Approach:
 * Use the array itself as a hash map. For each element, negate the value at
 * index (abs(nums[i]) - 1). If we find a negative value already there, it means
 * the number has appeared before, so add it to the result list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) (excluding output)
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < (int)nums.size(); i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            result.push_back(idx + 1);
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = findDuplicates(nums);
    cout << "Duplicates: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
