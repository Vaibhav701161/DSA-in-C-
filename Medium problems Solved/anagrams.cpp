/*
Find All Anagrams in a String (sliding window + freq array)

Problem: Given a string s and p, find all start indices of p's anagrams in s.
*/

// find_anagrams.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Find all anagram indices:
  - Use sliding window with freq counts (size 26).
  - Time: O(|s| + |p|)
*/

vector<int> findAnagrams(string s, string p) {
    int n = s.size(), m = p.size();
    vector<int> res;
    if (m > n) return res;

    vector<int> cntP(26,0), cntS(26,0);
    for (char c : p) cntP[c-'a']++;
    for (int i = 0; i < m; i++) cntS[s[i]-'a']++;

    if (cntS == cntP) res.push_back(0);

    for (int i = m; i < n; i++) {
        cntS[s[i]-'a']++;
        cntS[s[i-m]-'a']--;
        if (cntS == cntP) res.push_back(i-m+1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "cbaebabacd";
    string p = "abc";
    auto res = findAnagrams(s, p);
    cout << "Anagram indices: ";
    for (int i : res) cout << i << ' ';
    cout << '\n';
    return 0;
}
