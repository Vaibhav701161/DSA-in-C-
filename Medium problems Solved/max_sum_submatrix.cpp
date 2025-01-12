// 34_max_sum_submatrix_k.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Use 2D prefix sums to query any submatrix in O(1).
  Then iterate top-left corners for k x k.
  Time: O(m*n)
*/

long long maxSumSubmatrixK(const vector<vector<int>>& mat, int k) {
    int m = mat.size();
    if (m == 0) return 0;
    int n = mat[0].size();
    vector<vector<long long>> pref(m+1, vector<long long>(n+1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

    long long best = LLONG_MIN;
    for (int i = k; i <= m; ++i) {
        for (int j = k; j <= n; ++j) {
            long long sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k];
            best = max(best, sum);
        }
    }
    return best;
}

int main() {
    vector<vector<int>> mat = {
        {1,2,0,3},
        {4,5,6,1},
        {2,1,4,0},
        {3,2,7,5}
    };
    int k = 2;
    cout << "Max sum " << k << "x" << k << " submatrix: " << maxSumSubmatrixK(mat, k) << '\n';

    // random small test
    mt19937 rng(42);
    int m=5,n=6; k=3;
    vector<vector<int>> rmat(m, vector<int>(n));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) rmat[i][j] = (int)(rng()%10)-2;
    cout << "Random matrix max 3x3 sum: " << maxSumSubmatrixK(rmat, 3) << '\n';
    return 0;
}
