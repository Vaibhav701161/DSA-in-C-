/*
128. Longest Consecutive Sequence
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

// Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
int longest =1;
int cnt = 1;
for (int i = 0 ; i<n ; i++){
    int x = nums[i];
    cnt = 1;
    while (ls(x+1,nums)){
        x++;
        cnt++;
    }
    longest = max(longest,cnt);
}
}


// Using Sorting
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size() == 0) return 0;
            sort(nums.begin(), nums.end());
            int longest = 1;
            int cnt = 0 ;
            int lastSmallest = INT_MIN;
    
            for (int i =0 ; i <nums.size(); i++ ){
                if(nums[i] - 1 == lastSmallest){
                    cnt = cnt+1;
                    lastSmallest = nums[i];
                } else if(nums[i] != lastSmallest){
                    cnt = 1;
                    lastSmallest = nums[i];
    
                }
                longest = max(longest,cnt);
            }
    
            return longest;
    
        }
    };