/*
 * DAY 75: Edit Distance (Dynamic Programming)
 *
 * Problem Statement:
 * Given two strings word1 and word2, return the minimum number of operations
 * (insert, delete, replace) to convert word1 to word2.
 *
 * Approach: Bottom-up DP. dp[i][j] = min operations to convert word1[0..i-1]
 * to word2[0..j-1].
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[m][n];
}

int main() {
    cout << ""horse" -> "ros": " << minDistance("horse", "ros")   << endl; // 3
    cout << ""intention" -> "execution": " << minDistance("intention", "execution") << endl; // 5
    return 0;
}
