// longest_consecutive_sequence.cpp
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : nums) {
        if (!s.count(x-1)) { // x is start of sequence
            int cur = x;
            int len = 1;
            while (s.count(cur+1)) { cur++; len++; }
            best = max(best, len);
        }
    }
    return best;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    cout << "Longest consecutive length: " << longestConsecutive(nums) << '\n'; // 4 (1,2,3,4)
    return 0;
}
