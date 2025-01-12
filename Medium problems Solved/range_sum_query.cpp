// 31_segment_tree_range_sum.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Segment Tree for point update and range sum query.
  - Build: O(n)
  - Query: O(log n)
  - Update: O(log n)
*/

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(const vector<long long>& a) {
        n = a.size();
        tree.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node<<1, l, mid, a);
        build(node<<1|1, mid+1, r, a);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    void pointUpdate(int idx, long long val) { pointUpdate(1, 0, n-1, idx, val); }

    void pointUpdate(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) pointUpdate(node<<1, l, mid, idx, val);
        else pointUpdate(node<<1|1, mid+1, r, idx, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }

    long long rangeSum(int L, int R) { return rangeSum(1, 0, n-1, L, R); }

    long long rangeSum(int node, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return tree[node];
        int mid = (l + r) >> 1;
        return rangeSum(node<<1, l, mid, L, R) + rangeSum(node<<1|1, mid+1, r, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> arr = {5, 2, 6, 3, 1, 4, 7, 9};
    SegmentTree st(arr);

    cout << "Initial sum [0,7]: " << st.rangeSum(0,7) << '\n';
    cout << "Sum [2,5]: " << st.rangeSum(2,5) << '\n';

    cout << "Update index 3 -> 10\n";
    st.pointUpdate(3, 10);
    cout << "Sum [2,5] after update: " << st.rangeSum(2,5) << '\n';
    cout << "Sum [0,7] after update: " << st.rangeSum(0,7) << '\n';

    // Stress small tests
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < 5; ++i) {
        int idx = rng() % arr.size();
        long long val = (rng() % 20);
        st.pointUpdate(idx, val);
        cout << "After random update idx=" << idx << " val=" << val << " sum[0,7]=" << st.rangeSum(0,7) << '\n';
    }
    return 0;
}
