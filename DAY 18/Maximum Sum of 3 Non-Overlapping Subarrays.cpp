class Solution {
    public:
        vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> sum(n + 1, 0);
            for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];
            vector<int> left(n, 0), right(n, n - k);
            int total = sum[k] - sum[0];
            for (int i = k; i < n; ++i) {
                if (sum[i + 1] - sum[i + 1 - k] > total) {
                    left[i] = i + 1 - k;
                    total = sum[i + 1] - sum[i + 1 - k];
                } else {
                    left[i] = left[i - 1];
                }
            }
            total = sum[n] - sum[n - k];
            for (int i = n - k - 1; i >= 0; --i) {
                if (sum[i + k] - sum[i] >= total) {
                    right[i] = i;
                    total = sum[i + k] - sum[i];
                } else {
                    right[i] = right[i + 1];
                }
            }
            vector<int> res = {-1, -1, -1};
            total = 0;
            for (int i = k; i <= n - 2 * k; ++i) {
                int l = left[i - 1], r = right[i + k];
                int t = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);
                if (t > total) {
                    total = t;
                    res = {l, i, r};
                }
            }
            return res;
        }
    };
    