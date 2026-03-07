/*
 * DAY 72: Container With Most Water (Two Pointers)
 *
 * Problem Statement:
 * Given n vertical lines at positions 0 to n-1 with heights height[i],
 * find two lines that together with the x-axis form a container holding
 * the most water. Return the maximum amount of water a container can store.
 *
 * Approach: Two pointers from both ends. Move the pointer with smaller height
 * inward (the larger height is the limiting factor for width).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = (int)height.size() - 1;
    int maxWater = 0;
    while (left < right) {
        int water = min(height[left], height[right]) * (right - left);
        maxWater = max(maxWater, water);
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water: " << maxArea(height) << endl; // 49
    return 0;
}
