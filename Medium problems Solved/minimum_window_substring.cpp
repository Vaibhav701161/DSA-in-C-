// 33_min_window_substring.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Sliding window approach:
  - Expand right, include chars, check if window covers all needed chars.
  - Then shrink left to minimize window.
  Time: O(|s| + |t|)
*/

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int required = 0;
    for (int c = 0; c < 128; ++c) if (need[c] > 0) ++required;

    vector<int> window(128, 0);
    int formed = 0;
    int l = 0, r = 0;
    int minLen = INT_MAX, minL = 0;

    while (r < (int)s.size()) {
        char c = s[r++];
        window[c]++;
        if (need[c] > 0 && window[c] == need[c]) formed++;

        while (l < r && formed == required) {
            if (r - l < minLen) {
                minLen = r - l;
                minL = l;
            }
            char d = s[l++];
            window[d]--;
            if (need[d] > 0 && window[d] < need[d]) formed--;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minL, minLen);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << "minWindow: " << minWindow(s, t) << '\n';

    // additional tests
    cout << "minWindow(abcd, bc): " << minWindow("abcd", "bc") << '\n';
    cout << "minWindow(a, aa): " << (minWindow("a","aa").empty() ? "EMPTY" : "FOUND") << '\n';
    return 0;
}
