// palindromic_partitions.cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(const string& s, int idx, vector<string>& cur, vector<vector<string>>& res, vector<vector<bool>>& pal) {
    int n = s.size();
    if (idx == n) { res.push_back(cur); return; }
    for (int j = idx; j < n; ++j) {
        if (pal[idx][j]) {
            cur.push_back(s.substr(idx, j - idx + 1));
            dfs(s, j+1, cur, res, pal);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partitionPalindromes(const string& s) {
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    for (int i = n-1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            pal[i][j] = (s[i] == s[j]) && (j - i < 2 || pal[i+1][j-1]);
        }
    }
    vector<vector<string>> res;
    vector<string> cur;
    dfs(s, 0, cur, res, pal);
    return res;
}

int main() {
    string s = "aab";
    auto ans = partitionPalindromes(s);
    cout << "Palindrome partitions for '" << s << "':\n";
    for (auto &v : ans) {
        for (auto &t : v) cout << t << ' ';
        cout << '\n';
    }
    return 0;
}
