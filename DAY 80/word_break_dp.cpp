/*
 * DAY 80: Word Break (Dynamic Programming)
 *
 * Problem Statement:
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Approach: Bottom-up DP. dp[i] = true if s[0..i-1] can be segmented using wordDict.
 * For each position i, check all substrings ending at i: if dp[j] is true and
 * s[j..i-1] is in dict, then dp[i] = true.
 *
 * Time Complexity: O(n^2 * L) where L is max word length
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main() {
    vector<string> dict1 = {"leet", "code"};
    cout << wordBreak("leetcode", dict1) << endl; // 1

    vector<string> dict2 = {"apple", "pen"};
    cout << wordBreak("applepenapple", dict2) << endl; // 1

    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak("catsandog", dict3) << endl; // 0
    return 0;
}
