/*
Longest Increasing Subsequence (LIS) — tails + reconstruct

Problem: Given an array of integers, find the length of the 
longest strictly increasing subsequence and also return one 
such subsequence. Complexity target: O(n log n).
*/

// lis_reconstruct.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Longest Increasing Subsequence (LIS) with reconstruction.
  - Uses patience sorting (tails) + parent pointers.
  - Time: O(n log n), Space: O(n)
*/

vector<int> longest_increasing_subsequence(const vector<int>& a) {
    int n = (int)a.size();
    if (n == 0) return {};

    // tails stores the ending value of an increasing subsequence of length i+1 at tails[i]
    vector<int> tails;
    // idx[i] stores index in a of the element that forms tails[i]
    vector<int> idx;
    // parent[i] stores the previous index in a of the subsequence ending at i
    vector<int> parent(n, -1);

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        // lower_bound for strictly increasing -> use lower_bound
        auto it = lower_bound(tails.begin(), tails.end(), x);
        int pos = (int)(it - tails.begin());

        if (it == tails.end()) {
            tails.push_back(x);
            idx.push_back(i);
        } else {
            *it = x;
            idx[pos] = i;
        }

        if (pos > 0) parent[i] = idx[pos - 1];
    }

    // reconstruct using last index
    int len = (int)tails.size();
    vector<int> seq(len);
    int cur = idx[len - 1];
    for (int i = len - 1; i >= 0; --i) {
        seq[i] = a[cur];
        cur = parent[cur];
        if (cur == -1 && i > 0) {
            // safety but should not happen
            fill(seq.begin(), seq.begin() + i, -1);
            break;
        }
    }
    return seq;
}

// Example driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a = {3, 4, -1, 0, 6, 2, 3};
    auto seq = longest_increasing_subsequence(a);
    cout << "LIS length: " << seq.size() << '\n';
    cout << "LIS sequence: ";
    for (int x : seq) cout << x << ' ';
    cout << '\n';
    return 0;
}
