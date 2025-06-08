class Solution {
    public:
        bool canSplit(vector<int>& nums, int m, int maxSum) {
            int count = 1, sum = 0;
            for (int num : nums) {
                if (sum + num > maxSum) {
                    count++;
                    sum = num;
                    if (count > m) return false;
                } else {
                    sum += num;
                }
            }
            return true;
        }
        
        int splitArray(vector<int>& nums, int m) {
            int left = *max_element(nums.begin(), nums.end());
            int right = accumulate(nums.begin(), nums.end(), 0);
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (canSplit(nums, m, mid)) right = mid;
                else left = mid + 1;
            }
            return left;
        }
    };
    