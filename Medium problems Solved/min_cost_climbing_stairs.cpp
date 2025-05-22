#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum Cost: " << sol.minCostClimbingStairs(cost);
    return 0;
}
