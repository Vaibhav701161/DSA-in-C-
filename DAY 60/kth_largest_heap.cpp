/*
 * DAY 60: Kth Largest Element Using Min-Heap
 *
 * Problem Statement:
 * Find the kth largest element in an unsorted array.
 *
 * Approach: Use a min-heap of size k. Iterate through the array: push element
 * into heap, if heap size exceeds k, pop the minimum. Final heap top is the
 * kth largest element.
 *
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k)
            minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest: " << findKthLargest(nums, 2) << endl; // 5

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "4th largest: " << findKthLargest(nums2, 4) << endl; // 4
    return 0;
}
