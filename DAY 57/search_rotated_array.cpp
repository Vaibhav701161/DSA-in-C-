/*
 * DAY 57: Search in Rotated Sorted Array
 *
 * Problem Statement:
 * Given a sorted array that has been rotated at some unknown pivot index,
 * and a target value, return the index of target if found, else return -1.
 *
 * Approach: Modified binary search. Determine which half is sorted,
 * check if target lies in that half, then narrow the search accordingly.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0, high = (int)nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Index of 0: " << search(nums, 0) << endl; // 4
    cout << "Index of 3: " << search(nums, 3) << endl; // -1
    return 0;
}
