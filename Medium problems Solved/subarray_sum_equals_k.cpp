#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix;
        prefix[0] = 1;
        int count = 0, sum = 0;

        for (int x : nums) {
            sum += x;
            if (prefix.count(sum - k)) count += prefix[sum - k];
            prefix[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Number of subarrays with sum k: " << sol.subarraySum(nums, k);
    return 0;
}
