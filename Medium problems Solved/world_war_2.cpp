/*
Word Break II (all sentences) — memoized DFS

Problem: Given a string s and a dictionary of words wordDict, return all possible sentences where spaces are inserted to form dictionary words. Medium-hard; use memoization
*/

// word_break_ii.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Word Break II: return all possible sentences formed by words from dict.
  - Uses memoized recursion (DP).
  - Careful about performance; we memoize results for each start index.
*/

vector<string> wordBreakHelper(const string &s, int start, const unordered_set<string> &dict,
    vector<int> &maxlen, unordered_map<int, vector<string>> &memo) {

    if (start == (int)s.size()) return {""}; // one valid decomposition (empty)

    if (memo.count(start)) return memo[start];

    vector<string> res;
    int maxWordLen = maxlen[0];
    for (int len = 1; len <= maxWordLen && start + len <= (int)s.size(); ++len) {
        string word = s.substr(start, len);
        if (dict.count(word)) {
            vector<string> suffixes = wordBreakHelper(s, start + len, dict, maxlen, memo);
            for (const string &suf : suffixes) {
                if (suf.empty()) res.push_back(word);
                else res.push_back(word + " " + suf);
            }
        }
    }
    memo[start] = res;
    return res;
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int maxLen = 0;
    for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());
    vector<int> maxlen = {maxLen};
    unordered_map<int, vector<string>> memo;
    return wordBreakHelper(s, 0, dict, maxlen, memo);
}

// Example driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "catsanddog";
    vector<string> dict = {"cat","cats","and","sand","dog"};
    auto res = wordBreak(s, dict);
    cout << "Possible sentences:\n";
    for (auto &r : res) cout << r << '\n';
    return 0;
}
