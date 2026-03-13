/*
 * DAY 78: Merge Intervals (Greedy / Sorting)
 *
 * Problem Statement:
 * Given an array of intervals where intervals[i] = [start, end], merge all
 * overlapping intervals and return an array of the non-overlapping intervals.
 *
 * Approach: Sort by start time. Iterate through and merge if current interval
 * overlaps with the last one in result (start <= previous end).
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < (int)intervals.size(); i++) {
        if (intervals[i][0] <= merged.back()[1])
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        else
            merged.push_back(intervals[i]);
    }
    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto res = merge(intervals);
    cout << "Merged intervals:" << endl;
    for (auto& iv : res)
        cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;
    return 0;
}
