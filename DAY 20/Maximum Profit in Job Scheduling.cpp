class Solution {
    public:
        static bool cmp(vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }
        
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n = startTime.size();
            vector<vector<int>> jobs(n, vector<int>(3));
            for (int i = 0; i < n; ++i) {
                jobs[i] = {startTime[i], endTime[i], profit[i]};
            }
            sort(jobs.begin(), jobs.end(), cmp);
            vector<int> dp(n);
            dp[0] = jobs[0][2];
            for (int i = 1; i < n; ++i) {
                int incl = jobs[i][2];
                int l = binarySearch(jobs, i);
                if (l != -1) incl += dp[l];
                dp[i] = max(dp[i - 1], incl);
            }
            return dp[n - 1];
        }
        
        int binarySearch(vector<vector<int>>& jobs, int index) {
            int left = 0, right = index - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (jobs[mid][1] <= jobs[index][0]) {
                    if (jobs[mid + 1][1] <= jobs[index][0]) left = mid + 1;
                    else return mid;
                } else {
                    right = mid - 1;
                }
            }
            return -1;
        }
    };
    