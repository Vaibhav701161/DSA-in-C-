// 32_subarray_product_less_k.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Two pointers sliding window for positive integers.
  Maintain product of window [l..r]. Move l when product >= k.
  Time: O(n)
*/

long long numSubarrayProductLessThanK(const vector<int>& nums, long long k) {
    if (k <= 1) return 0;
    long long prod = 1;
    int left = 0;
    long long ans = 0;
    for (int right = 0; right < (int)nums.size(); ++right) {
        prod *= nums[right];
        while (prod >= k && left <= right) {
            prod /= nums[left];
            ++left;
        }
        ans += (right - left + 1);
    }
    return ans;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    long long k = 100;
    cout << "Number of subarrays with product < " << k << " : " << numSubarrayProductLessThanK(nums, k) << '\n';

    // edge cases
    cout << "Edge: k=1 -> " << numSubarrayProductLessThanK({1,1,1}, 1) << '\n';

    // random tests
    mt19937 rng(123);
    for (int t = 0; t < 3; ++t) {
        int n = 6;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = rng()%9 + 1; // 1..9
        long long K = rng()%50 + 1;
        cout << "arr: ";
        for (int x: a) cout << x << ' ';
        cout << " K=" << K << " -> " << numSubarrayProductLessThanK(a, K) << '\n';
    }
    return 0;
}
