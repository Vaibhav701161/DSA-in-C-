#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    cout << (sol.wordBreak(s, dict) ? "Yes" : "No") << endl;
    return 0;
}
