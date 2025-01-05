/*
Merge Intervals (with total covered length)

Problem: Given a list of intervals [l, r) or [l, r]
 (assume inclusive), merge overlapping intervals and 
 return the merged list and the total covered length.

*/

// merge_intervals.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Merge intervals and compute total covered length.
  Input: vector<pair<int,int>> intervals (inclusive [l,r]).
  Output: merged vector and total length.
  Time: O(n log n)
*/

vector<pair<int,int>> merge_intervals(vector<pair<int,int>> intervals) {
    vector<pair<int,int>> res;
    if (intervals.empty()) return res;
    sort(intervals.begin(), intervals.end());
    int curL = intervals[0].first, curR = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); ++i) {
        int L = intervals[i].first, R = intervals[i].second;
        if (L <= curR + 1) { // adjacent or overlapping
            curR = max(curR, R);
        } else {
            res.emplace_back(curL, curR);
            curL = L; curR = R;
        }
    }
    res.emplace_back(curL, curR);
    return res;
}

long long total_covered_length(const vector<pair<int,int>>& merged) {
    long long total = 0;
    for (auto &p : merged) {
        long long L = p.first;
        long long R = p.second;
        total += (R - L + 1); // inclusive
    }
    return total;
}

// Example usage
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,int>> intervals = {
        {1,3}, {2,4}, {6,8}, {9,10}, {8,9}, {12,12}
    };
    auto merged = merge_intervals(intervals);
    cout << "Merged intervals:\n";
    for (auto &p : merged) cout << "[" << p.first << "," << p.second << "]\n";
    cout << "Total covered length: " << total_covered_length(merged) << "\n";
    return 0;
}
