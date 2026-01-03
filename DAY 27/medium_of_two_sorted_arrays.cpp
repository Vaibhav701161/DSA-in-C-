/*
. Median of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int A_left  = (i == 0) ? INT_MIN : nums1[i - 1];
            int A_right = (i == m) ? INT_MAX : nums1[i];

            int B_left  = (j == 0) ? INT_MIN : nums2[j - 1];
            int B_right = (j == n) ? INT_MAX : nums2[j];

            if (A_left <= B_right && B_left <= A_right) {
                if ((m + n) % 2 == 0)
                    return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
                else
                    return max(A_left, B_left);
            }
            else if (A_left > B_right) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }
        return 0.0; 
    }
};
