/*
 * DAY 65: Activity Selection Problem (Greedy)
 *
 * Problem Statement:
 * Given n activities with start and finish times, select the maximum number
 * of non-overlapping activities that a single person can perform.
 *
 * Approach: Greedy algorithm. Sort activities by finish time. Always select
 * the activity that finishes earliest and doesn't conflict with previous.
 *
 * Time Complexity: O(n log n) for sorting
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<pair<int,int>>& activities) {
    sort(activities.begin(), activities.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second < b.second;
         });
    int count = 1;
    int lastEnd = activities[0].second;
    cout << "Selected: [" << activities[0].first << "," << activities[0].second << "] ";
    for (int i = 1; i < (int)activities.size(); i++) {
        if (activities[i].first >= lastEnd) {
            count++;
            lastEnd = activities[i].second;
            cout << "[" << activities[i].first << "," << activities[i].second << "] ";
        }
    }
    cout << endl;
    return count;
}

int main() {
    vector<pair<int,int>> activities = {{1,4},{3,5},{0,6},{5,7},{3,9},{5,9},{6,10},{8,11},{8,12},{2,14},{12,16}};
    cout << "Max activities: " << activitySelection(activities) << endl;
    return 0;
}
