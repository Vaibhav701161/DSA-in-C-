/*
Coin Change 2 (number of combinations) — DP

Problem: Given amount and array of coin denominations, compute number of combinations (order doesn't matter). Use DP.
*/

// coin_change2.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Coin Change 2: count combinations to form amount using coins (unlimited supply).
  Classic 1D DP with coin-first loop to avoid permutations counting.
  Complexity: O(amount * n)
*/

long long change(int amount, const vector<int>& coins) {
    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
        for (int a = coin; a <= amount; ++a) {
            dp[a] += dp[a - coin];
        }
    }
    return dp[amount];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << "Combinations to make " << amount << ": " << change(amount, coins) << '\n';
    return 0;
}
