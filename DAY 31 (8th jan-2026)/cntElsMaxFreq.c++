/*
3005. Count Elements With Maximum Frequency
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

 

Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(auto x:nums){
            umap[x]++;
        }
        
        int maxFreq =0;
        for (auto p:umap){
             maxFreq = max(maxFreq,p.second);
        } 

        int ans = 0;
        for (auto a : umap){
            if(a.second == maxFreq){
                ans+= a.second;
            }

        }
        return ans;

    }
};