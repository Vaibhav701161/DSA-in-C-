/*
 * DAY 68: Power of Two (Bit Manipulation)
 *
 * Problem Statement:
 * Given an integer n, determine if it is a power of two.
 * An integer is a power of two if there exists an integer x such that n == 2^x.
 *
 * Approach: A power of two has exactly one set bit.
 * n & (n - 1) removes the lowest set bit. If result is 0, n is a power of two.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

// Find next power of two >= n
int nextPowerOfTwo(int n) {
    if (n <= 0) return 1;
    n--;
    n |= n >> 1; n |= n >> 2; n |= n >> 4;
    n |= n >> 8; n |= n >> 16;
    return n + 1;
}

int main() {
    cout << isPowerOfTwo(1)  << endl; // 1
    cout << isPowerOfTwo(16) << endl; // 1
    cout << isPowerOfTwo(3)  << endl; // 0
    cout << "Next power of 2 >= 10: " << nextPowerOfTwo(10) << endl; // 16
    return 0;
}
