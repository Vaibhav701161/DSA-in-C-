#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int required = freq.size();
        int formed = 0;
        unordered_map<char, int> window;
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (freq.count(c) && window[c] == freq[c]) formed++;

            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if (freq.count(s[l]) && window[s[l]] < freq[s[l]]) formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;
    cout << "Minimum Window: " << sol.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}
