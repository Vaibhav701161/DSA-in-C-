/*
 * DAY 66: Fractional Knapsack (Greedy)
 *
 * Problem Statement:
 * Given items with weights and values and a knapsack capacity W, maximize the
 * total value by taking fractions of items. Unlike 0/1 knapsack, items can be broken.
 *
 * Approach: Greedy. Sort items by value/weight ratio in descending order.
 * Take as much of the highest ratio item as possible, then next, and so on.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item { int weight, value; };

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });
    double totalValue = 0.0;
    int remaining = W;
    for (auto& item : items) {
        if (remaining <= 0) break;
        int take = min(item.weight, remaining);
        totalValue += (double)take * item.value / item.weight;
        remaining -= take;
    }
    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    cout << "Max value: " << fractionalKnapsack(W, items) << endl; // 240.0
    return 0;
}
