/*
 * DAY 79: Number of Islands (Graph DFS)
 *
 * Problem Statement:
 * Given an m x n 2D binary grid where '1' represents land and '0' represents water,
 * return the number of islands. An island is surrounded by water and is formed by
 * connecting adjacent lands horizontally or vertically.
 *
 * Approach: For each unvisited '1', perform DFS to mark all connected land as visited.
 * Count how many times we start a new DFS.
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int m = grid.size(), n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
    grid[r][c] = '0'; // sink island
    dfs(grid, r+1, c); dfs(grid, r-1, c);
    dfs(grid, r, c+1); dfs(grid, r, c-1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < (int)grid.size(); i++)
        for (int j = 0; j < (int)grid[0].size(); j++)
            if (grid[i][j] == '1') { dfs(grid, i, j); count++; }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Number of islands: " << numIslands(grid) << endl; // 1

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Number of islands: " << numIslands(grid2) << endl; // 3
    return 0;
}
