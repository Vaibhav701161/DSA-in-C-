#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(mat);
    cout << "Rotated matrix:\n";
    for (auto &row : mat) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}
