// 38_count_smaller_after_self.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Coordinate compression + BIT (Fenwick Tree).
  Iterate from right to left, query count of smaller numbers seen so far.
*/

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sum(int idx) {
        int r = 0;
        for (; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
};

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> vals = nums;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto getIdx = [&](int x){
        return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1; // 1-based
    };
    Fenwick fw(vals.size());
    vector<int> res(n);
    for (int i = n-1; i >= 0; --i) {
        int idx = getIdx(nums[i]);
        res[i] = fw.sum(idx - 1);
        fw.add(idx, 1);
    }
    return res;
}

int main() {
    vector<int> nums = {5,2,6,1};
    auto ans = countSmaller(nums);
    cout << "Counts smaller after self: ";
    for (int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
