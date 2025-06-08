class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n), indexes(n);
            iota(indexes.begin(), indexes.end(), 0);
            mergeSort(nums, indexes, res, 0, n - 1);
            return res;
        }
        
        void mergeSort(vector<int>& nums, vector<int>& indexes, vector<int>& res, int left, int right) {
            if (left >= right) return;
            int mid = left + (right - left) / 2;
            mergeSort(nums, indexes, res, left, mid);
            mergeSort(nums, indexes, res, mid + 1, right);
            merge(nums, indexes, res, left, mid, right);
        }
        
        void merge(vector<int>& nums, vector<int>& indexes, vector<int>& res, int left, int mid, int right) {
            vector<int> temp(right - left + 1);
            int i = left, j = mid + 1, k = 0, count = 0;
            while (i <= mid && j <= right) {
                if (nums[indexes[j]] < nums[indexes[i]]) {
                    temp[k++] = indexes[j++];
                    count++;
                } else {
                    res[indexes[i]] += count;
                    temp[k++] = indexes[i++];
                }
            }
            while (i <= mid) {
                res[indexes[i]] += count;
                temp[k++] = indexes[i++];
            }
            while (j <= right) {
                temp[k++] = indexes[j++];
            }
            for (int l = 0; l < temp.size(); ++l) {
                indexes[left + l] = temp[l];
            }
        }
    };
    