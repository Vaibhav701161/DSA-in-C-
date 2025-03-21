/*
169. Majority Element
Attempted
Easy
Topics
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

//Brute force approach
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i<n; i++){
              int  cnt = 0 ;
    
            
            for(int j =  0 ; j<n ; j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
                if(cnt > n/2){
                    return nums[i];
                }
            }
            
        return -1;
        }
    };

    // better approach
    class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                map<int , int> mpp;
                int n = nums.size();
        
                for (int i = 0; i<n ; i++){
                    mpp[nums[i]]++;
                }
        
                for (auto it: mpp){
                    if (it.second > (n/2)){
                        return it.first;
                    }
                }
                return -1;
                
            }
        };

//Optimal approach
        class Solution {
            public:
                int majorityElement(vector<int>& nums) {
                    int cnt = 0;
                    int el;
                    int n = nums.size();
                            for(int i = 0 ; i<n ; i++){
                        if(cnt == 0){
                             el=nums[i] ;
            
                        }
                        else if(nums[i] == el){
                            cnt++;
                        }
                        else{cnt--;}
                    }
            
                    int cnt1 = 0;
                    for(int i = 0; i<n;i++){
                        if(nums[i] == el){cnt1++;}
                        if(cnt1 > (n/2)){return el;}
            
                    }
                    return -1;
                    
                    
                }
            };