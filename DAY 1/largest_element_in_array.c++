#include <bits/stdc++.h>
class Solution {
    public:
        int findLargest(vector<int>& nums, int k) {
            int largest = nums[0];
            for (int i = 0; i < k ; i++ ){
                if (nums[i] > largest){
                    largest = nums[i];
                }
            }
            return largest ;
        }
    };