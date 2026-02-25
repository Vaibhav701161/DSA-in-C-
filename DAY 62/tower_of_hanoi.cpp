/*
 * DAY 62: Tower of Hanoi (Recursion)
 *
 * Problem Statement:
 * Solve the Tower of Hanoi problem: move n disks from source rod to destination
 * rod using an auxiliary rod, following rules:
 * 1. Only one disk can be moved at a time.
 * 2. A larger disk cannot be placed on top of a smaller disk.
 *
 * Approach: Recursive divide-and-conquer.
 * Move top n-1 disks to auxiliary, move nth disk to dest, move n-1 from aux to dest.
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) recursion stack
 */
#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    cout << "Tower of Hanoi with " << n << " disks:" << endl;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
