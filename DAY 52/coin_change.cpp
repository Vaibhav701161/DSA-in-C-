/*
 * DAY 52: Coin Change (Minimum Coins)
 *
 * Problem Statement:
 * Given an array of coin denominations and an amount, return the minimum
 * number of coins needed to make up that amount. Return -1 if not possible.
 *
 * Approach: Bottom-up DP. dp[i] = min coins to make amount i.
 * For each amount, try all coin denominations.
 *
 * Time Complexity: O(amount * n)
 * Space Complexity: O(amount)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 5, 6, 9};
    int amount = 11;
    cout << "Min coins for " << amount << ": " << coinChange(coins, amount) << endl; // 2
    return 0;
}
