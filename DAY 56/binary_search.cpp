/*
 * DAY 56: Binary Search
 *
 * Problem Statement:
 * Given a sorted array and a target value, return the index of the target
 * in O(log n) time. Return -1 if the target is not found.
 *
 * Approach: Iterative binary search. Maintain low and high pointers.
 * Compute mid, compare with target, and narrow the search space.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = (int)nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << "Index of 9: " << binarySearch(nums, 9) << endl;   // 4
    cout << "Index of 2: " << binarySearch(nums, 2) << endl;   // -1
    return 0;
}
