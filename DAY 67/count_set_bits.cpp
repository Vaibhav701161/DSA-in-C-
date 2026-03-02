/*
 * DAY 67: Count Set Bits (Bit Manipulation)
 *
 * Problem Statement:
 * Given a non-negative integer n, return the number of '1' bits (set bits)
 * in its binary representation. Also known as Hamming Weight.
 *
 * Approach 1: Brian Kernighan's Algorithm - n & (n-1) clears the lowest set bit.
 * Approach 2: Built-in __builtin_popcount.
 *
 * Time Complexity: O(number of set bits)
 * Space Complexity: O(1)
 */
#include <iostream>
using namespace std;

// Brian Kernighan's Algorithm
int hammingWeight(unsigned int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // clears lowest set bit
        count++;
    }
    return count;
}

// Count set bits for range [1, n]
int countBitsUpTo(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += hammingWeight(i);
    return total;
}

int main() {
    cout << "Set bits in 11 (1011): " << hammingWeight(11) << endl; // 3
    cout << "Set bits in 128: "       << hammingWeight(128) << endl; // 1
    cout << "Total set bits 1 to 5: " << countBitsUpTo(5) << endl;   // 7
    return 0;
}
