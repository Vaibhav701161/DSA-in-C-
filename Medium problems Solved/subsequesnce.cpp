// lis.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Longest Increasing Subsequence (LIS).
  Approach: patience sorting with binary search.
  Time: O(n log n)
*/

int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    for (int x : nums) {
        auto it = lower_bound(sub.begin(), sub.end(), x);
        if (it == sub.end()) sub.push_back(x);
        else *it = x;
    }
    return sub.size();
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Length of LIS: " << lengthOfLIS(nums) << '\n';
    return 0;
}
