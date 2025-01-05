/*
Number of Islands (DFS) with grid mutation + boundary check

Problem: Given 2D grid of '1' (land) and '0' (water), count islands. You may modify grid.
*/

// num_islands.cpp
#include <bits/stdc++.h>
using namespace std;

/*
  Number of Islands using DFS (iterative stack to avoid recursion depth).
  Time: O(m*n), Space: O(m*n) worst-case stack.
*/

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    int count = 0;
    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,1,-1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                // iterative DFS
                stack<pair<int,int>> st;
                st.push({i,j});
                grid[i][j] = '0'; // mark visited
                while (!st.empty()) {
                    auto [r,c] = st.top(); st.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k], nc = c + dc[k];
                        if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1') {
                            grid[nr][nc] = '0';
                            st.push({nr,nc});
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands: " << numIslands(grid) << '\n';
    return 0;
}
