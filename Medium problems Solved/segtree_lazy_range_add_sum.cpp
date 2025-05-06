// segtree_lazy_range_add_sum.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Segment tree with:
   - build from array
   - rangeAdd(L,R,val)
   - rangeSum(L,R)
  0-indexed interface internally uses node intervals.
*/

struct SegTree {
    int n;
    vector<long long> tree, lazy;
    SegTree(const vector<long long>& a) {
        n = a.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1,0,n-1,a);
    }
    void build(int node, int l, int r, const vector<long long>& a) {
        if (l == r) { tree[node] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(node<<1, l, mid, a);
        build(node<<1|1, mid+1, r, a);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (r - l + 1);
            if (l != r) {
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int node, int l, int r, int L, int R, long long val) {
        push(node, l, r);
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(node<<1, l, mid, L, R, val);
        update(node<<1|1, mid+1, r, L, R, val);
        tree[node] = tree[node<<1] + tree[node<<1|1];
    }
    long long query(int node, int l, int r, int L, int R) {
        if (r < L || R < l) return 0;
        push(node, l, r);
        if (L <= l && r <= R) return tree[node];
        int mid = (l + r) >> 1;
        return query(node<<1, l, mid, L, R) + query(node<<1|1, mid+1, r, L, R);
    }
    // convenience wrappers
    void rangeAdd(int L, int R, long long val) { update(1,0,n-1,L,R,val); }
    long long rangeSum(int L, int R) { return query(1,0,n-1,L,R); }
};

int main() {
    vector<long long> a = {1,2,3,4,5,6,7,8};
    SegTree st(a);
    cout << "Sum [0,7]: " << st.rangeSum(0,7) << '\n';
    st.rangeAdd(2,5,10); // add 10 to indices 2..5
    cout << "Sum [0,7] after add: " << st.rangeSum(0,7) << '\n';
    cout << "Sum [3,4]: " << st.rangeSum(3,4) << '\n';
    return 0;
}
