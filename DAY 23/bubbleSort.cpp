// optimized bubble sort in c++ :

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Inner loop for adjacent comparisons
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                // Swap without using built-in functions
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!swapped)
            break;
    }

    return nums;
}

int main() {
    vector<int> nums = {5, 1, 1, 2, 0, 0};

    vector<int> sorted = sortArray(nums);

    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}
