/*
 * DAY 50: 0/1 Knapsack Problem
 *
 * Problem Statement:
 * Given n items, each with a weight and a value, and a knapsack of capacity W,
 * find the maximum value that can be obtained by including/excluding each item
 * (you cannot take a fraction of an item, take it or leave it).
 *
 * Approach: Bottom-up DP. dp[i][w] = max value using first i items with capacity w.
 *
 * Time Complexity: O(n * W)
 * Space Complexity: O(n * W)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values  = {1, 4, 5, 7};
    int W = 7, n = 4;
    cout << "Max value: " << knapsack(W, weights, values, n) << endl; // 9
    return 0;
}
