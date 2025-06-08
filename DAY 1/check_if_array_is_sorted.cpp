class Solution {
    public:
        bool check(vector<int>& nums) {
                for (int i = 1; i < nums.size() ; i++) {
            if (nums[i] >= nums[i - 1]) {
                
            } else {
                return false;
            }
        }
        return 1;
    
        }
    };