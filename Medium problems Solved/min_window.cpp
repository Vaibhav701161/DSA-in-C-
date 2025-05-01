#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char,int> need;
        for (char c : t) need[c]++;

        int left = 0, count = 0, minLen = INT_MAX, start = 0;
        unordered_map<char,int> window;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] <= need[c]) count++;

            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                window[s[left]]--;
                if (need.count(s[left]) && window[s[left]] < need[s[left]])
                    count--;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;
    return 0;
}
