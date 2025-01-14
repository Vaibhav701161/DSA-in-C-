// 37_sliding_window_median.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Maintain two multisets:
  - lowers (max-like): smaller half
  - uppers (min-like): larger half
  Keep sizes balanced so that median is accessible.
*/

class SlidingMedian {
    multiset<int> low, high;
    void balance() {
        while (low.size() > high.size() + 1) {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }
        while (high.size() > low.size()) {
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }
    }
public:
    void add(int x) {
        if (low.empty() || x <= *prev(low.end())) low.insert(x);
        else high.insert(x);
        balance();
    }
    void remove(int x) {
        auto it = low.find(x);
        if (it != low.end()) low.erase(it);
        else {
            it = high.find(x);
            if (it != high.end()) high.erase(it);
        }
        balance();
    }
    double median() {
        if (low.size() == high.size()) return ((*prev(low.end())) + *high.begin()) / 2.0;
        return *prev(low.end());
    }
};

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    SlidingMedian sm;
    for (int i = 0; i < (int)nums.size(); ++i) {
        sm.add(nums[i]);
        if (i >= k - 1) {
            res.push_back(sm.median());
            sm.remove(nums[i - k + 1]);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = medianSlidingWindow(nums, k);
    cout << "Medians: ";
    for (double d : res) cout << d << ' ';
    cout << '\n';
    return 0;
}
