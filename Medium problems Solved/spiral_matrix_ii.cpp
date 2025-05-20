#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int num = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) mat[top][i] = num++;
            top++;
            for (int i = top; i <= bottom; i++) mat[i][right] = num++;
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) mat[bottom][i] = num++;
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) mat[i][left] = num++;
                left++;
            }
        }
        return mat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ans = sol.generateMatrix(3);
    for (auto &row : ans) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
