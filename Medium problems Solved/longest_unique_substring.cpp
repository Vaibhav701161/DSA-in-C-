// longest_unique_substring.cpp
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(const string& s) {
    vector<int> last(256, -1);
    int left = 0, best = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        left = max(left, last[s[i]] + 1);
        best = max(best, i - left + 1);
        last[s[i]] = i;
    }
    return best;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest unique substring length: " << lengthOfLongestSubstring(s) << '\n'; // 3
    cout << "For 'bbbbb' -> " << lengthOfLongestSubstring("bbbbb") << '\n'; //1
    cout << "For 'pwwkew' -> " << lengthOfLongestSubstring("pwwkew") << '\n'; //3
    return 0;
}
