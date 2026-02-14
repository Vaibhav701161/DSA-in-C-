/*
 * DAY 51: Longest Common Subsequence (LCS)
 *
 * Problem Statement:
 * Given two strings text1 and text2, return the length of their longest
 * common subsequence. A subsequence is derived by deleting some characters
 * without changing the relative order of remaining characters.
 *
 * Approach: Bottom-up DP. dp[i][j] = LCS of text1[0..i-1] and text2[0..j-1].
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string& text1, string& text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "abcde", text2 = "ace";
    cout << "LCS length: " << lcs(text1, text2) << endl; // 3

    string a = "abc", b = "abc";
    cout << "LCS length: " << lcs(a, b) << endl; // 3
    return 0;
}
