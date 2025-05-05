// fenwick_range_update_point_query.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Fenwick / BIT supporting:
    - add(l, r, val): add val to every element in [l, r] (1-based indices)
    - pointQuery(idx): get value at idx
  Implementation trick: use single BIT where range add is done by point adds on BIT with prefix-sum interpretation.
*/

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0): n(n), bit(n+1,0) {}
    void addPoint(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    long long sumPrefix(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
    // range add: add val to [l,r]
    void addRange(int l, int r, long long val) {
        addPoint(l, val);
        addPoint(r+1, -val);
    }
    // point query: value at idx
    long long pointQuery(int idx) { return sumPrefix(idx); }
};

int main() {
    int n = 10;
    Fenwick fw(n);
    // initial zeros
    fw.addRange(2, 5, 10); // add 10 to indices 2..5
    fw.addRange(4, 9, 3);  // add 3 to indices 4..9
    cout << "Values at indices 1..10:\n";
    for (int i = 1; i <= n; ++i) {
        cout << fw.pointQuery(i) << (i==n?'\n':' ');
    }
    // expected:
    // idx1=0, 2=10,3=10,4=13,5=13,6=3,7=3,8=3,9=3,10=0
    return 0;
}
