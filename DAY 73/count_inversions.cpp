/*
 * DAY 73: Count Inversions (Divide and Conquer)
 *
 * Problem Statement:
 * Given an array, count the number of inversions. An inversion is a pair (i, j)
 * such that i < j but arr[i] > arr[j].
 *
 * Approach: Modified merge sort. During the merge step, when we pick from the
 * right subarray before left, all remaining elements in left form inversions.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

long long mergeCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long inv = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) { temp.push_back(arr[i++]); }
        else {
            inv += (mid - i + 1); // all remaining left elements form inversions
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)  temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
    return inv;
}

long long countInversions(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long inv = 0;
    inv += countInversions(arr, left, mid);
    inv += countInversions(arr, mid + 1, right);
    inv += mergeCount(arr, left, mid, right);
    return inv;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    int n = arr.size();
    cout << "Inversions: " << countInversions(arr, 0, n - 1) << endl; // 6
    return 0;
}
