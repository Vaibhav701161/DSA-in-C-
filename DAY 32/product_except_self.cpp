/*
 * DAY 32: Product of Array Except Self
 *
 * Problem Statement:
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all elements of nums except nums[i].
 * You must solve it without using division and in O(n) time.
 *
 * Approach:
 * Use prefix and suffix product arrays. First pass: compute prefix products
 * (product of all elements to the left). Second pass: multiply each element
 * by the suffix product (product of all elements to the right).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) (excluding output array)
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Prefix pass
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix pass
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    cout << "Product except self: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
