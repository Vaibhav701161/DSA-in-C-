/*
Sliding Window Maximum (deque)

Problem: Given an array and window size k, return max for each sliding window. Time O(n).
*/

// sliding_window_max.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Sliding Window Maximum using a deque storing indices of candidates.
  Complexity: O(n)
*/

vector<int> sliding_window_max(const vector<int>& a, int k) {
    int n = (int)a.size();
    vector<int> res;
    if (n == 0 || k <= 0) return res;
    deque<int> dq; // store indices, front is max
    for (int i = 0; i < n; ++i) {
        // remove indices out of this window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // remove smaller values
        while (!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            res.push_back(a[dq.front()]);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = sliding_window_max(a, k);
    cout << "Sliding window max for k="<<k<<":\n";
    for (int x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}
