/*
 * DAY 54: Insertion Sort
 *
 * Problem Statement:
 * Sort an array using the insertion sort algorithm.
 * In each iteration, take the current element and insert it into the correct
 * position within the already-sorted portion of the array.
 *
 * Time Complexity: O(n^2) worst/avg case, O(n) best case (already sorted)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
