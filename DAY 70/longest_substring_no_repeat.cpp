/*
 * DAY 70: Longest Substring Without Repeating Characters (Sliding Window)
 *
 * Problem Statement:
 * Given a string s, find the length of the longest substring without
 * repeating characters.
 *
 * Approach: Sliding window with a hashmap to store the last seen index of
 * each character. Move the left pointer past the duplicate when found.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(min(m, n)) where m is charset size
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left)
            left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb")    << endl; // 1
    cout << lengthOfLongestSubstring("pwwkew")   << endl; // 3
    return 0;
}
