/*
 * DAY 69: Maximum Sum Subarray of Size K (Sliding Window)
 *
 * Problem Statement:
 * Given an array of integers and a number k, find the maximum sum of a
 * contiguous subarray of size k.
 *
 * Approach: Sliding window. Compute sum of first k elements, then slide the
 * window right by adding the next element and subtracting the first element.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubarrayK(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];
    int maxSum = windowSum;
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    cout << "Max sum (k=3): " << maxSumSubarrayK(arr, 3) << endl; // 9

    vector<int> arr2 = {2, 3, 4, 1, 5};
    cout << "Max sum (k=2): " << maxSumSubarrayK(arr2, 2) << endl; // 7
    return 0;
}
