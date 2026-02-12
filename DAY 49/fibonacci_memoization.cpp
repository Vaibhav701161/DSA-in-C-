/*
 * DAY 49: Fibonacci with Memoization (Top-Down DP)
 *
 * Problem Statement:
 * Compute the nth Fibonacci number using dynamic programming with memoization.
 * F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2) for n>=2.
 *
 * Approach: Top-down recursion + memoization cache to avoid re-computing.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10;
    memo.assign(n + 1, -1);
    cout << "Fibonacci(" << n << ") = " << fib(n) << endl; // 55

    // Also print first 10 Fibonacci numbers
    cout << "First 11 Fibonacci: ";
    memo.assign(n + 1, -1);
    for (int i = 0; i <= n; i++) cout << fib(i) << " ";
    cout << endl;
    return 0;
}
