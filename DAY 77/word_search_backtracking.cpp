/*
 * DAY 77: Word Search (Backtracking)
 *
 * Problem Statement:
 * Given an m x n board of characters and a string word, return true if the word
 * exists in the grid. The word can be constructed from sequentially adjacent cells
 * (horizontally or vertically) and each cell can only be used once per path.
 *
 * Approach: DFS + backtracking from each cell. Mark cells as visited during search,
 * restore on backtrack.
 *
 * Time Complexity: O(m * n * 4^L) where L is word length
 * Space Complexity: O(L) recursion stack
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int idx, int r, int c) {
    if (idx == (int)word.size()) return true;
    int m = board.size(), n = board[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[idx]) return false;
    char temp = board[r][c];
    board[r][c] = '#'; // mark visited
    bool found = dfs(board, word, idx+1, r+1, c) || dfs(board, word, idx+1, r-1, c) ||
                 dfs(board, word, idx+1, r, c+1) || dfs(board, word, idx+1, r, c-1);
    board[r][c] = temp; // restore
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dfs(board, word, 0, i, j)) return true;
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << exist(board, "ABCCED") << endl; // 1
    cout << exist(board, "SEE")    << endl; // 1
    cout << exist(board, "ABCB")   << endl; // 0
    return 0;
}
