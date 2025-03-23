/*
53. Maximum Subarray
Medium
Topics
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// brute force approach
// Time Complexity: O(n^3)

#include<bits/stdc++.h>
using namespace std;
for (int i =0; i<n;i++){
    for(int j = i ; j<n j++){
        int sum = 0 ;
        for (int k =i ; k<=j ; k++){
            sum += arr[k];
            maxi = max(maxi,sum);
        }
    }
}

// better approach
int maxi;
int sum = 0;
for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
        sum += arr[j];
        maxi = max(maxi,sum);
        if(sum<0) sum = 0;
    }
}

// kadane's algorithm
// Time Complexity: O(n)
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int sum =0;
            int maxi = INT_MIN;
            int n = nums.size();
            int ansStart =-1;
            int ansEnd = -1;
            int start =0;
    
            for (int i =0; i<n ; i++){
                if(sum ==0){start = i;}
                sum += nums[i];
                if(sum>maxi){
                    maxi = sum;
                    ansStart = start;
                    ansEnd = nums[i];
                }
                
                if(sum<0){
                    sum =0;
                }
            }
            return maxi;
        }
    };